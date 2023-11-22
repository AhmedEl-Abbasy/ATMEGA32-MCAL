 /******************************************************************************
 * Module: 
 *
 * File Name: timer0.c
 *
 * Created on: Oct 31, 2023
 *
 * Description:  Source file for the Timer0 Driver
 *
 * Author: Ahmed El-Abbasy 
 *******************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "timer0.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
void(*CallBackTimer0Ptr)(void) = NULL;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Timer0_Init()
{
	Timer0_Stop();

	switch (TIMER0_MODE)
	{
		case MODE_NORMAL:
			CLEAR_BIT(TCCR0_Reg,6);		//WGM00
			CLEAR_BIT(TCCR0_Reg,3);		//WGM01

			/* Enable Overflow Interrupt */
			SET_BIT(TIMSK_Reg,0);		//TOIE0
		break;
		case MODE_CTC:
			//CLEAR_BIT(TCCR0_Reg,6); //WGM00
			//  SET_BIT(TCCR0_Reg,3); //WGM01
			/* toggle OC0 pin*/
			  //SET_BIT(TCCR0,COM00);
			 // CLEAR_BIT(TCCR0,COM01);
		break;
		case MODE_FAST_PWM:
			/*
			Put your code here*/
			TCCR0_Reg = 0;

			SET_BIT(TCCR0_Reg,6);		//WGM00
			SET_BIT(TCCR0_Reg,3);		//WGM01
			SET_BIT(TCCR0_Reg,5);		//COM01
			SET_BIT(TCCR0_Reg,0);		//CS00
		break;
		case MODE_PHASE_PWM:
			/*
			Put your code here	*/
			TCCR0_Reg = 0;

			SET_BIT(TCCR0_Reg,6);		//WGM00
			SET_BIT(TCCR0_Reg,5);		//COM01
			SET_BIT(TCCR0_Reg,0);		//CS00
		break;
	}
}
void Timer0_Start(void)
{
	//SET_BIT(TCCR0_Reg,0);
	TCCR0_Reg = 0x01;
	TCCR0_Reg &= TIMER0_PRESCALER_msk;
	TCCR0_Reg |= PRESCALER_DEF;
	//CLEAR_BIT(TIFR_Reg,0);
}
void Timer0_Stop(void)
{
	TCCR0_Reg =0;
}
void Timer0_ResetCounters(void)
{
	TCNT0_Reg = 0x0;
}

void Timer0_DelayUS(u32 delayUS)  //500us
{
	EXTI_DisableGlobalInt();
	u16 ovcounter =0;
	u16 ovcounter1 =0;
	ovcounter = (delayUS * 16) %(8*256);	             //232
	ovcounter  = ovcounter % 256;						//232
	ovcounter1 = (delayUS * 16) /(8*256);					//3

	TCNT0_Reg = 256-ovcounter;					//24
	for(u16 i=0 ;i < ovcounter1+1 ;i++)
	{
		Timer0_Start();
		while((TIFR_Reg&0x01)==0);
		Timer0_Stop();
		TIFR_Reg = 0x1;
	}
	EXTI_EnableGlobalInt();
}
void Timer0_DelayMS(u32 delayMS) //5ms
{
	EXTI_DisableGlobalInt();
	u16 ovcounter =0;
	u16 ovcounter1 =0;
	ovcounter = (delayMS * 16000) /(8*256);	             //39
	ovcounter1 = ((delayMS * 16000)) - ovcounter*256*8 ; //128
	ovcounter1 /= 8;									//16

	TCNT0_Reg = 1+ovcounter1;
	for(u16 i=0 ;i < ovcounter ;i++)
	{
		Timer0_Start();
		while((TIFR_Reg&0x01)==0);
		Timer0_Stop();
		TIFR_Reg = 0x1;
	}
	EXTI_EnableGlobalInt();
}

/* duty in range 0:100 */
static u8 duty_var = 0;
void Timer0_SetDuty(u8 duty)
{
	TCCR0_Reg |= PRESCALER_DEF;
	duty_var = duty;
	u16 rec=0 ;
	rec = duty *255;
	OCR0_Reg=rec/100;
}
void Timer0_IncDuty(u8 incDuty)
{
	duty_var =duty_var +incDuty;
	if(duty_var <= 100)
		Timer0_SetDuty(duty_var);
	else if(duty_var > 100)
		Timer0_SetDuty(100);
}
void Timer0_DecDuty(u8 decDuty)
{
	duty_var =duty_var -decDuty;
	if(duty_var >= 0)
		Timer0_SetDuty(duty_var);
	else if(duty_var < 0)
		Timer0_SetDuty(0);
}

void timer0_SetCallback(void(*CopyT0FuncPtr)(void))
{
	CallBackTimer0Ptr=CopyT0FuncPtr;
}

void __vector_11(void) __attribute__((signal,used));
void __vector_11(void)
{
	if(CallBackTimer0Ptr != NULL)
	{
		CallBackTimer0Ptr();
	}
}

/*******************************************************************************
 *                      End of File: timer0.c                                       *
 *******************************************************************************/


