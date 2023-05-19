/*
* EXT_INTERRUPT_Prog.c
*
*  Created on: 9 Apr 2023
*      Author: 20101
*/


#include "EXT_INTERRUPT_Interface.h"


extern const ST_EXT_INTERRUPTS_CFG A_interruptConfig[EXT_INTERRUPT_PINS];


static void(*INT0_InterruptHandler)(void) = NULL;
static void(*INT1_InterruptHandler)(void) = NULL;
static void(*INT2_InterruptHandler)(void) = NULL;


void EXT_vINTERRUPT_setSenseControl()
{
	Uchar8_t elementIndex = 0;
	while(elementIndex < EXT_INTERRUPT_PINS)
	{
		switch(A_interruptConfig[elementIndex].EXTERNAL_INTERRUPRT_Number)
		{
			case EXT0_INTERRUPTS:
			{

				if(A_interruptConfig[elementIndex].EXTERNAL_INTERRUPRT_Sense_Control == LOW_LEVEL_SENSE_CONTROL)
				{
					MCU_vEnableInterrupt();
					CLEAR_BIT(MCUCR_REG,MCUCR_REG_ISC01_BITS);
					CLEAR_BIT(MCUCR_REG,MCUCR_REG_ISC00_BITS);
					SET_BIT(GICR_REG,GICR_REG_INT0_BITS);
				}
				else if(A_interruptConfig[elementIndex].EXTERNAL_INTERRUPRT_Sense_Control == ANY_LOGICAL_SENSE_CONTROL)
				{
					MCU_vEnableInterrupt();
					CLEAR_BIT(MCUCR_REG,MCUCR_REG_ISC01_BITS);
					SET_BIT(MCUCR_REG,MCUCR_REG_ISC00_BITS);
					SET_BIT(GICR_REG,GICR_REG_INT0_BITS);
				}
				else if(A_interruptConfig[elementIndex].EXTERNAL_INTERRUPRT_Sense_Control == FALLING_EDGE_SENSE_CONTROL)
				{
					MCU_vEnableInterrupt();
					SET_BIT(MCUCR_REG,MCUCR_REG_ISC01_BITS);
					CLEAR_BIT(MCUCR_REG,MCUCR_REG_ISC00_BITS);
					SET_BIT(GICR_REG,GICR_REG_INT0_BITS);
				}
				else if(A_interruptConfig[elementIndex].EXTERNAL_INTERRUPRT_Sense_Control == RISING_EDGE_SENSE_CONTROL)
				{
					MCU_vEnableInterrupt();
					SET_BIT(MCUCR_REG,MCUCR_REG_ISC01_BITS);
					SET_BIT(MCUCR_REG,MCUCR_REG_ISC00_BITS);
					SET_BIT(GICR_REG,GICR_REG_INT0_BITS);
				}
				break;
			}
			case EXT1_INTERRUPTS:
			{

				if(A_interruptConfig[elementIndex].EXTERNAL_INTERRUPRT_Sense_Control == LOW_LEVEL_SENSE_CONTROL)
				{
					MCU_vEnableInterrupt();
					CLEAR_BIT(MCUCR_REG,MCUCR_REG_ISC11_BITS);
					CLEAR_BIT(MCUCR_REG,MCUCR_REG_ISC10_BITS);
					SET_BIT(GICR_REG,GICR_REG_INT1_BITS);
				}
				else if(A_interruptConfig[elementIndex].EXTERNAL_INTERRUPRT_Sense_Control == ANY_LOGICAL_SENSE_CONTROL)
				{
					MCU_vEnableInterrupt();
					CLEAR_BIT(MCUCR_REG,MCUCR_REG_ISC11_BITS);
					SET_BIT(MCUCR_REG,MCUCR_REG_ISC10_BITS);
					SET_BIT(GICR_REG,GICR_REG_INT1_BITS);
				}
				else if(A_interruptConfig[elementIndex].EXTERNAL_INTERRUPRT_Sense_Control == FALLING_EDGE_SENSE_CONTROL)
				{
					MCU_vEnableInterrupt();
					SET_BIT(MCUCR_REG,MCUCR_REG_ISC11_BITS);
					CLEAR_BIT(MCUCR_REG,MCUCR_REG_ISC10_BITS);
					SET_BIT(GICR_REG,GICR_REG_INT1_BITS);
				}
				else if(A_interruptConfig[elementIndex].EXTERNAL_INTERRUPRT_Sense_Control == RISING_EDGE_SENSE_CONTROL)
				{
					MCU_vEnableInterrupt();
					SET_BIT(MCUCR_REG,MCUCR_REG_ISC11_BITS);
					SET_BIT(MCUCR_REG,MCUCR_REG_ISC10_BITS);
					SET_BIT(GICR_REG,GICR_REG_INT1_BITS);
				}
				break;
			}
			case EXT2_INTERRUPTS:
			{

				if(A_interruptConfig[elementIndex].EXTERNAL_INTERRUPRT_Sense_Control == FALLING_EDGE_SENSE_CONTROL)
				{
					MCU_vEnableInterrupt();
					CLEAR_BIT(MCUCSR_REG,MCUCSR_REG_ISC2_BITS);
					SET_BIT(GICR_REG,GICR_REG_INT2_BITS);
				}
				else if(A_interruptConfig[elementIndex].EXTERNAL_INTERRUPRT_Sense_Control == RISING_EDGE_SENSE_CONTROL)
				{
					MCU_vEnableInterrupt();
					SET_BIT(MCUCSR_REG,MCUCSR_REG_ISC2_BITS);
					SET_BIT(GICR_REG,GICR_REG_INT2_BITS);
				}
				break;
			}
		}
		elementIndex++;
	}
}
void EXT_vINTERRUPT_Denit()
{
	
	Uchar8_t elementIndex = 0;
	
	while(elementIndex < EXT_INTERRUPT_PINS)
	{
		switch(A_interruptConfig[elementIndex].EXTERNAL_INTERRUPRT_Number)
		{
			case EXT0_INTERRUPTS:
			{
				CLEAR_BIT(GICR_REG,GICR_REG_INT0_BITS);
				break;
			}
			case EXT1_INTERRUPTS:
			{
				CLEAR_BIT(GICR_REG,GICR_REG_INT1_BITS);
				break;
			}
			case EXT2_INTERRUPTS:
			{
				CLEAR_BIT(GICR_REG,GICR_REG_INT1_BITS);
				break;
			}
		}
	}
}


