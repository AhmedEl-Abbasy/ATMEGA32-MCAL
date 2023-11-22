 /******************************************************************************
 * Module: 
 *
 * File Name: timer0_config.h
 *
 * Created on: Oct 31, 2023
 *
 * Description: Header File for the Timer0 Driver
 *
 * Author: Ahmed El-Abbasy 
 *******************************************************************************/
#ifndef MCAL_TIMER_INC_TIMER0_CONFIG_H_
#define MCAL_TIMER_INC_TIMER0_CONFIG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "timer0_types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*
 *  MODE_NORMAL
 *  MODE_CTC
 *  MODE_FAST_PWM
 *  MODE_PHASE_PWM
 */
#define TIMER0_MODE				MODE_PHASE_PWM

/*
 * TIMER0_PRESCALER_NoCk
 * TIMER0_PRESCALER_1
 * TIMER0_PRESCALER_8
 * TIMER0_PRESCALER_64
 * TIMER0_PRESCALER_256
 * TIMER0_PRESCALER_1024
 */
#define PRESCALER_DEF			TIMER0_PRESCALER_1024

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* MCAL_TIMER_INC_TIMER0_CONFIG_H_ */
/*******************************************************************************
 *                      End of File: timer0_config.h                                      *
 *******************************************************************************/
