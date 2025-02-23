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
 */

#ifndef __PHY_TSC_IBLK_H__
#define __PHY_TSC_IBLK_H__

#include <phy/phy_reg.h>

/*
 * Always set bit 15 in block address register 0x1f to make the
 * register contents more similar to the clause 45 address.
 */
#ifndef PHY_TSC_IBLK_DBG_BIT15
#define PHY_TSC_IBLK_DBG_BIT15  1
#endif

/* Special lane values for broadcast and dual-lane multicast */
#define PHY_TSC_IBLK_MCAST01    4
#define PHY_TSC_IBLK_MCAST23    5
#define PHY_TSC_IBLK_BCAST      6

/* Host/uC mailbox control */
#define TSC_UC_PROXY_WAIT_TIME  600000
#define TSC_UC_SYNC_CMD_REQ     (1L << 0)
#define TSC_UC_SYNC_CMD_RDY     (1L << 1)
#define TSC_UC_SYNC_CMD_BUSY    (1L << 2)
#define TSC_UC_SYNC_CMD_RAM     (1L << 3)
#define TSC_UC_SYNC_CMD_WR      (1L << 4)
#define TSC_UC_SYNC_CMD_DONE    (1L << 15)


extern int
phy_tsc_iblk_mdio_read(phy_ctrl_t *pc, uint32_t addr, uint32_t *data);

extern int
phy_tsc_iblk_mdio_write(phy_ctrl_t *pc, uint32_t addr, uint32_t data);

extern int
phy_tsc_iblk_proxy_read(phy_ctrl_t *pc, uint32_t addr, uint32_t *data);

extern int
phy_tsc_iblk_proxy_write(phy_ctrl_t *pc, uint32_t addr, uint32_t data);

extern int
phy_tsc_iblk_read(phy_ctrl_t *pc, uint32_t addr, uint32_t *data);

extern int
phy_tsc_iblk_write(phy_ctrl_t *pc, uint32_t addr, uint32_t data);

#endif /* __PHY_TSC_IBLK_H__ */
