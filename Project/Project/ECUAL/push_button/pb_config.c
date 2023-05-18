/*
* pb_config.c
*
* Created: 17/05/2023 14:04:34
*  Author: 20101
*/

#include "PB_config.h"

const ST_PUSH_BTN_t A_pbConfig[NUMBER_OF_PUSH_BUTTONS] =
{
	{
		.PUSH_BTN_pin.dio_mode = DIO_MODE_INPUT,
		.PUSH_BTN_pin.dio_pin = DIO_PIN4,
		.PUSH_BTN_pin.dio_port = DIO_PORTC,
		.PUSH_BTN_pin.dio_initial_value = DIO_HIGH,
		.PUSH_BTN_pin.dio_pullup_resistor = DIO_PULLUP_ENABLED,
		.PUSH_BTN_connection = PUSH_BTN_PULL_UP,
		.PUSH_BTN_state = PUSH_BTN_STATE_RELEASED
	}
};