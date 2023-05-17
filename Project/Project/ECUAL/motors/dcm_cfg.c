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
#include "DCM_private.h"
#include "dcm_cfg.h"

/*******************************************************************************************************************************************************************/
/* Declaration and Initialization */


ST_DCM_g_Config_t ST_g_carMotors[2] =
{
	{  	 MOT0_EN_PIN_NUMBER_0 ,  MOT0_EN_PIN_NUMBER_1, MOT0_PWM_PIN_NUMBER, MOT0_EN_PORT_NUMBER, MOT0_PWM_PORT_NUMBER},
	{  	 MOT1_EN_PIN_NUMBER_0,  MOT1_EN_PIN_NUMBER_1, MOT1_PWM_PIN_NUMBER, MOT1_EN_PORT_NUMBER, MOT1_PWM_PORT_NUMBER}
};


/*******************************************************************************************************************************************************************/
/****************************************************************************************************************************************/