static void EXT0_INTERRUPT_SetInterruptHandler(void(*InterruptHandler)(void))
{

	INT0_InterruptHandler = InterruptHandler;

}

static void EXT1_INTERRUPT_SetInterruptHandler(void(*InterruptHandler)(void))
{

	INT1_InterruptHandler = InterruptHandler;

}

static void EXT2_INTERRUPT_SetInterruptHandler(void(*InterruptHandler)(void))
{

	INT2_InterruptHandler = InterruptHandler;
}


void EXT_INTERRUPT_SetInterruptHandler()
{
	Uchar8_t elementIndex = 0;
	while(elementIndex < EXT_INTERRUPT_PINS)
	{
		
		switch(A_interruptConfig[elementIndex].EXTERNAL_INTERRUPRT_Number)
		{
			case EXT0_INTERRUPTS:
			{
				EXT0_INTERRUPT_SetInterruptHandler(A_interruptConfig[elementIndex].INTERRUPT_EXTERNAL_HANDLER);
				break;
			}
			case EXT1_INTERRUPTS:
			{
				EXT1_INTERRUPT_SetInterruptHandler(A_interruptConfig[elementIndex].INTERRUPT_EXTERNAL_HANDLER);
				break;
			}
			case EXT2_INTERRUPTS:
			{
				EXT2_INTERRUPT_SetInterruptHandler(A_interruptConfig[elementIndex].INTERRUPT_EXTERNAL_HANDLER);
				break;
			}
		}
		elementIndex++;
	}
}

void EXT_vINTERRUPT_Init()
{
	EXT_vINTERRUPT_setSenseControl();
	EXT_INTERRUPT_SetInterruptHandler();
}

/*ISR(EXT_INT0)
{
	INT0_InterruptHandler();
}*/
//ISR(EXT_INT1)
//{
	//INT1_InterruptHandler();
//}
//ISR(EXT_INT2)
//{
	//INT2_InterruptHandler();
//}

