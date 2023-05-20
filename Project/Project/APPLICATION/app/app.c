/*
 * app.c
 *
 * Created: 16/05/2023 22:26:51
 *  Author: 20101
 */ 

#define F_CPU 1000000UL
#include <util/delay.h>
#include "apph.h"

extern EN_carState state;
extern float64_t obstcaleDistance;
extern Uchar8_t moreThan70Flag;
extern Uchar8_t lessThan20Flag;
extern Uchar8_t moreThan30Flag;
extern Uchar8_t u8_g_rot360Flag;
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
	
	     state = SET_DEFAULT_ROTATION;
		 u8_g_startFlag = 1;
	}
	else if(keyState == KEY_2 && u8_g_startFlag == 1)
	{ 
		state = STOP;
	}
	
	else if(keyState == KEY_1 && u8_g_startFlag == 1)
	{
		state = CAR_SCANING;
	}
	
	
	switch(state)
	{
		case SET_DEFAULT_ROTATION :
		{
			setDefaultRotation();
			state = CAR_SCANING;
			break;
		}
		case CAR_SCANING :
		{
			
			ultrasonic_vGetDistance(&obstcaleDistance);
			if(obstcaleDistance > 70)
			{
				state = MORE_THAN_70_CM;
			}
			else if(obstcaleDistance <= 70 && obstcaleDistance > 30)
			{
				state = MORE_THAN_30_CM;
			}
			else if(obstcaleDistance <= 30 && obstcaleDistance > 20)
			{
				state = MORE_THAN_20_CM;
			}
			else if(obstcaleDistance < 20)
			{
				state = LESS_THAN_20_CM;
			}
			
			break;
		}
		case MORE_THAN_70_CM :
		{
			lessThan20Flag = 0;
			moreThan30Flag = 0;
			u8_g_rot360Flag=0;
			obstcaleMoreThan70();
			state = CAR_SCANING;
			break;
		}
		case MORE_THAN_30_CM:
		{
			moreThan70Flag = 0;
			lessThan20Flag = 0;
			u8_g_rot360Flag=0;
			obstcaleMoreThan30();
			state = CAR_SCANING;
			break;
		}
		
		case MORE_THAN_20_CM:
		{
			moreThan70Flag = 0;
			lessThan20Flag = 0;
			moreThan30Flag = 0;
			obstcaleMoreThan20();
			state = CAR_SCANING;
			break;
		}
		
		
		case LESS_THAN_20_CM:
		{
			moreThan30Flag = 0;
			moreThan70Flag = 0;
			obstcaleLessThan20();
			state = CAR_SCANING;
			break;
		}
		
		
		case STOP:
		{
			moreThan70Flag = 0;
			lessThan20Flag = 0;
			moreThan30Flag = 0;
			Car_Stop();
			break;
		}
		
		case STATE_IDLE:
		{
			LCD_SetCursor(0,0);
			LCD_WriteString((Uchar8_t*)"Press Key 1");
			LCD_SetCursor(1,0);
			LCD_WriteString((Uchar8_t*)"to start");
			break;
		}
	}
	
}