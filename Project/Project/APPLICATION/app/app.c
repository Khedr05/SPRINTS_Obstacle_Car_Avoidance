/*
 * app.c
 *
 * Created: 16/05/2023 22:26:51
 *  Author: 20101
 */ 


#include "apph.h"

extern EN_carState state;
extern float64_t obstcaleDistance;
extern Uchar8_t moreThan70Flag;

void app_init()
{
	HLCD_vidInit();
	PUSH_BTN_intialize();
	TIMER_TMR2NormalModeInit(ENABLED);
	ultrasonic_vInit();
}

void app_main()
{
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
			HLCD_ClrDisplay();
			HLCD_WriteInt(obstcaleDistance);
			if(obstcaleDistance > 70)
			{
				HLCD_WriteString("akatr 70");
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
				HLCD_WriteString("less 20");
				state = LESS_THAN_20_CM;
			}
			else
			{
				HLCD_WriteInt(obstcaleDistance);
			}
			break;
		}
		case MORE_THAN_70_CM :
		{
			obstcaleMoreThan70();
			state = CAR_SCANING;
			break;
		}
		case MORE_THAN_30_CM:
		{
			moreThan70Flag = 0;
			break;
		}
	}
}