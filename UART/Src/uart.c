  /******************************************************************************
 * Module: 
 *
 * File Name: uart.c
 *
 * Created on: Oct 27, 2023 
 *
 * Description: Source File for the UART Driver
 *
 * Author: Ahmed El-Abbasy 
 *******************************************************************************/
 
 /*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/

#include "uart.h"
#include <avr/interrupt.h>
/*******************************************************************************
 *                      Local Data                                             *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Data                                            *
 *******************************************************************************/

void(*txCallBackPtr)(void) = NULL;
void(*rxCallBackPtr)(void) = NULL;

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
void UART_Init(u16 baudRate)
{
	/* Set baud rate */
	UART_UBRRH_REG = (u8)(baudRate>>8);
	UART_UBRRL_REG = (u8)baudRate;
	/* Enable receiver and transmitter */
	SET_BIT(UART_UCSRB_REG,RXEN_BIT_NO);  /* Enable Receiver*/
	SET_BIT(UART_UCSRB_REG,TXEN_BIT_NO);  /* Enable Transmitter */
	/* Set frame format: 8data, 1stop bit, Even Parity */
	UART_UCSRC_REG |= (1 << URSEL_BIT_NO)|UART_8_BIT_DATA | UART_EVEN_PARITY;

	
	/*	Enable Rx complete	*/
	SET_BIT(UART_UCSRB_REG,RXC_BIT_NO);
	/*	Enable Tx complete	*/
	SET_BIT(UART_UCSRB_REG,TXC_BIT_NO);
}

void UART_TransmitChr(u8 data)
{
	/* Wait for empty transmit buffer */
//	while (!(CHECK_BIT(UART_UCSRA_REG,UDRE_BIT_NO)))
//			;
	/* Put data into buffer, sends the data */
	UART_UDR_REG = data;
}

u8 UART_ReceiveChr(void)
{
	/* Wait for data to be received */
//	while (!(CHECK_BIT(UART_UCSRA_REG,RXC_BIT_NO)))
//			;
	/* Get and return received data from buffer */
	return UART_UDR_REG;
}

void UART_TransmitStrPoll(u8 str[])
{
	while (*str != '\0')
	{
		UART_TransmitChr(*str);
		str++;
	}
}

void UART_TransmitStr(u8 *str)
{
	u8 i=0;
	/*	copy str into global tx buffer	*/
	/*
	for (i=0; i < TX_BUFFER_MAX_SIZE; i++)
	{
		tx_buffer[i] = str[i];
	}*/
	//UART_TransmitChr(tx_buffer[tx_index]);
	UART_TransmitChr(*str);
}


void UART_setTxCallback(void(*CopytxCallFuncPtr)(void))
{
	txCallBackPtr = CopytxCallFuncPtr;
}
ISR(USART_TXC_vect)
{
	if(txCallBackPtr != NULL)
	{
		txCallBackPtr();
	}
}

void UART_setRxCallback(void(*CopyrxCallFuncPtr)(void))
{
	rxCallBackPtr = CopyrxCallFuncPtr;
}

ISR(USART_RXC_vect)
{
	if(rxCallBackPtr != NULL)
	{
		rxCallBackPtr();
	}

}

/*******************************************************************************
 *                      End of File: uart.c                                        *
 *******************************************************************************/
