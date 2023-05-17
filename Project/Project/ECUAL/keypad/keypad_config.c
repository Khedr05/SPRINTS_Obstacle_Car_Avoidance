/*
 * keypad_config.c
 *
 * Created: 5/16/2023 3:23:52 PM
 *  Author: Sharpel
 */ 


#include "../../COMMON/std_types.h"
#include "../../MCAL/dio/dio.h"
#include "keypad_config.h"





/* variable of type keypad configs to set our configuration */
const ST_KEYPAD_CONFIG st_keypad_conf =
{
    .u8_arr_cols = 
	{
		{
			.dio_port = KEPAD_PORT,
			.dio_pin  = C1,
			.dio_mode = DIO_MODE_INPUT,
			.dio_initial_value  = DIOINPUT_PULLUP,
			
		},
		{
			.dio_port = KEPAD_PORT,
			.dio_pin  = C2,
			.dio_mode = DIO_MODE_INPUT,
		    .dio_initial_value  = DIOINPUT_PULLUP,
			
		}
	},
	
	.u8_arr_rows = 
	{
		{
			.dio_port = KEPAD_PORT,
			.dio_pin  = R1,
			.dio_mode = DIO_MODE_OUTPUT,
			.dio_initial_value  = DIO_HIGH,
			.dio_pullup_resistor = DIO_PULLUP_DISABLED
			
		},
	},
	.u8_arr_keys =
	{
		{
			KEY_1 , KEY_2
		}
	}
};
	
	
	