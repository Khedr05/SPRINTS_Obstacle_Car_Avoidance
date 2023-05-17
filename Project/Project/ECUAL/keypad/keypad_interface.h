/*
 * keypad_interface.h
 *
 * Created: 5/16/2023 3:22:43 PM
 *  Author: Sharpel
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "keypad_config.h"

/*
Author		: Sharpel
Function	: KEYPAD_init
Description : Initializes Rows as Output and Cols as input and put high logic on each pin
Args        : Void
return      : Void 
*/
void KEYPAD_init(void);

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
EN_KEYPAD_KEYS KEYPAD_getButton();

#endif /* KEYPAD_INTERFACE_H_ */