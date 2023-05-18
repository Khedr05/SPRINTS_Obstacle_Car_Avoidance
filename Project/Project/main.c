/*
 * Project.c
 *
 * Created: 16/05/2023 22:19:20
 * Author : 20101
 */ 

#include "APPLICATION/app/apph.h"


void main(void)
{
	//float64_t val;
	app_init();
	while(1)
	{
// 			ultrasonic_vGetDistance(&val);
// 			HLCD_WriteInt(val);
// 			_delay_ms(1000);
// 			HLCD_ClrDisplay();
		app_main();
		
	}
}

