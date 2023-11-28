/******************************************************************************
 * Module:
 *
 * File Name: adc_types.h
 *
 * Description:
 *
 * Created on: 10/23/2023 1:46:50 PM
 *
 * Author: Ahmed El-Abbasy 
 *
 *******************************************************************************/
#ifndef ADC_TYPES_H_
#define ADC_TYPES_H_
/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/

/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/

/* ADC Voltage Select (ADMUX)->REFS1,REFS0*/
#define ADC_VOLAGE_REF_clr_msk		0b00111111
#define ADC_VOLAGE_REF_AVCC			0b01000000
#define ADC_VOLAGE_REF_AREF			0b00000000
#define ADC_VOLAGE_REF_2_56v		0b11000000 

/* ADC MODE Select (ADCSRA)->ADSC(6),ADATE(5) */ 
#define ADC_MODE_AUTO_TRIGGER		1
#define ADC_MODE_SINGLE_CONVERSION	0

/* ADC ADJUST Select (ADMUX)->ADLAR(4)*/
#define ADC_RIGHT_ADJUSTED			0
#define ADC_LEFT_ADJUSTED			1

/* ADC PRESCALER Select (ADCSRA)->ADPS2(2),ADPS1(1),ADPS0(0) */
#define ADC_PRESCALER_clr_msk		0b11111000
#define ADC_PRESCALER_2_msk			0b00000000
#define ADC_PRESCALER_4_msk			0b00000010
#define ADC_PRESCALER_8_msk			0b00000011
#define ADC_PRESCALER_16_msk		0b00000100
#define ADC_PRESCALER_32_msk		0b00000101
#define ADC_PRESCALER_64_msk		0b00000110
#define ADC_PRESCALER_128_msk		0b00000111

/* ADC Auto Trigger Select (SFIOR)->ADTS2(7),ADTS1(6),ADTS0(5)*/
#define ADC_AUTO_TEIG_SRC_clr_msk			0b00011111
#define ADC_AUTO_TEIG_SRC_FREE_RUNNING_msk	0b00000000
#define ADC_AUTO_TEIG_SRC_ANALOG_COMP_msk	0b00100000
#define ADC_AUTO_TEIG_SRC_EXIT0_msk			0b01000000
#define ADC_AUTO_TEIG_SRC_TIMER0_COMP_msk	0b01100000
#define ADC_AUTO_TEIG_SRC_TIMER0_OVF_msk	0b10000000
#define ADC_AUTO_TEIG_SRC_TIMER1_COMP_msk	0b10100000
#define ADC_AUTO_TEIG_SRC_TIMER1_OVF_msk	0b11000000
#define ADC_AUTO_TEIG_SRC_TIMER1_CAPT_msk	0b11100000

/** ADC  Mask to clear channel   **/
#define ADC_CHANNEL_SELECTOR_clr_msk	 0b11100000



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
 *                      End of File: adc_types.h                                       *
 *******************************************************************************/
#endif /* ADC_TYPES_H_ */
