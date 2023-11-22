   /******************************************************************************
 * Module: 
 *
 * File Name: timer1_reg.h
 *
 * Created on: Nov 4, 2023
 *
 * Description: Header File for the Timer1 Driver
 *
 * Author: Ahmed El-Abbasy 
 *******************************************************************************/

#ifndef MCAL_TIMER_TIMER1_INC_TIMER1_REG_H_
#define MCAL_TIMER_TIMER1_INC_TIMER1_REG_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define TCCR1A_Reg		*((volatile u8*) 0x4F)
#define TCCR1B_Reg		*((volatile u8*) 0x4E)


#define TCNT1H_Reg		*((volatile u8*)  0x4D)
#define TCNT1L_Reg		*((volatile u8*)  0x4C)
#define TCNT1_Reg		*((volatile u16*) 0x4C)


#define OCR1AH_Reg		*((volatile u8*) 0x4B)
#define OCR1AL_Reg		*((volatile u8*) 0x4A)
#define OCR1BH_Reg		*((volatile u8*) 0x49)
#define OCR1BL_Reg		*((volatile u8*) 0x48)

#define ICR1H_Reg		*((volatile u8*)0x47)
#define ICR1L_Reg		*((volatile u8*)0x46)
#define ICR1_Reg		*((volatile u16*)0x46)


#define TIMSK_Reg		*((volatile u8*) 0x59)
#define TIFR_Reg		*((volatile u8*) 0x58)


#define ICF1_pin		5
#define ICES1_pin		6
#define TOIE1_pin		2
#define TICIE1_pin		5
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

#endif /* MCAL_TIMER_TIMER1_INC_TIMER1_REG_H_ */
/*******************************************************************************
 *                      End of File: timer1_reg.h                                     *
 *******************************************************************************/