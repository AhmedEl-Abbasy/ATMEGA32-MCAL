/******************************************************************************
 * Module:
 *
 * File Name: adc.c
 *
 * Description:
 *
 * Created on: 10/23/2023 1:46:50 PM
 *
 * Author: Ahmed El-Abbasy 
 *
 *******************************************************************************/
/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "adc.h"


/*******************************************************************************
 *                      Local Data                                             *
 *******************************************************************************/
static void(*ADC_CALLBACKptr)(void) =NULL;

/*******************************************************************************
 *                      Global Data                                            *
 *******************************************************************************/


 /*******************************************************************************
 *                      ISR's Definitions                                      *
 *******************************************************************************/


/*******************************************************************************
 *                      Private Functions Prototypes                           *
 *******************************************************************************/


/*******************************************************************************
 *                      Private Functions Definitions                          *
 *******************************************************************************/
 

/*******************************************************************************
 *                      Global Functions Definitions                           *
 *******************************************************************************/

void ADC_Initialize(void)
{
	/*******Selecting Voltage reference *******/
	ADMUX_Reg &= ADC_VOLAGE_REF_clr_msk;
	ADMUX_Reg |= ADC_VOLAGE_REF_SELECTOR_msk;
	/******************************************/
	/*********Selecting ADC Mode **************/
	#if ADC_MODE_SELECTOR == ADC_MODE_AUTO_TRIGGER
		SET_BIT(ADCSRA_Reg,ADATE_pin);
		SFIOR_Reg &= ADC_AUTO_TEIG_SRC_clr_msk;
		SFIOR_Reg |= ADC_AUTO_TRIG_SRCE_SELECTOR;
	#elif ADC_MODE_SELECTOR == ADC_MODE_SINGLE_CONVERSION
		CLEAR_BIT(ADCSRA_Reg,ADATE_pin);
	#endif
	/******************************************/
	/*********Selecting Adjusted  *************/
	#if ADC_ADJUSTMENT_SELECTOR ==  ADC_RIGHT_ADJUSTED
		CLEAR_BIT(ADMUX_Reg,ADLAR_pin);
	#elif ADC_ADJUSTMENT_SELECTOR ==  ADC_LEFT_ADJUSTED
		SET_BIT(ADMUX_Reg,ADLAR_pin);
	#endif
	/******************************************/
	/********* Clearing Interrupt Flag**************/
		SET_BIT(ADCSRA_Reg,ADIF_pin);
	/******************************************/
	/************** Enabling ADC ****************/
		SET_BIT(ADCSRA_Reg,ADEN_pin);
	/******************************************/
}

void ADC_StartConversion(ADC_Channel_types ADC_Channel)
{
	//dio_vidConfigChannel(DIO_PORTA, ADC_Channel, INPUT);
	ADMUX_Reg &= ADC_CHANNEL_SELECTOR_clr_msk;  		
	ADMUX_Reg |= ADC_Channel;

	SET_BIT(ADCSRA_Reg,ADSC_pin);
}

u16 ADC_GetResult(void)
{
	SET_BIT(ADCSRA_Reg,ADSC_pin);//
	#if ADC_MODE_SELECTOR == ADC_MODE_AUTO_TRIGGER
		return ADCLH_Reg;
	#elif ADC_MODE_SELECTOR == ADC_MODE_SINGLE_CONVERSION
		while(CHECK_BIT(ADCSRA_Reg,ADIF_pin));	//this bit clear by hardware
		return ADCLH_Reg;
	#endif
}

void ADC_EnableInt(void)
{
	SET_BIT(ADCSRA_Reg,ADIE_pin);
}

void ADC_DisableInt(void)
{
	CLEAR_BIT(ADCSRA_Reg,ADIE_pin);
}

void ADC_SetCallback(void(*CopyFuncPtr)(void))
{
	ADC_CALLBACKptr = CopyFuncPtr;
}

void __vector_16(void) __attribute__((signal,used));
void __vector_16(void)
{
	if(ADC_CALLBACKptr != NULL)
	{
		ADC_CALLBACKptr();
	}
}


/*******************************************************************************
 *                      End of File: adc_types.h                                       *
 *******************************************************************************/
