  /******************************************************************************
 * Module: 
 *
 * File Name: timer1.c
 *
 * Created on: Nov 4, 2023
 *
 * Description:  Source file for the Timer1 Driver
 *
 * Author: Ahmed El-Abbasy 
 *******************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "timer1.h"

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
void(*CallBackTimer1Ptr)(void) = NULL;
void(*CallBackTimer1_ICUPtr)(void) = NULL;
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Timer1_Init()
{
	//Timer1_Stop();
	TCCR1A_Reg &= PINS_WGM11_WGM10_msk;
	TCCR1B_Reg &= PINS_WGM13_WGM12_msk;
	switch (TIMER1_MODE)
	{
		case MODE_NORMAL:
			TCCR1A_Reg |=PINS_WGM11_WGM10_NORMAL_MODE;
			TCCR1A_Reg |=PINS_WGM13_WGM12_NORMAL_MODE;

			/* Enable Overflow Interrupt */
			SET_BIT(TIMSK_Reg,TOIE1_pin);		//TOIE1
		break;
		case MODE_CTC:
				/*            */
		break;
	}
}
void Timer1_Start(void)
{
	TCCR1B_Reg = 0x01;
	//TCCR1B_Reg &= TIMER0_PRESCALER_msk;
	TCCR1B_Reg |= PRESCALER_DEF;
}
void Timer1_Stop(void)
{
	TCCR1B_Reg =0;
}
void Timer1_ResetCounters(void)
{
	TCNT1_Reg = 0x0000;
}

//void ICU_init()
//{
//	SET_BIT(TIMSK_Reg,TICIE1_pin);
//	SET_BIT(TCCR1B_Reg,ICES1_pin);// raising
//}
///////******************************************************************************************
static u8 get_ICU_flag =5;
static u8 get_ICU_flag2 =0;
static u32 D = 0;
static u32 F = 0;

void ICU_get_PWM(u8* duty, u32* freq)
{

	if (get_ICU_flag ==5)
	{
		SET_BIT(TIMSK_Reg,TICIE1_pin);
		SET_BIT(TCCR1B_Reg,ICES1_pin);// raising
//		get_ICU_flag=1;
	}
	while((get_ICU_flag < 1) & (get_ICU_flag2 == 0));
	while(get_ICU_flag < 2);
	while(get_ICU_flag < 3);

	*duty =(u8)D;
	*freq =F;
	get_ICU_flag =0;

}

void ICU_get_Event(u8 stateflag1)
{
	static u32 t0 =0;
	static u32 t1 =0;
	static u32 t2 =0;
	u32 T1 =0;
	u32 T2 =0;
	u32 Tt =0;

	if(stateflag1 == 0)
	{
		t0 = ICR1_Reg;
//		t0 = 100;
//		//t0 =1;
		CLEAR_BIT(TCCR1B_Reg,ICES1_pin);// falling
		get_ICU_flag = 1;
		get_ICU_flag2 = 1;
	}
	else if(stateflag1 == 1)
	{
		t1 = ICR1_Reg;
//		t1 = 60000;
//		//t1 = 20;
		SET_BIT(TCCR1B_Reg,ICES1_pin);//  raising
		get_ICU_flag2 = 0;
		get_ICU_flag = 2;
	}
	else if(stateflag1 == 2)
	{
		t2 = ICR1_Reg;
//		t2 = 50000;
		//t2 = 40;
		//CLEAR_BIT(TCCR1B_Reg,ICES1_pin);// falling
//		T1 = t1-t0;			//20
//		T2 = t2-t1;		//20
		if(t1 > t0)
		{
			T1 = t1-t0;			//59900
		}
		else
		{
			T1 = 65535-(t0-t1);
		}
		if(t2 > t1)
		{
			T2 = (t2-t1);		//90.000
		}
		else
		{
			T2 = (65535-(t1-t2));			//55535
			//T2 =t2+65535-t1;
		}
		Tt = T1 + T2;		//115435
		D= T1*100;			//5990000
		D =D/Tt;  //%			//

		F = 1*1000000;
		F= F/Tt;
		F = F*1000;
		F= F/125;

		t0 =0;
		t1 =0;
		t2 =0;
		get_ICU_flag = 3;
		//get_ICU_flag2 =2;
	}
}

void timer1_SetCallback(void(*CopyT1FuncPtr)(void))
{
	CallBackTimer1Ptr=CopyT1FuncPtr;
}
void __vector_9(void) __attribute__((signal,used));
void __vector_9(void)
{
	if(CallBackTimer1Ptr != NULL)
	{
		CallBackTimer1Ptr();
	}
}
void timer1_SetICUCallback(void(*CopyT1_ICUFuncPtr)(void))
{
	CallBackTimer1_ICUPtr=CopyT1_ICUFuncPtr;
}
void __vector_6(void) __attribute__((signal,used));
void __vector_6(void)
{
	if(CallBackTimer1_ICUPtr != NULL)
	{
		CallBackTimer1_ICUPtr();
	}
}

/*******************************************************************************
 *                      End of File: timer1.c                                       *
 *******************************************************************************/