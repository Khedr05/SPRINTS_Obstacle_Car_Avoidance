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
	
	if(moreThan70Flag == 0)
	{
		moreThan70Flag = 1;
		//start motor 30;
		LCD_update(SPEED_30,DIRECTION_F,obstcaleDistance);
		TMR_intDelay_ms(5000);
		
	}
	else if(moreThan70Flag == 1 && u8_g_timeOut == 1)
	{
		//motor 50
		LCD_update(SPEED_50,DIRECTION_F,obstcaleDistance);
		u8_g_timeOut =0;
	}
 
      else LCD_update(SPEED_50,DIRECTION_F,obstcaleDistance);
}

void obstcaleMoreThan30()
{
	// motor 30
	LCD_update(SPEED_30,DIRECTION_F,obstcaleDistance);
}
void LCD_update(EN_speed en_a_speed,EN_direction en_a_direction,float64_t f64_a_distance)
{
	
	
	HLCD_gotoXY(0,0);
	HLCD_WriteString("Speed:");
	HLCD_gotoXY(0,7);
	if(en_a_speed == SPEED_0 )
	{
		HLCD_WriteString("00% ");
	}
	else if (en_a_speed == SPEED_30)
	{
		HLCD_WriteString("30% ");
	}
	else 
	{
		HLCD_WriteString("50% ");
	}
	HLCD_gotoXY(0,11);
	HLCD_WriteString("Dir: ");
	
	if(en_a_direction == DIRECTION_F)
	{
		HLCD_WriteString("F");
	}
	else if(en_a_direction == DIRECTION_B)
	{
		HLCD_WriteString("B");
	}
	else if(en_a_direction == DIRECTION_R)
	{
		HLCD_WriteString("R");
	}
    else
	{
		HLCD_WriteString("L");
	}
	
	HLCD_gotoXY(1,0);
	HLCD_WriteString("Dist:");
	HLCD_gotoXY(1,5);
	HLCD_WriteInt(f64_a_distance);
	HLCD_WriteString(" Cm");
	
}