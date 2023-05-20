/*
 * PB_interface.h
 *
 *  Created on: 6 Apr 2023
 *      Author: 20101
 */

#ifndef ECU_PUSH_BUTTON_PB_INTERFACE_H_
#define ECU_PUSH_BUTTON_PB_INTERFACE_H_

#include "PB_config.h"
#include "../../MCAL/dio/dio.h"
#include "../../COMMON/BIT_Math.h"

/*
Function: PUSH_BTN_intialize

Description: Initializes a push button based on the configuration settings specified in the input parameter.

Parameters:
-  btn : A pointer to an ST_PUSH_BTN_t struct that contains the configuration settings for the push button.

Return Type: Std_ReturnType. This is a standard type used in AUTOSAR (Automotive Open System Architecture) 
	         software development to indicate the success or failure of a function call. 
The possible return values for this function are:
-  E_OK		: The function has completed successfully.
-  E_NOT_OK : The function has encountered an error and could not complete successfully.


Overall, the PUSH_BTN_intialize function provides a way to initialize a push button based on the specified 
configuration settings. By using this function, the software can ensure that the pin used by the push button 
is configured correctly and the push button is ready for use.
*/
void PUSH_BTN_intialize();

/*
Function	 : PUSH_BTN_read_state

Description  : Reads the current en_g_state of a push button and returns its value.

Parameters:
-  btn		 : A pointer to an ST_PUSH_BTN_t struct that contains the configuration settings and current en_g_state 
			   information for the push button.
-  btn_state : A pointer to an EN_PUSH_BTN_state_t enum where the current en_g_state of the push button 
			   will be stored.

Return Type	 : Std_ReturnType. This is a standard type used in AUTOSAR (Automotive Open System Architecture) 
			   software development to indicate the success or failure of a function call. 
The possible return values for this function are:
-  E_OK		 : The function has completed successfully.
-  E_NOT_OK  : The function has encountered an error and could not complete successfully.


Overall, the PUSH_BTN_read_state function provides a way to read the current en_g_state of a push button and return
its value. By using this function, the software can determine whether the push button is currently pressed or
released and take appropriate action based on its en_g_state.
*/
void PUSH_BTN_read_state(Uchar8_t btnNumber, EN_PUSH_BTN_state_t *btn_state);

#endif /* ECU_PUSH_BUTTON_PB_INTERFACE_H_ */
