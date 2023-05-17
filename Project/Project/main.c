/*
 * Project.c
 *
 * Created: 16/05/2023 22:19:20
 * Author : 20101
 */ 

#include "ECUAL/ultrasonic/ultrasonic_interface.h"
#include "lcd_test/lcd_interface.h"
#include "COMMON/STD_Types.h"
#include <util/delay.h>


void main(void)
{
	float64_t dis = 0; 
	HLCD_vidInit();
	ultrasonic_vInit();
	ultrasonic_vGetDistance(&dis);
	HLCD_WriteInt(dis);
	while(1)
	{
		ultrasonic_vGetDistance(&dis);
		HLCD_WriteInt(dis);
		_delay_ms(2000);
		HLCD_ClrDisplay();
		
	}
}

