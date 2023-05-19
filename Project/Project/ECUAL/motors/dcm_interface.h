 /*
  * DCM_Interface.h
  *
  *     Created on: Apr 11, 2023
  *         Author: Mahmoud Mowafey - https://github.com/Mahmoud-Mowafy
  *    Description: This file contains all Direct Current Motor (DCM) functions' prototypes and definitions (Macros) to avoid magic numbers.
  *		MCU Datasheet: AVR ATmega32 - https://ww1.microchip.com/downloads/en/DeviceDoc/Atmega32A-DataSheet-Complete-DS40002072A.pdf
  */

#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_

/*******************************************************************************************************************************************************************/
/* DCM Includes */

/* LIB */
#include "../../COMMON/bit_math.h"
#include "../../COMMON/std_types.h"

/* MCAL */
#include "../../MCAL/dio/dio.h"
#include "../../MCAL/timer/timer_interface.h"
#include "dcm_cfg.h"

/*******************************************************************************************************************************************************************/
/* DCM Macros */
/*******************************************************************************************************************************************************************/
/* DCM Macros */
#define MOTORS_NUMBER                 2
#define ZERO_SPEED					          0
#define MAX_DUTY_CYCLE			          100
#define PERIOD_TIME					          10
#define ROTATION_DUTY_CYCLE           50

/*type definition*/

typedef enum {
	DCM_OK,
	DCM_ERROR
}EN_DCM_ERROR_T;

typedef enum {
	MOTOR_RIGHT,
	MOTOR_LEFT
}EN_DCM_MOTORSIDE;

typedef enum {
	FALSE,
	TRUE
}EN_DCM_FLAG;



extern ST_DCM_g_Config_t ST_g_carMotors[2];
/*******************************************************************************************************************************************************************/
/* DCM Functions' Prototypes */

EN_DCM_ERROR_T DCM_rotateDCM(EN_DCM_MOTORSIDE DCM_l_motorNumber, u16 DCM_a_rotateSpeed);

EN_DCM_ERROR_T DCM_changeDCMDirection(ST_DCM_g_Config_t* DCM_a_ptrToConfig, EN_DCM_MOTORSIDE DCM_a_motorNum);

EN_DCM_ERROR_T DCM_u8SetDutyCycleOfPWM(u8 DCM_a_dutyCycleValue);

void DCM_vdStopDCM(void);

EN_DCM_ERROR_T DCM_motorInit(ST_DCM_g_Config_t* DCM_a_ptrToConfig);

void DCM_updateStopFlag(void);
void DCM_MoveForward(u8 u8_a_speed);
void DCM_MoveBackward(u8 u8_a_speed);

//u8 DCM_u8GetDutyCycleOfPWM(u8* Cpy_pu8ReturnedDutyCycleValue);
/**************************************************************************************************************************************************************************/

/*******************************************************************************************************************************************************************/

#endif /* DCM_INTERFACE_H_ */