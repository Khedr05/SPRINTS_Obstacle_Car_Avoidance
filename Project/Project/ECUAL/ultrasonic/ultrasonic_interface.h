/*
 * ultrasonic_interface.h
 *
 * Created: 17/05/2023 18:44:42
 *  Author: 20101
 */ 


#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_

#include "../../COMMON/STD_Types.h"
#include "../../MCAL/icu/ICU.h"
#include "../../MCAL/dio/dio.h"
#include "../../MCAL/mcu_cfg/MCU_Interface.h"



typedef struct 
{
	DIO_ConfigType triggerpin;
	DIO_ConfigType echopin;
}ST_ultrasonicPins;


void ultrasonic_vInit(void);
void ultrasonic_vGetDistance(float64_t *Copy_f64distance);




#endif /* ULTRASONIC_INTERFACE_H_ */