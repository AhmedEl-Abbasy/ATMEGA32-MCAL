  /******************************************************************************
 * Module: 
 *
 * File Name: timer1.h
 *
 * Created on: Nov 4, 2023
 *
 * Description: Header File for the Timer1 Driver
 *
 * Author: Ahmed El-Abbasy 
 *******************************************************************************/

#ifndef MCAL_TIMER_TIMER1_INC_TIMER1_H_
#define MCAL_TIMER_TIMER1_INC_TIMER1_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"
#include "std_types.h"
#include "bit_math.h"
#include "dio.h"

#include "timer1_types.h"
#include "timer1_config.h"
#include "timer1_reg.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PINS_WGM11_WGM10_msk		0b11111100
#define PINS_WGM13_WGM12_msk		0b11111100

#define PINS_WGM11_WGM10_NORMAL_MODE	0b00000000
#define PINS_WGM13_WGM12_NORMAL_MODE	0b00000000


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
void Timer1_Init();
void Timer1_Start(void);
void Timer1_Stop(void);
void Timer1_ResetCounters(void);

void timer1_SetCallback(void(*CopyT1FuncPtr)(void));
void timer1_SetICUCallback(void(*CopyT1_ICUFuncPtr)(void));


//void Timer1_DelayUS(u32 delayUS);
//void Timer1_DelayMS(u32 delayMS);
//
///* duty in range 0:100 */
//void Timer1_SetDuty(u8 duty);
//void Timer1_IncDuty(u8 incDuty);
//void Timer1_DecDuty(u8 decDuty);


/* ICU */
void ICU_init();
void ICU_get_Event(u8 );
void ICU_get_PWM(u8* duty, u32* freq);
//void calculateDaF(u16 t0,u16 t1,u16 t2);
//u32 ICU_get(u8 mode);
//FP32 ICU_get_pwm();

/*******************************************************************************
 *                      End of File: timer1.h                                       *
 *******************************************************************************/
#endif /* MCAL_TIMER_TIMER1_INC_TIMER1_H_ */
