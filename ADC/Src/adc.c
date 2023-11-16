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
 *                      Global Constant Macros                                 *
 *******************************************************************************/

/*******************************************************************************
 *                      Global Function Macros                                 *
 *******************************************************************************/

/*******************************************************************************
 *                      Global Data Types and Structures                       *
 *******************************************************************************/

/*******************************************************************************
 *                      Global Data Prototypes                                 *
 *******************************************************************************/

/*******************************************************************************
 *                      Global Function                              *
 *******************************************************************************/


void ADC_Initialize(void)
{
	/*******Selecting Voltage reference *******/
	
	ADMUX_Reg &= ADC_VOLAGE_REF_clr_msk;
	ADMUX_Reg |= ADC_VOLAGE_REF_SELECTOR_msk;	
	
	/******************************************/
	
	/*********Selecting ADC Mode **************/
	#if ADC_MODE_SELECTOR == ADC_MODE_AUTO_TRIGGER
		SET_BIT(ADCSRA_Reg,5);
		//ADCSRA_Reg |= (1 << 5);
		SFIOR_Reg &= ADC_AUTO_TEIG_SRC_clr_msk;
		SFIOR_Reg |= ADC_AUTO_TRIG_SRCE_SELECTOR;	
	#elif ADC_MODE_SELECTOR == ADC_MODE_SINGLE_CONVERSION
		CLEAR_BIT(ADCSRA_Reg,5);
		//ADCSRA_Reg &= ~(1 << 5);
	#endif
	
	
	/******************************************/
	
	/*********Selecting Adjusted  *************/
	#if ADC_ADJUSTMENT_SELECTOR ==  ADC_RIGHT_ADJUSTED
		CLEAR_BIT(ADMUX_Reg,5);
		//ADMUX_Reg &=~(1 << 5);
	#elif ADC_ADJUSTMENT_SELECTOR ==  ADC_LEFT_ADJUSTED
		SET_BIT(ADMUX_Reg,5);
		//ADMUX_Reg |= (1 << 5);
	#endif
	/******************************************/
	
	/********* Clearing Interrupt Flag**************/
		SET_BIT(ADCSRA_Reg,4);
	//ADCSRA_Reg |= (1 << 4);
	/******************************************/
	
	/************** Enabling ADC ****************/
		SET_BIT(ADCSRA_Reg,7);
		//ADCSRA_Reg |= (1 << 7);
	/******************************************/
	
	
}

u16 ADC_StartConversion(ADC_Channel_types ADC_Channel)
{
	/***************** Select Channel *************************/
	ADMUX_Reg &= 0b11100000;  		// ADC  Mask to clear channel */  /*ADC_CHANNEL_SELECTOR_clr_msk	 0b11100000*/
	ADMUX_Reg |= ADC_Channel;
	/******************************************/
	/***************** Start Conversion *************************/
	SET_BIT(ADCSRA_Reg,6);
	/******************************************/
	while(CHECK_BIT(ADCSRA_Reg,6));	//this bit clear by hardware
	return ADCLH_Reg;
}


/*******************************************************************************
 *                      End of File: adc_types.h                                       *
 *******************************************************************************/
