/*
 * ICU.c
 *
 * Created: 5/16/2023 8:24:35 PM
 *         Author: Mahmoud Mowafey - https://github.com/Mahmoud-Mowafy
 *  Description: This file contains all Direct Current Motor (DCM) functions' implementation.
 *		MCU Datasheet: AVR ATmega32
 *                  https://ww1.microchip.com/downloads/en/DeviceDoc/Atmega32A-DataSheet-Complete-DS40002072A.pdf
 */ 

#include "ICU.h"



Uint32_t TIMER_g_timer1RegValue = 0;
Uint32_t u32_g_timer1Overflow = 0;

Uint32_t ICU_g_ValueRising = 0;
Uint32_t ICU_g_ValueFalling = 0;

Uchar8_t ICU_g_flag = 0; 
Uint32_t ICU_g_Count = 0;
EN_icuEdgeFlag ICU_g_edgeFlag;
/**
 * @brief function enable timer1 in normal mode.
 *
 * @param[in] void.
 *
 * @return void.
 */
// void ICU_init(void)
// {
// 	TIMER_tmr1NormalModeInit(ST_g_softwareICU->timer1_ISR);
// }

/**
 * @brief function enables timer1 in normal mode and sets the external interrupt event at rising edge.
 *
 * @param[in] void.
 *
 * @return void.
 */
void ICU_RisingEdgeCapture(void)
{
	TIMER_tmr1NormalModeInit(ST_g_softwareICU->timer1_ISR);
	TIMER_tmr1Stop();
	
	EXI_enablePIE( ST_g_softwareICU->ICU_exti, ST_g_softwareICU->ICU_firstSenseControl);
	ICU_g_edgeFlag = RISING;
	TIMER_tmr1Start(1);
}
 
 
void ICU_getValue(Uint32_t *u32_l_ICR_value)
{
	*u32_l_ICR_value = ICU_g_Count;
}
/**
 * @brief function sets the external interrupt event at falling edge.
 *
 * @param[in] void.
 *
 * @return void.
 */
/*
void ICU_FallingEdgeCapture(void)
{
	EXI_enablePIE( ST_g_softwareICU->ICU_exti, ST_g_softwareICU->ICU_secondSenseControl );
}*/



/**
 * @brief The function enables a specific external interrupt with a specified sense control.
 *
 * @param[in] u8_a_interruptId This is an input parameter of type Uchar8_t (unsigned 8-bit integer) that specifies the interrupt ID.
 * 			  It can have one of three values: EXI_U8_INT0, EXI_U8_INT1, or EXI_U8_INT2, which correspond to external interrupt,
 * @param[in] u8_a_senseControl This parameter is used to specify the sense control of the external interrupt.
 * 			  It can take one of the following values:
 *
 * @return void
 */

void EXI_enablePIE( Uchar8_t u8_a_interruptId, Uchar8_t u8_a_senseControl )
{

        SET_BIT(TIMER_U8_SREG_REG, GLOBAL_INTERRUPT_ENABLE_BIT);

        SET_BIT( EXI_U8_GICR_REG, EXI_U8_INT2_BIT );

                /* Check 1.1.1: Required SenseControl */
                switch ( u8_a_senseControl )
                {
                    //case EXI_U8_SENSE_LOW_LEVEL		: CLEAR_BIT( EXI_U8_MCUCR_REG, EXI_U8_ISC00_BIT ); CLEAR_BIT( EXI_U8_MCUCR_REG, EXI_U8_ISC01_BIT ); break;
                   // case EXI_U8_SENSE_LOGICAL_CHANGE: SET_BIT( EXI_U8_MCUCR_REG, EXI_U8_ISC00_BIT ); CLEAR_BIT( EXI_U8_MCUCR_REG, EXI_U8_ISC01_BIT ); break;
                    case EXI_U8_SENSE_FALLING_EDGE	: CLEAR_BIT( EXI_U8_MCUCSR_REG, 6 ); break;
                    case EXI_U8_SENSE_RISING_EDGE	: SET_BIT( EXI_U8_MCUCSR_REG, 6 );  break;
                }
}



/* ************************************************************************************************/

/**
 * @brief Initializes timer1 at normal mode
 *
 * This function initializes/selects the timer_1 normal mode for the timer, and enable the ISR for this timer.
 * @param[in] EN_TMR_INTERRPUT_T en_a_interrputEnable value to set the interrupt bit for timer_1 in the TIMSK reg.
 *
 * @return An EN_TMR_ERROR_T value indicating the success or failure of the operation
 *         (TMR_OK if the operation succeeded, TMR_ERROR otherwise)
 */
