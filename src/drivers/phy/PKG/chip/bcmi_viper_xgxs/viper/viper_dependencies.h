/**************************************************************************************/
/**************************************************************************************/
/*                                                                                    */
/*  Revision      :  viper_dependencies.h 366 2014-03-07 00:36:34Z hongc $ */
/*                                                                                    */
/*  Description   :  API Dependencies to be provided by IP user                       */
/*                                                                                    */
/*  Copyright: (c) 2020 Broadcom Inc.All Rights Reserved.                     */
/*  All Rights Reserved                                                               */
/*  No portions of this material may be reproduced in any form without                */
/*  the written permission of:                                                        */
/*      Broadcom Inc.                                                         */
/*      5300 California Avenue                                                        */
/*      Irvine, CA  92617                                                             */
/*                                                                                    */
/*  All information contained in this document is Broadcom Inc.               */
/*  company private proprietary, and trade secret.                                    */
/*                                                                                    */
/**************************************************************************************/
/**************************************************************************************/
/*
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom/Broadcom-Compute-Connectivity-Software-robo2-rsdk/master/Legal/LICENSE file.
 *
 *  $Copyright: (c) 2020 Broadcom Inc.All Rights Reserved.$
 *  $Id$
*/

/** @file viper_dependencies.h
 * Dependencies to be provided by IP User
 */

#ifndef VIPER_API_DEPENDENCIES_H
#define VIPER_API_DEPENDENCIES_H

#include "viper_err_code.h"

/** Read a register from the currently selected Serdes IP Lane.
 * @param pa phymod_access_t struct
 * @param address Address of register to be read
 * @param val read from the register
 * @return Error code generated by delay function (returns ERR_CODE_NONE if no errors)  
 */
err_code_t viper_pmd_rdt_reg(phymod_access_t *pa,uint16_t address, uint16_t *val);           


/** Write to a register from the currently selected Serdes IP Lane.
 * @param pa phymod_access_t struct
 * @param address Address of register to be written
 * @param val Value to be written to the register
 * @return Error code generated by delay function (returns ERR_CODE_NONE if no errors)  
 */
void viper_pmd_wr_reg(const phymod_access_t *pa,uint16_t address, uint16_t val); 


/** Masked Register Write to the currently selected Serdes IP core/lane.
 * If using Serdes MDIO controller to access the registers, implement this function using viper_pmd_mdio_mwr_reg(..)
 *
 * If NOT using a Serdes MDIO controller or the Serdes PMI Masked write feature, please use the following code to
 * implement this function
 *
 *    viper_pmd_wr_reg(const phymod_access_t *pa,addr, ((viper_pmd_rd_reg(addr) & ~mask) | (mask & (val << lsb))));
 *
 * @param pa phymod_access_t struct
 * @param addr Address of register to be written
 * @param mask 16-bit mask indicating the position of the field with bits of 1s
 * @param lsb  LSB of the field
 * @param val  16bit value to be written
 * @return Error code generated by delay function (returns ERR_CODE_NONE if no errors)  
 */
void viper_pmd_mwr_reg(PHYMOD_ST *pa,uint16_t addr, uint16_t mask, uint8_t lsb, uint16_t val); 

uint16_t viper_pmd_rd_reg(PHYMOD_ST *pa, uint16_t address);

/** Delay the execution of the code for atleast specified amount of time in nanoseconds.
 * This function is used ONLY for delays less than 1 microsecond, non-zero error code may be returned otherwise.
 * The user can implement this as an empty function if their register access latency exceeds 1 microsecond.
 * @param pa phymod_access_t struct
 * @param delay_ns Delay in nanoseconds
 * @return Error code generated by delay function (returns ERR_CODE_NONE if no errors)  
 */
err_code_t viper_delay_ns(uint16_t delay_ns); 


/** Delay the execution of the code for atleast specified amount of time in microseconds.
 * For longer delays, accuracy is required. When requested delay is > 100ms, the implemented delay is assumed 
 * to be < 10% bigger than requested.
 * This function is used ONLY for delays greater than or equal to 1 microsecond.
 * @param pa phymod_access_t struct
 * @param delay_us Delay in microseconds
 * @return Error code generated by delay function (returns ERR_CODE_NONE if no errors)  
 */
err_code_t viper_delay_us(uint32_t delay_us);


/** Return the address of current selected Serdes IP lane.
 * @param pa phymod_access_t struct
 * @return the IP level address of the current lane. 0 to N-1, for an N lane IP
 */
uint8_t viper_get_lane(const phymod_access_t *pa);


#endif
