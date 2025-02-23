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
 * This function accepts a 32-bit generic PHY register address
 * and performs a register write accoding to the access method
 * contained in the PHY register address.
 */

#include <phy/phy_reg.h>
#include <phy/phy_brcm_shadow.h>
#include <phy/phy_brcm_1000x.h>
#include <phy/phy_xgs_iblk.h>
#include <phy/phy_xaui_iblk.h>
#include <phy/phy_aer_iblk.h>
#include <phy/phy_brcm_xe.h>
#include <phy/phy_tsc_iblk.h>
#include <phy/phy_brcm_rdb.h>

int
phy_reg_write(phy_ctrl_t *pc, uint32_t addr, uint32_t data)
{
    switch (PHY_REG_ACCESS_METHOD(addr)) {
    case PHY_REG_ACC_RAW:
        return PHY_BUS_WRITE(pc, addr, data);
    case PHY_REG_ACC_BRCM_SHADOW:
        return phy_brcm_shadow_write(pc, addr, data);
    case PHY_REG_ACC_BRCM_1000X:
        return phy_brcm_1000x_write(pc, addr, data);
    case PHY_REG_ACC_XGS_IBLK:
        return phy_xgs_iblk_write(pc, addr, data);
    case PHY_REG_ACC_XAUI_IBLK:
        return phy_xaui_iblk_write(pc, addr, data);
    case PHY_REG_ACC_AER_IBLK:
        return phy_aer_iblk_write(pc, addr, data);
    case PHY_REG_ACC_BRCM_XE:
        return phy_brcm_xe_write(pc, addr, data);
    case PHY_REG_ACC_TSC_IBLK:
        return phy_tsc_iblk_write(pc, addr, data);
    case PHY_REG_ACC_BRCM_RDB:
        return phy_brcm_rdb_write(pc, addr, data);
    default:
        break;
    }

    /* Unknown access method */
    return -1;
}
