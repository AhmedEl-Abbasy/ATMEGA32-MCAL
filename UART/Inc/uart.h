 /******************************************************************************
 * Module: 
 *
 * File Name: uart.h
 *
 * Created on: Oct 27, 2023 
 *
 * Description: Header File for the UART Driver
 *
 * Author: Ahmed El-Abbasy 
 *******************************************************************************/
#ifndef UART_H
#define UART_H
/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "Std_Types.h"
#include "uart_reg.h"
#include "bit_math.h"
#include "uart.h"
/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/


#define UART_BAUDRATE_1200			(0x340)
#define UART_BAUDRATE_2400			(0x19F)
#define UART_BAUDRATE_4800			(0xCF)
#define UART_BAUDRATE_9600			(0x67)
#define UART_BAUDRATE_19200			(0x51)
#define UART_BAUDRATE_115200		(0x7)


#define UART_5_BIT_DATA				(0<<UCSZ0_BIT_NO)
#define UART_6_BIT_DATA				(1<<UCSZ0_BIT_NO)
#define UART_7_BIT_DATA				(2<<UCSZ0_BIT_NO)
#define UART_8_BIT_DATA				(3<<UCSZ0_BIT_NO)

#define UART_1_STOP_BIT				(0<<USBS_BIT_NO)
#define UART_2_STOP_BIT				(1<<USBS_BIT_NO)

#define UART_EVEN_PARITY			(2<<UPM0_BIT_NO)
#define UART_ODD_PARITY				(3<<UPM0_BIT_NO)


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

void UART_Init(u16 baudRate);
void UART_TransmitChr(u8 data);
void UART_TransmitStr(u8 *str);
u8 UART_ReceiveChr(void);
void UART_TransmitStrPoll(u8 str[]);


void UART_setTxCallback(void(*CopytxCallFuncPtr)(void));

void UART_setRxCallback(void(*CopyrxCallFuncPtr)(void));


/*******************************************************************************
 *                      End of File: uart.h                                        *
 *******************************************************************************/
#endif  /* UART_H */
