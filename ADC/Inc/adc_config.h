/******************************************************************************
 * Module:
 *
 * File Name: adc_config.h
 *
 * Description:
 *
 * Created on: 10/23/2023 1:46:50 PM
 *
 * Author: Ahmed El-Abbasy 
 *
 *******************************************************************************/
#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/

/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/
/*
*Configure the voltage reference 
*Range:
*ADC_VOLAGE_REF_AVCC
*ADC_VOLAGE_REF_AREF
*ADC_VOLAGE_REF_2_56v
**/

#define ADC_VOLAGE_REF_SELECTOR_msk				ADC_VOLAGE_REF_AVCC

#define ADC_VOLAGE_REF_mv						5000
#define ADC_MAX_NUMBER_OF_STEPS					1024

/*
*Configure the ADC mode
*Range:
*ADC_MODE_AUTO_TRIGGER
*ADC_MODE_SINGLE_CONVERSION
**/	
#define ADC_MODE_SELECTOR						ADC_MODE_AUTO_TRIGGER

/*
*Configure the ADC adjustment
*Range:
*ADC_RIGHT_ADJUSTED
*ADC_LEFT_ADJUSTED
**/
#define ADC_ADJUSTMENT_SELECTOR					ADC_RIGHT_ADJUSTED

/*
*Configure the ADC prescaller
*Range:
* ADC_PRESCALER_2_msk
* ADC_PRESCALER_4_msk
* ADC_PRESCALER_8_msk
* ADC_PRESCALER_16_msk
* ADC_PRESCALER_32_msk
* ADC_PRESCALER_64_msk
* ADC_PRESCALER_128_msk
**/
#define ADC_PRESCALLER_SELECTOR_msk				ADC_PRESCALER_128_msk

/*
*Configure the ADC trigger source
*Range:
* ADC_AUTO_TEIG_SRC_FREE_RUNNING_msk
* ADC_AUTO_TEIG_SRC_ANALOG_COMP_msk
* ADC_AUTO_TEIG_SRC_EXIT0_msk
* ADC_AUTO_TEIG_SRC_TIMER0_COMP_msk
* ADC_AUTO_TEIG_SRC_TIMER0_OVF_msk
* ADC_AUTO_TEIG_SRC_TIMER1_COMP_msk
* ADC_AUTO_TEIG_SRC_TIMER1_OVF_msk
* ADC_AUTO_TEIG_SRC_TIMER1_CAPT_msk
**/
#define ADC_AUTO_TRIG_SRCE_SELECTOR				ADC_AUTO_TEIG_SRC_FREE_RUNNING_msk



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
 *                      Global Function Prototypes                             *
 *******************************************************************************/

/*******************************************************************************
 *                      End of File: adc_config.h                                       *
 *******************************************************************************/
#endif /* ADC_CONFIG_H_ */
