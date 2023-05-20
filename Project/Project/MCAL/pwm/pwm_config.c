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
		PIND4
	},
	{
		PIND5
	}
};