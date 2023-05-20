/*
 * DCM_Program.c
 *
 *     Created on: Apr 11, 2023
 *         Author: Mahmoud Mowafey - https://github.com/Mahmoud-Mowafy
 *  Description: This file contains all Direct Current Motor (DCM) functions' implementation.
 *		MCU Datasheet: AVR ATmega32
 *                  https://ww1.microchip.com/downloads/en/DeviceDoc/Atmega32A-DataSheet-Complete-DS40002072A.pdf
 */




 /* HAL */
#include "dcm_cfg.h"
#include "dcm_interface.h"
#include "../../MCAL/pwm/pwm_interface.h"
#include "../../MCAL/timer/timer_interface.h"

/*******************************************************************************************************************************************************************/
/* Declaration and Initialization */

EN_DCM_FLAG DCM_g_stopFlag = FALSE;

extern Uchar8_t u8_g_timeOut;
/*******************************************************************************************************************************************************************/

EN_DCM_ERROR_T DCM_motorInit(ST_DCM_g_Config_t* DCM_a_ptrToConfig)
{
	if (DCM_a_ptrToConfig == NULL)
		return DCM_ERROR;
	else
	{
		Uchar8_t u8_a_loopCounter;
		for (u8_a_loopCounter = 0; u8_a_loopCounter < MOTORS_NUMBER; u8_a_loopCounter++)
		{
		
			DIO_InitDCM(DCM_a_ptrToConfig[u8_a_loopCounter].DCM_g_motEnPinNumber0,
				DCM_a_ptrToConfig[u8_a_loopCounter].DCM_g_motEnPortNumber,
				DIO_MODE_OUTPUT);
			DIO_InitDCM(DCM_a_ptrToConfig[u8_a_loopCounter].DCM_g_motEnPinNumber1,
				DCM_a_ptrToConfig[u8_a_loopCounter].DCM_g_motEnPortNumber,
				DIO_MODE_OUTPUT);
		}

	}
	TIMER0_initPWM();
}

/*******************************************************************************************************************************************************************/
EN_DCM_ERROR_T DCM_changeDCMDirection(ST_DCM_g_Config_t* DCM_a_ptrToConfig, EN_DCM_MOTORSIDE DCM_a_motorNum)
{
	if (DCM_a_ptrToConfig == NULL)
		return DCM_ERROR;
	else
	{

		DIO_toggle( DCM_a_ptrToConfig[DCM_a_motorNum].DCM_g_motEnPortNumber,
					DCM_a_ptrToConfig[DCM_a_motorNum].DCM_g_motEnPinNumber0
		);
		
		
	}
	return DCM_OK;
}
/****************************************************************************************************************************************/

void DCM_vdStopDCM(void)
{
	DIO_WritePin( DIO_PORTC, 0 , DIO_LOW);
	DIO_WritePin( DIO_PORTC, 1 , DIO_LOW);
	TIMER0_stop();
}

/************************************************************************************************************************************/

EN_DCM_ERROR_T DCM_u8SetDutyCycleOfPWM(Uchar8_t DCM_a_dutyCycleValue)
{

	if (DCM_a_dutyCycleValue > MAX_DUTY_CYCLE)
		return DCM_ERROR;
	else
	{
		TIMER0_setPwm(DCM_a_dutyCycleValue);
	}
}

/****************************************************************************************************************************************/
void DCM_updateStopFlag(void)
{
	DCM_g_stopFlag = TRUE;
}
/****************************************************************************************************************************************/
/* you need to specify which motor you want to rotate*/
EN_DCM_ERROR_T DCM_rotateDCM(EN_DCM_MOTORSIDE DCM_l_motorNumber, Uint16_t DCM_a_rotateSpeed)
{
	
	if(DCM_l_motorNumber == MOTOR_RIGHT)
	{
		DCM_changeDCMDirection(ST_g_carMotors, MOTOR_RIGHT);
		// High delay to see it on simulation
		TMR_intDelay_ms(620);
		DCM_u8SetDutyCycleOfPWM(ROTATION_DUTY_CYCLE);
		while(u8_g_timeOut == 0);
		TIMER0_stop();
		u8_g_timeOut = 0;
		DCM_changeDCMDirection(ST_g_carMotors, MOTOR_RIGHT);	
	}
	else
	{
		DCM_changeDCMDirection(ST_g_carMotors, MOTOR_LEFT);
		TMR_intDelay_ms(620);
		DCM_u8SetDutyCycleOfPWM(ROTATION_DUTY_CYCLE);
		while(u8_g_timeOut == 0);
		TIMER0_stop();
		u8_g_timeOut = 0;
		DCM_changeDCMDirection(ST_g_carMotors, MOTOR_LEFT);		
	}

}

/****************************************************************************************************************************************/

void DCM_MoveForward(Uchar8_t u8_a_speed)
{
	DCM_u8SetDutyCycleOfPWM(u8_a_speed);
	DIO_WritePin(ST_g_carMotors[0].DCM_g_motEnPortNumber,ST_g_carMotors[0].DCM_g_motEnPinNumber0,DIO_HIGH);
	DIO_WritePin(ST_g_carMotors[0].DCM_g_motEnPortNumber,ST_g_carMotors[0].DCM_g_motEnPinNumber1,DIO_LOW);
	DIO_WritePin(ST_g_carMotors[1].DCM_g_motEnPortNumber,ST_g_carMotors[1].DCM_g_motEnPinNumber0,DIO_HIGH);
	DIO_WritePin(ST_g_carMotors[1].DCM_g_motEnPortNumber,ST_g_carMotors[1].DCM_g_motEnPinNumber1,DIO_LOW);
}


void DCM_MoveBackward(Uchar8_t u8_a_speed)
{
	DCM_u8SetDutyCycleOfPWM(u8_a_speed);
	DIO_WritePin(ST_g_carMotors[0].DCM_g_motEnPortNumber,ST_g_carMotors[0].DCM_g_motEnPinNumber0,DIO_LOW);
	DIO_WritePin(ST_g_carMotors[0].DCM_g_motEnPortNumber,ST_g_carMotors[0].DCM_g_motEnPinNumber1,DIO_HIGH);
	DIO_WritePin(ST_g_carMotors[1].DCM_g_motEnPortNumber,ST_g_carMotors[1].DCM_g_motEnPinNumber0,DIO_LOW);
	DIO_WritePin(ST_g_carMotors[1].DCM_g_motEnPortNumber,ST_g_carMotors[1].DCM_g_motEnPinNumber1,DIO_HIGH);
}