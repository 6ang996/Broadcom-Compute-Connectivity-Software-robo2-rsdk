/*
 *         
 * $Id: eagle_common.c,v 1.1.2.5 2013/09/12 10:43:06 nirf Exp $
 * 
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom/Broadcom-Compute-Connectivity-Software-robo2-rsdk/master/Legal/LICENSE file.
 *
 * $Copyright: 
 * All Rights Reserved.$
 *         
 *     
 */

#include "eagle_common.h"


int eagle_osr_mode_to_enum(int osr_mode, phymod_osr_mode_t* osr_mode_en)
{
    switch(osr_mode) {
        case 0: *osr_mode_en = phymodOversampleMode1; break;
        case 1: *osr_mode_en = phymodOversampleMode2; break;
        case 2: *osr_mode_en = phymodOversampleMode3; break;
        case 3: *osr_mode_en = phymodOversampleMode3P3; break;
        case 4: *osr_mode_en = phymodOversampleMode4; break;
        case 5: *osr_mode_en = phymodOversampleMode5; break;
        case 6: *osr_mode_en = phymodOversampleMode7P5; break;
        case 7: *osr_mode_en = phymodOversampleMode8; break;
        case 8: *osr_mode_en = phymodOversampleMode8P25; break;
        case 9: *osr_mode_en = phymodOversampleMode10; break;
        default:
            PHYMOD_RETURN_WITH_ERR(PHYMOD_E_INTERNAL, (_PHYMOD_MSG("unsupported OS mode %d"), osr_mode));
    }
    return PHYMOD_E_NONE;
}



