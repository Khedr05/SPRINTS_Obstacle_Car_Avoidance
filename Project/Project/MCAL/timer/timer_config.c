/*
 * timer_cfg.c
 *
 * Created: 4/6/2023 5:33:09 AM
 *  Author: Mahmoud Mowafey
 */
#include "timer_config.h"

/**********************************************************************
* Module Preprocessor Constants
**********************************************************************/
/*********************************************************************
* Module Preprocessor Macros
**********************************************************************/
/**********************************************************************
* Module Typedefs
**********************************************************************/
/**********************************************************************
* Module Variable Definitions
**********************************************************************/
/**
* Defines a table of pointers to the peripheral TCCR register on the
* microcontroller.
*/
/*
static uint8_t volatile * const TmrTCCR_reg[NUMBER_OF_TIMERS] =
{
	 (uint8_t*)TIMER_U8_TCCR0_REG,
	 (uint8_t*)TIMER_U8_TCCR1_REG = TimrTCCR1_reg[0],
	 (uint8_t*)TIMER_U8_TCCR2_REG
};


static uint8_t volatile * const TimrTCCR1_reg[2] =
{
	 (uint8_t*)TIMER_U8_TCCR1A_REG,
	 (uint8_t*)TIMER_U8_TCCR1B_REG
};*/
/**********************************************************************/
/**
* Defines a table of pointers to the peripheral TCNT register on the
* microcontroller.
*/
/*static uint8_t volatile * const TmrTCNT_reg[NUMBER_OF_PORTS] =
{
	 (uint8_t*)TMR_U8_TCNT0_REG,
	 (uint8_t*)TMR_U8_TCNT1_REG,
	 (uint8_t*)TMR_U8_TCNT2_REG
};*/
/**********************************************************************/
/**
* Defines a table of pointers to the peripheral TCCR register on the
* microcontroller.
*/
/*static uint8_t volatile * const TmrTCCR_reg[NUMBER_OF_PORTS] =
{
	 (uint8_t*)PINA,
	 (uint8_t*)PINB,
	 (uint8_t*)PINC,
	 (uint8_t*)PIND
};*/
/**********************************************************************/
/**
* Defines a table of pointers to the peripheral TCCR register on the
* microcontroller.
*/
/*static uint8_t volatile * const TmrTCCR_reg[NUMBER_OF_PORTS] =
{
	 (uint8_t*)PINA,
	 (uint8_t*)PINB,
	 (uint8_t*)PINC,
	 (uint8_t*)PIND
};*/

// uint8_t volatile *const tmrReg[NUM_TIMERS] =
//         {
//                 (uint8_t*)TIMER_U8_TCCR_REG,    /*Timer/Counter Control Register*/
//                 (uint8_t*)TIMER_U8_TCNT_REG,    /*Timer/Counter Register*/
//                 (uint8_t*)TIMER_U8_OCR_REG,     /* Output Compare Register*/
//                 (uint8_t*)TIMER_U8_TIMSK_REG,  /*Timer/Counter Interrupt Mask Register*/
//                 (uint8_t*)TIMER_U8_TIFR_REG,   /*Timer/Counter Interrupt Flag Register*/
//                // (uint8_t*)&SFIOR,  /* PSR10: Prescaler Reset Timer/Counter1 and Timer/Counter0*/
//         };

const TimerConfig_t TimerConfig[]=
{
    {  TIMER0, TMR_DISABLED,  TMR_OVERFLOW_MODE, TMR_NORMAL_PORT_OPERATION_OC_PIN_DISCONNECTED,  TMR_INTERNAL,  TMR_MODULE_CLK, TMR_CLK_1024_FROM_PRESCALER, TMR_ISR_ENABLED },
    {  TIMER1, TMR_DISABLED,  TMR_OVERFLOW_MODE, TMR_NORMAL_PORT_OPERATION_OC_PIN_DISCONNECTED,  TMR_INTERNAL,  TMR_MODULE_CLK, TMR_CLK_1024_FROM_PRESCALER, TMR_ISR_ENABLED },
    {  TIMER2, TMR_DISABLED,  TMR_OVERFLOW_MODE, TMR_NORMAL_PORT_OPERATION_OC_PIN_DISCONNECTED,  TMR_INTERNAL,  TMR_MODULE_CLK, TMR_CLK_1024_FROM_PRESCALER, TMR_ISR_ENABLED }
};




