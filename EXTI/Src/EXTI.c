/*******************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------
 * Module: 
 *
 * File Name: EXTI.c
 *
 * Created on: 10/22/2023 2:22:26 PM 
 *
 * Description: Source file for the EXTI driver
 *
 * Author: Ahmed El-Abbasy
 *
 *******************************************************************************/

/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "EXTI.h"


/*******************************************************************************
 *                      Local Data                                             *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Data                                            *
 *******************************************************************************/
void(*CallBackPtr)(void) = NULL;

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

void EXTI_Initialization(void)
{
	CLEAR_BIT(MCUCR_REG,0);
	CLEAR_BIT(MCUCR_REG,1);
	CLEAR_BIT(MCUCR_REG,2);
	CLEAR_BIT(MCUCR_REG,3);
	CLEAR_BIT(MCUCSR_REG,6);
	
	
	MCUCR_REG |=  EXTI0_MODE;
	MCUCR_REG |= (EXTI1_MODE<<2);
	MCUCSR_REG |= (EXTI2_MODE<<6);

#if		EXTI_INT0_INIT_STATE == EXTI_Enable_state
	SET_BIT(GICR_REG,6); 
#elif	EXTI_INT0_INIT_STATE == EXTI_Disable_state
	CLEAR_BIT(GICR_REG,6);
#endif	

#if		EXTI_INT1_INIT_STATE == EXTI_Enable_state
	SET_BIT(GICR_REG,7); 
#elif	EXTI_INT1_INIT_STATE == EXTI_Disable_state
	CLEAR_BIT(GICR_REG,7);
#endif

#if		EXTI_INT2_INIT_STATE == EXTI_Enable_state
	SET_BIT(GICR_REG,5); 
#elif	EXTI_INT2_INIT_STATE == EXTI_Disable_state
	CLEAR_BIT(GICR_REG,5);
#endif
	 
	SET_BIT(GIFR_REG,5);
	SET_BIT(GIFR_REG,6);
	SET_BIT(GIFR_REG,7);
}

void EXTI_EnableInt0(void)
{
	SET_BIT(GICR_REG,6);
}

void EXTI_DisableInt0(void)
{
	CLEAR_BIT(GICR_REG,6);
}

void EXTI_SetCallback(void(*CopyFuncPtr)(void))
{
	CallBackPtr = CopyFuncPtr;
}

void __vector_1(void) __attribute__((signal,used));
void __vector_1(void)
{
	if(CallBackPtr != NULL)
	{
		CallBackPtr();
	}	
}
/*******************************************************************************
 *                      End of File: EXTI.c                                       *
 *******************************************************************************/

