/*
 * $Id$
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom/Broadcom-Compute-Connectivity-Software-robo2-rsdk/master/Legal/LICENSE file.
 *
 * $Copyright: Copyright 2020 Broadcom Inc.
 * This program is the proprietary software of Broadcom Inc.
 * and/or its licensors, and may only be used, duplicated, modified
 * or distributed pursuant to the terms and conditions of a separate,
 * written license agreement executed between you and Broadcom
 * (an "Authorized License").  Except as set forth in an Authorized
 * License, Broadcom grants no license (express or implied), right
 * to use, or waiver of any kind with respect to the Software, and
 * Broadcom expressly reserves all rights in and to the Software
 * and all intellectual property rights therein.  IF YOU HAVE
 * NO AUTHORIZED LICENSE, THEN YOU HAVE NO RIGHT TO USE THIS SOFTWARE
 * IN ANY WAY, AND SHOULD IMMEDIATELY NOTIFY BROADCOM AND DISCONTINUE
 * ALL USE OF THE SOFTWARE.  
 *  
 * Except as expressly set forth in the Authorized License,
 *  
 * 1.     This program, including its structure, sequence and organization,
 * constitutes the valuable trade secrets of Broadcom, and you shall use
 * all reasonable efforts to protect the confidentiality thereof,
 * and to use this information only in connection with your use of
 * Broadcom integrated circuit products.
 *  
 * 2.     TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS
 * PROVIDED "AS IS" AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES,
 * REPRESENTATIONS OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY,
 * OR OTHERWISE, WITH RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY
 * DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY,
 * NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES,
 * ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR
 * CORRESPONDENCE TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING
 * OUT OF USE OR PERFORMANCE OF THE SOFTWARE.
 * 
 * 3.     TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL
 * BROADCOM OR ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL,
 * INCIDENTAL, SPECIAL, INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER
 * ARISING OUT OF OR IN ANY WAY RELATING TO YOUR USE OF OR INABILITY
 * TO USE THE SOFTWARE EVEN IF BROADCOM HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGES; OR (ii) ANY AMOUNT IN EXCESS OF
 * THE AMOUNT ACTUALLY PAID FOR THE SOFTWARE ITSELF OR USD 1.00,
 * WHICHEVER IS GREATER. THESE LIMITATIONS SHALL APPLY NOTWITHSTANDING
 * ANY FAILURE OF ESSENTIAL PURPOSE OF ANY LIMITED REMEDY.$
 *
 * Generic PHY driver.
 *
 */

#include <phy/phy.h>
#include <phy/ge_phy.h>

/*
 * Function:    
 *      ge_phy_duplex_get
 * Purpose:     
 *      Get the current operating duplex mode. If autoneg is enabled, 
 *      then operating mode is returned, otherwise forced mode is returned.
 * Parameters:
 *      pc - PHY control structure
 *      duplex - (OUT) non-zero indicates full duplex, zero indicates half
 * Returns:     
 *      CDK_E_xxx
 * Notes: 
 *      Returns a half duplex if autonegotiation is not complete.
 */
int
ge_phy_duplex_get(phy_ctrl_t *pc, int *duplex)
{
    int ioerr = 0;
    uint32_t ctrl, stat;

    PHY_CTRL_CHECK(pc);

    ioerr += PHY_BUS_READ(pc, MII_CTRL_REG, &ctrl);
    ioerr += PHY_BUS_READ(pc, MII_STAT_REG, &stat);

    if (ioerr) {
        return CDK_E_IO;
    }

    if (ctrl & MII_CTRL_AE) {
        /* Auto-negotiation enabled */
        if (!(stat & MII_STAT_AN_DONE)) {
            /* Auto-neg NOT complete */
            *duplex = 0;
            return CDK_E_NONE;
        }
        return ge_phy_autoneg_gcd(pc, NULL, duplex);
    } else {
        /* Auto-negotiation disabled */
        *duplex = (ctrl & MII_CTRL_FD) ? 1 : 0;
    }

    return CDK_E_NONE;
}

