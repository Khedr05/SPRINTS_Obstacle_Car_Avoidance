/*
 * app.c
 *
 * Created: 16/05/2023 22:26:51
 *  Author: 20101
 */ 

#define F_CPU 1000000UL
#include <util/delay.h>
#include "apph.h"

extern EN_carState en_g_state;
extern float64_t f64_g_obstcaleDistance;
extern Uchar8_t u8_g_moreThan70Flag;
extern Uchar8_t u8_g_lessThan20Flag;
EN_KEYPAD_KEYS keyState = KEY_NOTHING;
Uchar8_t u8_g_startFlag = 0;
Uchar8_t u8_g_stopFlag = 0;

void app_init()
{
	ultrasonic_vInit();
	LCD_Init();
	PUSH_BTN_intialize();
	TIMER_TMR2NormalModeInit(ENABLED);
	KEYPAD_init();
	DCM_motorInit(ST_g_carMotors);
}

void app_main()
{
	keyState = KEYPAD_getButton();
	if(keyState == KEY_1 && u8_g_startFlag==0)
	{
	
	     en_g_state = SET_DEFAULT_ROTATION;
		 u8_g_startFlag = 1;
	}
	else if(keyState == KEY_2)
	{ 
		en_g_state = STOP;
	}
	
	else if(keyState == KEY_1 && u8_g_startFlag == 1)
	{
		en_g_state = CAR_SCANING;
	}
	
	
	switch(en_g_state)
	{
		case SET_DEFAULT_ROTATION :
		{
			setDefaultRotation();
			en_g_state = CAR_SCANING;
			break;
		}
		case CAR_SCANING :
		{
			
			ultrasonic_vGetDistance(&f64_g_obstcaleDistance);
			if(f64_g_obstcaleDistance > 70)
			{
				en_g_state = MORE_THAN_70_CM;
			}
			else if(f64_g_obstcaleDistance <= 70 && f64_g_obstcaleDistance > 30)
			{
				en_g_state = MORE_THAN_30_CM;
			}
			else if(f64_g_obstcaleDistance <= 30 && f64_g_obstcaleDistance > 20)
			{
				en_g_state = MORE_THAN_20_CM;
			}
			else if(f64_g_obstcaleDistance < 20)
			{
				en_g_state = LESS_THAN_20_CM;
			}
			
			break;
		}
		case MORE_THAN_70_CM :
		{
			u8_g_lessThan20Flag = 0;
			obstcaleMoreThan70();
			en_g_state = CAR_SCANING;
			break;
		}
		case MORE_THAN_30_CM:
		{
			u8_g_moreThan70Flag = 0;
			u8_g_lessThan20Flag = 0;
			obstcaleMoreThan30();
			en_g_state = CAR_SCANING;
			break;
		}
		
		case MORE_THAN_20_CM:
		{
			u8_g_moreThan70Flag = 0;
			u8_g_lessThan20Flag = 0;
			obstcaleMoreThan20();
			en_g_state = CAR_SCANING;
			break;
		}
		
		
		case LESS_THAN_20_CM:
		{
			u8_g_moreThan70Flag = 0;
			obstcaleLessThan20();
			en_g_state = CAR_SCANING;
			break;
		}
		
		
		case STOP:
		{
			Car_Stop();
			break;
		}
		
		case STATE_IDLE:
		{
			LCD_update_stop();
			break;
		}
	}
	
}