/*
 * car_operations.h
 *
 * Created: 16/05/2023 22:27:20
 *  Author: 20101
 */ 


#ifndef CAR_OPERATIONS_H_
#define CAR_OPERATIONS_H_

#include "../../COMMON/std_types.h"
#include "../../lcd_test/lcd_interface.h"
#include "../../MCAL/timer/timer_interface.h"
#include "../../ECUAL/push_button/PB_interface.h"
#include "../../ECUAL/ultrasonic/ultrasonic_interface.h"

typedef enum
{
	
	SPEED_0,
	SPEED_30,
	SPEED_50
	
}EN_speed;

typedef enum
{
	
	DIRECTION_F,
	DIRECTION_B,
	DIRECTION_L,
	DIRECTION_R
}EN_direction;

typedef enum
{
	
	SET_DEFAULT_ROTATION,
	CAR_SCANING,
	MORE_THAN_70_CM,
	MORE_THAN_30_CM,
	MORE_THAN_20_CM,
	LESS_THAN_20_CM,
	
}EN_carState;

void setDefaultRotation(void);



void obstcaleMoreThan70(void);
#endif /* CAR_OPERATIONS_H_ */