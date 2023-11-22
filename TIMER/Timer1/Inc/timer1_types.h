    /******************************************************************************
 * Module: 
 *
 * File Name: timer1_types.h
 *
 * Created on: Nov 4, 2023
 *
 * Description: Header File for the Timer1 Driver
 *
 * Author: Ahmed El-Abbasy 
 *******************************************************************************/

#ifndef MCAL_TIMER_TIMER1_INC_TIMER1_TYPES_H_
#define MCAL_TIMER_TIMER1_INC_TIMER1_TYPES_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define MODE_NORMAL                                       0
#define MODE_PWM_Phase_Correct_8_bit                      1
#define MODE_PWM_Phase_Correct_9_bit                      2
#define MODE_PWM_Phase_Correct_10_bit                     3
#define MODE_CTC                                          4
#define MODE_Fast_PWM_8_bit                               5
#define MODE_Fast_PWM_9_bit                               6
#define MODE_Fast_PWM_10_bit                              7
#define MODE_PWM_Phase_and_Frequency_Correct_ICR1		  8
#define MODE_PWM_Phase_and_Frequency_Correct_OCR1A		  9
#define MODE_PWM_Phase_Correct_ICR1                       10
#define MODE_PWM_Phase_Correct_OCR1A                      11
#define MODE_CTC_ICR1                                     12
#define MODE_Reserved                                     13
#define MODE_FAST_PWM_ICR1                                14
#define MODE_FAST_PWM_OCR1A                               15


#define TIMER0_PRESCALER_msk			0b11111000
#define TIMER0_PRESCALER_NoCk			0b00000000
#define TIMER0_PRESCALER_1				0b00000001
#define TIMER0_PRESCALER_8				0b00000010
#define TIMER0_PRESCALER_64				0b00000011
#define TIMER0_PRESCALER_256			0b00000100
#define TIMER0_PRESCALER_1024			0b00000101


#define External_Clock_Falling_Edge		0b00000110
#define External_Clock_Rising_Edge		0b00000111
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


#endif /* MCAL_TIMER_TIMER1_INC_TIMER1_TYPES_H_ */

/*******************************************************************************
 *                      End of File: timer0_types.h                                   *
 *******************************************************************************/