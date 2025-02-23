/*
 * $Id: $
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom/Broadcom-Compute-Connectivity-Software-robo2-rsdk/master/Legal/LICENSE file.
 *
 * $Copyright: (c) 2020 Broadcom Inc.
 * All Rights Reserved$
 *
 * Broadcom System Log (bSL)
 *
 * Defines for INTERNAL usage only.
 */

#ifndef _SHR_BSL_H_
#define _SHR_BSL_H_

#include "bslenable.h"
#include "sal_console.h"

#ifndef BSL_FILE
#define BSL_FILE    __FILE__
#endif

#ifndef BSL_LINE
#define BSL_LINE    __LINE__
#endif

#ifndef BSL_FUNC
#define BSL_FUNC    __FUNCTION__
#endif

#define bsl_printf    sal_printf

/* Message macro which includes the standard meta data */
#define BSL_META(str_) \
    "<c=%uf=%sl=%dF=%s>" str_, mchk_, BSL_FILE, BSL_LINE, BSL_FUNC

/* Message macros which include optional meta data */
#define BSL_META_U(u_, str_) \
    "<c=%uf=%sl=%dF=%su=%d>" str_, mchk_, BSL_FILE, BSL_LINE, BSL_FUNC, u_
#define BSL_META_UP(u_, p_, str_) \
    "<c=%uf=%sl=%dF=%su=%dp=%d>" str_, mchk_, BSL_FILE, BSL_LINE, BSL_FUNC, u_, p_
#define BSL_META_UPX(u_, p_, x_, str_) \
    "<c=%uf=%sl=%dF=%su=%dp=%dx=%d>" str_, mchk_, BSL_FILE, BSL_LINE, BSL_FUNC, u_, p_, x_

/* Same as above, but with formatting options */
#define BSL_META_O(opt_, str_) \
    "<c=%uf=%sl=%dF=%so=%u>" str_, mchk_, BSL_FILE, BSL_LINE, BSL_FUNC, opt_
#define BSL_META_OU(opt_, u_, str_) \
    "<c=%uf=%sl=%dF=%so=%uu=%d>" str_, mchk_, BSL_FILE, BSL_LINE, BSL_FUNC, opt_, u_
#define BSL_META_OUP(opt_, u_, p_, str_) \
    "<c=%uf=%sl=%dF=%so=%uu=%dp=%d>" str_, mchk_, BSL_FILE, BSL_LINE, BSL_FUNC, opt_, u_, p_
#define BSL_META_OUPX(opt_, u_, p_, x_, str_) \
    "<c=%uf=%sl=%dF=%so=%uu=%dp=%dx=%d>" str_, mchk_, BSL_FILE, BSL_LINE, BSL_FUNC, opt_, u_, p_, x_

/* Macro for invoking "fast" checker */
#define BSL_LOG(chk_, stuff_) do {              \
        if (bsl_fast_check(chk_)) {             \
            unsigned int mchk_ = chk_;          \
            (void)mchk_;                        \
            bsl_printf stuff_;                  \
        }                                       \
    } while (0)

/* Any layer log macros */
#define LOG_FATAL(ls_, stuff_)          BSL_LOG(ls_|BSL_FATAL, stuff_)
#define LOG_ERROR(ls_, stuff_)          BSL_LOG(ls_|BSL_ERROR, stuff_)
#define LOG_WARN(ls_, stuff_)           BSL_LOG(ls_|BSL_WARN, stuff_)
#define LOG_INFO(ls_, stuff_)           BSL_LOG(ls_|BSL_INFO, stuff_)
#define LOG_VERBOSE(ls_, stuff_)        BSL_LOG(ls_|BSL_VERBOSE, stuff_)
#define LOG_DEBUG(ls_, stuff_)          BSL_LOG(ls_|BSL_DEBUG, stuff_)

/*  Change LOG_CLI appropriately for now it is LOG_INFO */
#define LOG_CLI(stuff_)                 BSL_LOG(BSL_INFO, stuff_)

#endif /* _SHR_BSL_H_ */