EN_TIMER_ERROR_T TIMER_tmr1NormalModeInit(EN_TIMER_INTERRPUT_T en_a_interrputEnable)
{
	switch (en_a_interrputEnable)
	{
	case ENABLED:
		//* select the normal mode for the timer, timer is not start yet.*//*
		CLEAR_BIT(TMR_U8_TCCR1A_REG, TMR_U8_WGM10_BIT);
		CLEAR_BIT(TMR_U8_TCCR1A_REG, TMR_U8_WGM11_BIT);
		CLEAR_BIT(TMR_U8_TCCR1B_REG, TMR_U8_WGM12_BIT);
		CLEAR_BIT(TMR_U8_TCCR1B_REG, TMR_U8_WGM13_BIT);
		//*must be set for the non_PWM mode*//*
		SET_BIT(TMR_U8_TCCR1A_REG, TMR_U8_FOC1A_BIT);
		SET_BIT(TMR_U8_TCCR1A_REG, TMR_U8_FOC1B_BIT);
		//*Enable the global interrupt enable bit.*//*
		SET_BIT(TMR_U8_SREG_REG, GLOBAL_INTERRUPT_ENABLE_BIT);
		//* Enable the interrupt for timer0 overflow.*//*
		SET_BIT(TMR_U8_TIMSK_REG, TMR_U8_TOIE1_BIT);
		break;
	case DISABLED:
		//* select the normal mode for the timer, timer is not start yet.*//*
		CLEAR_BIT(TMR_U8_TCCR1A_REG, TMR_U8_WGM10_BIT);
		CLEAR_BIT(TMR_U8_TCCR1A_REG, TMR_U8_WGM11_BIT);
		CLEAR_BIT(TMR_U8_TCCR1B_REG, TMR_U8_WGM12_BIT);
		CLEAR_BIT(TMR_U8_TCCR1B_REG, TMR_U8_WGM13_BIT);
		//*must be set for the non_PWM mode*//*
		SET_BIT(TMR_U8_TCCR1A_REG, TMR_U8_FOC1A_BIT);
		SET_BIT(TMR_U8_TCCR1A_REG, TMR_U8_FOC1B_BIT);
		break;
	default:
		return TIMER_ERROR;
	}
	return TIMER_OK;
}

/* ********************************************************************************************************************/

/* *******************************************************************************************/
/**
 * @brief Start the timer by setting the desired prescaler.
 *
 * This function set the prescaler for timer_1.
 * @param[in] Uint16_t u16_a_prescaler value to set the desired prescaler.
 *
 * @return An EN_TMR_ERROR_T value indicating the success or failure of the operation
 *         (TMR_OK if the operation succeeded, TMR_ERROR otherwise)
 */
EN_TIMER_ERROR_T TIMER_tmr1Start(Uint16_t u16_a_prescaler)
{
	//select the required prescaler value
	switch(u16_a_prescaler)
	{
	case 1:
		CLEAR_BIT(TMR_U8_TCCR1B_REG, TMR_U8_CS11_BIT);
		CLEAR_BIT(TMR_U8_TCCR1B_REG, TMR_U8_CS12_BIT);
		SET_BIT(TMR_U8_TCCR1B_REG, TMR_U8_CS10_BIT);
		break;
	case 8:
		CLEAR_BIT(TMR_U8_TCCR1B_REG, TMR_U8_CS10_BIT);
		CLEAR_BIT(TMR_U8_TCCR1B_REG, TMR_U8_CS12_BIT);
		SET_BIT(TMR_U8_TCCR1B_REG, TMR_U8_CS11_BIT);
		break;
	case 64:
		CLEAR_BIT(TMR_U8_TCCR1B_REG, TMR_U8_CS12_BIT);
		SET_BIT(TMR_U8_TCCR1B_REG, TMR_U8_CS11_BIT);
		SET_BIT(TMR_U8_TCCR1B_REG, TMR_U8_CS10_BIT);
		break;
	case 256:
		CLEAR_BIT(TMR_U8_TCCR1B_REG, TMR_U8_CS11_BIT);
		CLEAR_BIT(TMR_U8_TCCR1B_REG, TMR_U8_CS10_BIT);
		SET_BIT(TMR_U8_TCCR1B_REG, TMR_U8_CS12_BIT);
		break;
	case 1024:
		CLEAR_BIT(TMR_U8_TCCR1B_REG, TMR_U8_CS11_BIT);
		SET_BIT(TMR_U8_TCCR1B_REG, TMR_U8_CS12_BIT);
		SET_BIT(TMR_U8_TCCR1B_REG, TMR_U8_CS10_BIT);
		break;
	default:
		return TIMER_ERROR;
	}
	return TIMER_OK;
}
/* ************************************************************************************************/

void TIMER_tmr1Stop(void)
{
 //Stop the timer by clearing the prescaler

	CLEAR_BIT(TMR_U8_TCCR1B_REG, TMR_U8_CS10_BIT);
	CLEAR_BIT(TMR_U8_TCCR1B_REG, TMR_U8_CS11_BIT);
	CLEAR_BIT(TMR_U8_TCCR1B_REG, TMR_U8_CS12_BIT);
}



	
/**
 * ISR function implementation of INT2
 * */
ISR(EXT_INT_2)
{
    /* Save the current value of the timer/counter register  */
	TIMER_g_timer1RegValue = TMR_U16_TCNT1_REG;
	if(ICU_g_edgeFlag == RISING)
	{
		ICU_g_ValueRising = TIMER_g_timer1RegValue;
		/* Clear Timer counter */
		TMR_U16_TCNT1_REG = 0;
		/* Set the external interrupt event at falling edge.*/
		EXI_enablePIE( ST_g_softwareICU->ICU_exti, ST_g_softwareICU->ICU_secondSenseControl );
		/* Clear Timer overflow count */
		u32_g_timer1Overflow = 0;
		ICU_g_edgeFlag = FALLING;
	}
	else
	{
		ICU_g_ValueFalling = TIMER_g_timer1RegValue;
		ICU_g_Count = TIMER_g_timer1RegValue + (65535 * u32_g_timer1Overflow);
		/* Stop timer1 */
		TIMER_tmr1Stop();
		ICU_g_flag = 1;
	}

}	
		
ISR(TIM1_OVF_INT)
{
	u32_g_timer1Overflow++;
}		