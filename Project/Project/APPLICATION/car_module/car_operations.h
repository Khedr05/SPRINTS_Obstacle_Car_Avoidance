/*
 * car_operations.h
 *
 * Created: 16/05/2023 22:27:20
 *  Author: 20101
 */ 


#ifndef CAR_OPERATIONS_H_
#define CAR_OPERATIONS_H_

#include "../../COMMON/std_types.h"
#include "../../ECUAL/lcd/lcd_interface.h"
#include "../../MCAL/timer/timer_interface.h"
#include "../../ECUAL/push_button/PB_interface.h"
#include "../../ECUAL/ultrasonic/ultrasonic_interface.h"
#include "../../ECUAL/keypad/keypad_interface.h"
#include "../../ECUAL/motors/dcm_interface.h"

typedef enum
{
	
	SPEED_0,
	SPEED_30,
	SPEED_50
	
}EN_speed;

typedef enum
{
	
	ROTATION_L,
	ROTATION_R
}EN_Rotation;

typedef enum
{
	
	DIRECTION_F,
	DIRECTION_B,
	DIRECTION_R,
	DIRECTION_S
}EN_direction;
typedef enum
{
	STATE_IDLE,
	SET_DEFAULT_ROTATION,
	CAR_SCANING,
	MORE_THAN_70_CM,
	MORE_THAN_30_CM,
	MORE_THAN_20_CM,
	LESS_THAN_20_CM,
	STOP
	
}EN_carState;



void setDefaultRotation(void);
void LCD_update(EN_speed en_a_speed,EN_direction en_a_direction,float64_t f64_a_distance);
void obstcaleMoreThan70(void);
void obstcaleMoreThan30(void);
void obstcaleMoreThan20(void);
void obstcaleLessThan20(void);
void Car_Stop(void);
#endif /* CAR_OPERATIONS_H_ */