  /******************************************************************************
 * Module: 
 *
 * File Name: timer0_reg.h
 *
 * Created on: Oct 31, 2023
 *
 * Description: Header File for the Timer0 Driver
 *
 * Author: Ahmed El-Abbasy 
 *******************************************************************************/

#ifndef MCAL_TIMER_INC_TIMER0_REG_H_
#define MCAL_TIMER_INC_TIMER0_REG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define TCCR0_Reg		(*(volatile u8*)(0x53))  //TCCR0 � Timer/Counter Control Register
//FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00
#define TCNT0_Reg		(*(volatile u8*)(0x52))	// TCNT0 � Timer/Counter Register
#define OCR0_Reg		(*(volatile u8*)(0x5C))	//OCR0 � Output Compare Register
#define TIMSK_Reg		(*(volatile u8*)(0x59))	//TIMSK � Timer/Counter Interrupt Mask Register
//OCIE2 TOIE2 TICIE1 OCIE1A OCIE1B TOIE1 OCIE0 TOIE0
#define TIFR_Reg		(*(volatile u8*)(0x58))	//TIFR � Timer/Counter Interrupt Flag Register
//OCF2 TOV2 ICF1 OCF1A OCF1B TOV1 OCF0 TOV0
#define SFIOR_Reg		(*(volatile u8*)(0x50)) //SFIOR � Special Function IO Register

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

#endif /* MCAL_TIMER_INC_TIMER0_REG_H_ */

/*******************************************************************************
 *                      End of File: timer0_reg.h                                     *
 *******************************************************************************/