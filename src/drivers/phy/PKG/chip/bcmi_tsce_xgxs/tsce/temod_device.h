/*----------------------------------------------------------------------
 * $Id: temod_device.h,
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom/Broadcom-Compute-Connectivity-Software-robo2-rsdk/master/Legal/LICENSE file.
 *
 * $Copyright: (c) 2020 Broadcom Inc.
 * All Rights Reserved$
 *
 *  Broadcom Inc.
 *  Proprietary and Confidential information
 *  All rights reserved
 *  This source file is the property of Broadcom Inc. and
 *  may not be copied or distributed in any isomorphic form without the
 *  prior written consent of Broadcom Inc.
 *----------------------------------------------------------------------
 *  Description: define enumerators  
 *----------------------------------------------------------------------*/
/*
 * $Id: $ 
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom/Broadcom-Compute-Connectivity-Software-robo2-rsdk/master/Legal/LICENSE file.
 *
 * $Copyright:
 * All Rights Reserved.$
 */
#ifndef _TEMOD_DEVICE_H_
#define _TEMOD_DEVICE_H_

/* debug mask are used by TEMOD */
#define TEMOD_DBG_CL72       (1L << 16) /* CL72 */
#define TEMOD_DBG_FWL        (1L << 15) /* FW loading debug */
#define TEMOD_DBG_REGACC     (1L << 14) /* Print all register accesses */
#define TEMOD_DBG_CFG        (1L << 13) /* CFG */
#define TEMOD_DBG_LNK        (1L << 12) /* Link */
#define TEMOD_DBG_SPD        (1L << 11) /* Speed */
#define TEMOD_DBG_AN         (1L << 10) /* AN */
#define TEMOD_DBG_LPK        (1L << 9) /* Local or remote loopback */
#define TEMOD_DBG_PMD        (1L << 8) /* PMD */
#define TEMOD_DBG_SCN        (1L << 7) /* Link scan*/
#define TEMOD_DBG_TST        (1L << 6) /* Testing and PRBS */
#define TEMOD_DBG_TOP        (1L << 5) /* Lane swap and polarity */
#define TEMOD_DBG_MEM        (1L << 4) /* allocation/object */

#define TEMOD_DBG_FUNCVALOUT (1L << 2) /* All values returned by Tier1*/
#define TEMOD_DBG_FUNCVALIN  (1L << 1) /* All values pumped into Tier1*/
#define TEMOD_DBG_FUNC       (1L << 0) /* Every time we enter a  Tier1*/

typedef struct temod_device_aux_modes_s {
    uint32_t core_id ; 
    uint16_t st_current_entry ;
    uint16_t st_hcd[4] ;
    uint16_t st_pll_div[4] ;
    uint16_t st_os[4] ;

    uint16_t hto_enable[4]  ;
    uint16_t hto_pll_div[4] ;
    uint16_t hto_os[4] ;
} temod_device_aux_modes_t ;

#define TEMOD_CL72_CONTROL_NO_TRIGER  0x80
#define TEMOD_CL72_CONTROL_MASK       0x0f

#endif
