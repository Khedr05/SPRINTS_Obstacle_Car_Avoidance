/*
 * ultrasonic.c
 *
 * Created: 17/05/2023 18:44:19
 *  Author: 20101
 */ 

#include "ultrasonic_interface.h"

#include <util/delay.h>

extern Uchar8_t ICU_g_flag;

static ST_ultrasonicPins ultra = 
{
	
	.triggerpin = 
	{
		.dio_port = DIO_PORTB,
		.dio_pin = DIO_PIN3,
		.dio_mode = DIO_MODE_OUTPUT,
		.dio_initial_value = DIO_LOW,
		.dio_pullup_resistor = DIO_PULLUP_DISABLED
	}
};

void ultrasonic_vInit()
{
	
	
	DIO_Initpin(&(ultra.triggerpin));
	MCU_vEnableInterrupt();
}

void ultrasonic_vGetDistance(float64_t *Copy_f64distance)
{
	
	
	Uint32_t val = 0;
	DIO_WritePin(DIO_PORTB,DIO_PIN3,DIO_HIGH);

	_delay_ms(10);
	
	DIO_WritePin(DIO_PORTB,DIO_PIN3,DIO_LOW);
	ICU_RisingEdgeCapture();

	
	while(ICU_g_flag != 1);
	ICU_getValue(&val);

	*Copy_f64distance = ((float)val / 466.47*8)+1;	
	ICU_g_flag = 0;
}

