/*
 * PB_prog.c
 *
 *  Created on: 6 Apr 2023
 *      Author: 20101
 */

#include"PB_interface.h"

extern const ST_PUSH_BTN_t A_pbConfig[NUMBER_OF_PUSH_BUTTONS];

void PUSH_BTN_intialize()
{
	DIO_initpinn(PINC4,INPULL);
}

void PUSH_BTN_read_state(Uchar8_t btnNumber, EN_PUSH_BTN_state_t *btn_state)
{

		en_dio_value_t pin_logic_status = DIO_LOW;
		DIO_read(A_pbConfig[btnNumber].PUSH_BTN_pin.dio_port,A_pbConfig[btnNumber].PUSH_BTN_pin.dio_pin,&pin_logic_status);
		
		if(PUSH_BTN_PULL_UP == A_pbConfig[btnNumber].PUSH_BTN_connection)
		{
			if(DIO_HIGH == pin_logic_status)
			{
				*btn_state = PUSH_BTN_STATE_RELEASED;
			}
			else
			{
				*btn_state = PUSH_BTN_STATE_PRESSED;
			}
		}
		else if(PUSH_BTN_PULL_DOWN == A_pbConfig[btnNumber].PUSH_BTN_connection)
		{
			if(DIO_HIGH == pin_logic_status)
			{
				*btn_state = PUSH_BTN_STATE_PRESSED;
			}
			else
			{
				*btn_state = PUSH_BTN_STATE_RELEASED;
			}
		}
}
