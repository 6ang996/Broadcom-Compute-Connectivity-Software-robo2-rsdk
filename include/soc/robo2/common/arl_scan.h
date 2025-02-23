/*
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated from the registers file.
 * Edits to this file will be lost when it is regenerated.
 *
 * $Id: $
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom/Broadcom-Compute-Connectivity-Software-robo2-rsdk/master/Legal/LICENSE file.
 *
 * $Copyright: (c) 2020 Broadcom Inc.
 * All Rights Reserved.$
 *
 * File:	arl_scan.h
 * Purpose:	Robo2 ARL Scanner Access Routines
 */

#ifndef _SOC_ROBO2_ARL_SCAN_H
#define _SOC_ROBO2_ARL_SCAN_H

#include <sal_types.h>

/*
 * Scanner operations
 */
typedef enum {
    SCANNER_MIN_CMD = 0,
    SCANNER_DELETE  = 1, /* Delete entries matching the key & mask */
    SCANNER_COUNT   = 2, /* Count entries matching the key and mask */
    SCANNER_READ    = 3, /* Search operation, Return first match */
    SCANNER_RESUME  = 4, /* Search operation, continue to next match */
    SCANNER_INSERT  = 5, /* Queue record for insertion */
    SCANNER_MAX_CMD,
} soc_robo2_arl_scanner_op_t;

#define SCANNER_STATUS_READY         0x80000000
#define SCANNER_STATUS_SEARCH_VALID  0x40000000
#define SCANNER_STATUS_INSERT_VALID  0x20000000
/*#define SCANNER_STATUS_COUNT_VALID   0x10000000*/

#define SCANNER_STATUS_VALID_MASK    0xF0000000
#define SCANNER_STATUS_RESULT_MASK   0x00007FFF

/**
 * ARL SCANNER ENTRY:
 * 0
 */
typedef struct soc_robo2_arl_scan_entry_s {
    /**
     * Indicates the type of the dst field.
     * 3 - DST_IS_DPG
     *     Indicates that the dst field is a Destination Port Group.
     * 0 - DST_IS_INVALID
     *     If this is returned on a DMAC lookup of the ARLFM then the
     *     causal frame will be dropped.
     * 2 - DST_IS_N
     *     Indicates that the dst field is the N field of an N-type LI.
     * 1 - DST_IS_MULTICAST
     *     Indicates that the dst field is a Destination Group Identifier.
     */
    uint8   dst_type_key;

    uint8   dst_type_mask;

    /**
     * Destination field. This indicates how to forward a frame. Its precise
     * semantic is determined by the dst_type field.
     */
    uint16  dst_key;

    uint16  dst_mask;

    /**
     * The Filter Identifier. Used to segregate entries in the ARL.
     */
    uint16  fid_key;

    uint16  fid_mask;

    /**
     * Indicates how to forward a frame.
     * 2 - COPY_TO_CPU
     *     Standard forwarding and unconditionally generate an additional
     *     copy for the Control Plane.
     * 1 - DENY_SMAC
     *     If this is returned as the result of an SMAC lookup then the
     *     frame will be discarded. Note that denying DMACs can be accomplished
     *     by setting the dst_type field to DST_IS_INVALID in ARLFM. If this is
     *     returned as the result of a DMAC lookup then the frame will be
     *     forwarded normally.
     * 3 - DENY_SMAC_AND_COPY_TO_CPU
     *     Deny and unconditionally generate an additional
     *     copy for the Control Plane.
     * 0 - PERMIT
     *     Standard forwarding. Allow frame to be forwarded normally.
     */
    uint8   fwd_ctrl_key;

    uint8   fwd_ctrl_mask;

    /**
     * Set by hardware when a lookup hits this entry. Cleared periodically
     * by the aging process. If the aging process encounters a valid
     * non-static entry that has the hit bit clear then it marks the entry
     * as invalid (aging it out).
     */
    uint8   hit_key;

    uint8   hit_mask;

    /**
     * Bits 47 thru 32 of the 48b Ethernet MAC address.
     */
    uint16  mac_hi_key;

    uint16  mac_hi_mask;

    /**
     * Bits 31 thru 0 of the 48b Ethernet MAC address.
     */
    uint32  mac_lo_key;

    uint32  mac_lo_mask;

    /**
     * Indicates actions to take when station movement is detected.
     * When this field is UPDATE then the update actions specified by the
     * PGLCT have priority. When this field is UPDATE_AND_COPY, COPY or
     * DISABLE_UPDATE then the PGLCT update actions are ignored.
     * 2 - COPY
     *     When movement is detected dont update the ARL entry but do copy
     *     the frame to the CPU.
     * 1 - UPDATE_AND_COPY
     *     When movement is detected update the ARL entry and copy to the CPU.
     * 0 - UPDATE
     *     When station movement is detected update the ARL entrys associated
     *     destination data.
     * 3 - DISABLE_UPDATE
     *     Do not allow ARL entry update.
     */
    uint8   upd_ctrl_key;

    uint8   upd_ctrl_mask;

    /**
     * Indicates the validity of an entry.
     * 2 - VALID
     *     Indicates that this is a valid entry.
     * 3 - STATIC
     *     Indicates that the entry belongs wholly to software, hardware
     *     may not age it. Hardware updates the associated data
     *     when a station move is detected if and only if upd_ctrl is UPDATE
     *     or UPDATE_AND_COPY.
     * 1 - PENDING
     *     Indicates that the hash table entry has been learned by hardware
     *     but not sanctioned by software, eligible for aging. Counts as a miss
     *     for forwarding purposes but suppresses continued notification of
     *     software.
     * 0 - EMPTY
     *     Indicates that the hash table entry is empty.
     */
    uint8   valid_key;

    uint8   valid_mask;

} soc_robo2_arl_scan_entry_t;

/* Declaration for arl scan functions */
extern int soc_robo2_arl_count_entry(int unit,
        soc_robo2_arl_scan_entry_t *entry, uint32 *count);
extern int soc_robo2_arl_delete_entry(int unit,
        soc_robo2_arl_scan_entry_t *entry, uint32 *count);
extern int soc_robo2_arl_insert_entry(int unit,
        soc_robo2_arl_scan_entry_t *entry, uint32 *index);
extern int soc_robo2_arl_scan_entry_validate(soc_robo2_arl_scan_entry_t *entry);
extern int soc_robo2_arl_scanner_operation(int unit,
        soc_robo2_arl_scan_entry_t *entry, soc_robo2_arl_scanner_op_t cmd,
        uint32 *index);
extern int soc_robo2_arl_scanner_wait_for(int unit, int32 duration,
        uint32 *result);
extern int soc_robo2_arl_search_first_entry(int unit,
        soc_robo2_arl_scan_entry_t *entry, uint32 *index);
extern int soc_robo2_arl_search_next_entry(int unit,
        soc_robo2_arl_scan_entry_t *entry, uint32 *index);
extern int soc_robo2_arl_update_scan_data_reg(int unit,
        soc_robo2_arl_scan_entry_t *entry);


#endif /* SOC_ROBO2_ARL_SCAN_H */
