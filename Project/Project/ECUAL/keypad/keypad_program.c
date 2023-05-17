/*
 * keypad_program.c
 *
 * Created: 5/16/2023 3:23:33 PM
 *  Author: Sharpel
 */ 

#include "../../COMMON/std_types.h"
#include "../../MCAL/dio/dio.h"
#include "keypad_config.h"
#include "keypad_interface.h"


extern ST_KEYPAD_CONFIG st_keypad_conf;

/*
Author		: Sharpel
Function	: KEYPAD_init
Description : Initializes Rows as Output and Cols as input and put high logic on each pin
Args        : Void
return      : Void
*/
void KEYPAD_init(void)
{
	/* declare two local counters for row and col*/
	Uchar8_t u8_loc_colsCounter,u8_loc_rowsCounter;
	
	/* loop from 0 to number of rows defined in config file*/
	for(u8_loc_rowsCounter=0;u8_loc_rowsCounter<NUMBER_OF_ROWS;u8_loc_rowsCounter++)
	{
		///* set current row pin direction as output */
		//DIO_s8SETPinDir(st_keypad_conf.u8_arr_rows[u8_loc_rowsCounter],OUTPUT);
		///* set current row pin value as high */
		//DIO_s8SETPinVal(st_keypad_conf.u8_arr_rows[u8_loc_rowsCounter],HIGH);
		
		DIO_Initpin(&st_keypad_conf.u8_arr_rows[u8_loc_rowsCounter]);
	}
	
	/* loop from 0 to number of cols defined in config file*/
	for(u8_loc_colsCounter=0;u8_loc_colsCounter<NUMBER_OF_COLS;u8_loc_colsCounter++)
	{
		///* set current col pin direction as input */
		//DIO_s8SETPinDir(st_keypad_conf.u8_arr_cols[u8_loc_colsCounter],INPUT);
		///* set current col pin value as high */
		//DIO_s8SETPinVal(st_keypad_conf.u8_arr_cols[u8_loc_colsCounter],HIGH);
		DIO_Initpin(&st_keypad_conf.u8_arr_cols[u8_loc_colsCounter]);
	}
}

/*
Author		: Sharpel
Function	: KEYPAD_getButton
Description : outer loop over rows and write logic low on current row Counter then inner loop for cols 
              checks 1- if current col counter pressed return [row Counter] [col Counter]
			         2- else increment col counter 
					 3- repeat tell col counter is equal to Number of cols ( inner loop terminates ) 
			  write logic HIgh on current row Counter to de-activate this row and increment row counter 
			  repeat tell row counter is equal to Number of rows ( outer loop terminates )
			  return Nothing pressed		 
             
Args        : Void
return      : EN_KEYPADKEYS enum holds all possible keys
*/
EN_KEYPAD_KEYS KEYPAD_getButton()
{
	/* declare two local counters for row and col*/
	Uchar8_t u8_loc_colsCounter,u8_loc_rowsCounter;
	
	/* initialize pinValue variable to holds pin state*/
	Uchar8_t pinValue = 1;
	
	
	/* loop from 0 to number of rows defined in config file*/
	for( u8_loc_rowsCounter = 0 ; u8_loc_rowsCounter < NUMBER_OF_ROWS ; u8_loc_rowsCounter++)
	{
		/* write logic low on current row pin*/
		//DIO_s8SETPinVal(st_keypad_conf.u8_arr_rows[u8_loc_rowsCounter],LOW);
		DIO_WritePin(KEPAD_PORT,st_keypad_conf.u8_arr_rows[u8_loc_rowsCounter].dio_pin,DIO_LOW);
		/* loop from 0 to number of cols defined in config file*/
		for (u8_loc_colsCounter = 0 ; u8_loc_colsCounter < NUMBER_OF_COLS ; u8_loc_colsCounter++)
		{
			/* Get value of current col pin*/
			//DIO_s8GETPinVal (st_keypad_conf.u8_arr_cols[u8_loc_colsCounter] , &pinValue); 
			DIO_read(KEPAD_PORT,st_keypad_conf.u8_arr_cols[u8_loc_colsCounter].dio_pin,&pinValue);
			/* check if pressed*/
			if(pinValue == 0) 
			{
				/* loop tell it turns high again (user left key) */
				while(pinValue == 0)
				{
		          DIO_read(KEPAD_PORT,st_keypad_conf.u8_arr_cols[u8_loc_colsCounter].dio_pin,&pinValue);
				}
				
				/* return current [row][col] position from config array */
				return st_keypad_conf.u8_arr_keys[u8_loc_rowsCounter][u8_loc_colsCounter];
			}
		}
		
		/* write logic high on current row pin */
		//DIO_s8SETPinVal(st_keypad_conf.u8_arr_rows[u8_loc_rowsCounter],HIGH);   
		DIO_WritePin(KEPAD_PORT,st_keypad_conf.u8_arr_rows[u8_loc_rowsCounter].dio_pin,DIO_HIGH);
	}
	
	/* if nothing pressed */
	return KEY_NOTHING;
}