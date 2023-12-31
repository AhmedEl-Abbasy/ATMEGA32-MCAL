 /******************************************************************************
 * Module: 
 *
 * File Name: uart_reg.h
 *
 * Created on: Oct 27, 2023 
 *
 * Description: Header File for the UART Driver
 *
 * Author: Ahmed El-Abbasy 
 *******************************************************************************/
#ifndef UART_REG_H
#define UART_REG_H
/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "std_types.h"
#include "uart.h"
/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/
#define UART_UDR_REG				(*(volatile u8* const)0x2C)
#define UART_UCSRA_REG				(*(volatile u8* const)0x2B)
#define UART_UCSRB_REG				(*(volatile u8* const)0x2A)
#define UART_UBRRH_REG				(*(volatile u8* const)0x40)
#define UART_UCSRC_REG				(*(volatile u8* const)0x40)
#define UART_UBRRL_REG				(*(volatile u8* const)0x29)

#define RXEN_BIT_NO						(4)
#define TXEN_BIT_NO						(3)
#define URSEL_BIT_NO					(7)
#define USBS_BIT_NO						(3)
#define UCSZ0_BIT_NO					(1)
#define UPM0_BIT_NO						(4)
#define UDRE_BIT_NO						(5)
#define TXC_BIT_NO						(6)
#define RXC_BIT_NO						(7)

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
 *                      End of File: uart_reg.h                                        *
 *******************************************************************************/

#endif  /* UART_REG_H */
