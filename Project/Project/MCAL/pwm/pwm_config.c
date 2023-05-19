/*
 * pwm_config.c
 *
 * Created: 5/17/2023 4:56:24 PM
 *  Author: Sharpel
 */ 

#include "../../COMMON/std_types.h"
#include "../dio/dio.h"
#include "pwm_config.h"

const ST_PWM_PINS_CONFIGS st_pwm_configs[PWM_PINS_NUMBER] =
{
	{
		.pwm_pin.dio_port = DIO_PORTD,
		.pwm_pin.dio_pin  = DIO_PIN4,
		.pwm_pin.dio_mode = DIO_MODE_OUTPUT,
		.pwm_pin.dio_initial_value  = DIO_HIGH,
		.pwm_pin.dio_pullup_resistor = DIO_PULLUP_DISABLED
	},
	{
		.pwm_pin.dio_port = DIO_PORTD,
		.pwm_pin.dio_pin  = DIO_PIN5,
		.pwm_pin.dio_mode = DIO_MODE_OUTPUT,
		.pwm_pin.dio_initial_value  = DIO_HIGH,
		.pwm_pin.dio_pullup_resistor = DIO_PULLUP_DISABLED
	}
};