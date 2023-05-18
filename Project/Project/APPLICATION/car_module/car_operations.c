/*
 * car_operations.c
 *
 * Created: 16/05/2023 22:27:10
 *  Author: 20101
 */ 

#include "car_operations.h"

EN_speed speed = SPEED_0;
EN_direction rotation = DIRECTION_R;
EN_direction direction = DIRECTION_F;
EN_carState state = SET_DEFAULT_ROTATION;
extern u8 u8_g_timeOut;
Uchar8_t timeOutFlag = 0 , rotationFlag = 0;
EN_PUSH_BTN_state_t rotationBtnState = PUSH_BTN_STATE_PRESSED;
float64_t obstcaleDistance = 0;

Uchar8_t moreThan70Flag = 0;


void setDefaultRotation()
{
	
	HLCD_gotoXY(0,0);
	HLCD_WriteString("Set Def. Rot.");
	HLCD_gotoXY(1,0);
	HLCD_WriteString("Right");
	TMR_intDelay_ms(5000);
	while(u8_g_timeOut != 1)
	{
		PUSH_BTN_read_state(0,&rotationBtnState);
		if(rotationBtnState == PUSH_BTN_STATE_RELEASED)
		{
			while(rotationBtnState == PUSH_BTN_STATE_RELEASED)
			{
				PUSH_BTN_read_state(0,&rotationBtnState);
			}
			if(rotationFlag == 0)
			{
				rotationFlag = 1;
				rotation = DIRECTION_L;
				HLCD_gotoXY(1,0);
				HLCD_WriteString("Left ");
				
			}
			else if(rotationFlag == 1)
			{
				rotationFlag = 0;
				rotation = DIRECTION_R;
				HLCD_gotoXY(1,0);
				HLCD_WriteString("Right ");
			}
		}
	}
	u8_g_timeOut = 0;
	TMR_intDelay_ms(2000);
	while(u8_g_timeOut !=1);
	u8_g_timeOut = 0;
}



void obstcaleMoreThan70()
{
	HLCD_ClrDisplay();
	HLCD_gotoXY(0,0);
	HLCD_WriteString("Speed:");
	HLCD_gotoXY(0,10);
	HLCD_WriteString("Dir:F");
	HLCD_gotoXY(1,0);
	HLCD_WriteString("Dist:");
	HLCD_gotoXY(1,5);
	HLCD_WriteInt(obstcaleDistance);
	HLCD_WriteString(" Cm");
	if(moreThan70Flag == 0)
	{
		moreThan70Flag = 1;
		//start motor 30;
		HLCD_gotoXY(0,7);
		HLCD_WriteString("30%");
		TMR_intDelay_ms(5000);
	}
	else if(moreThan70Flag == 1 && u8_g_timeOut == 1)
	{
		//motor 50
		HLCD_gotoXY(0,7);
		HLCD_WriteString("50%");
		u8_g_timeOut = 0;
	}
}