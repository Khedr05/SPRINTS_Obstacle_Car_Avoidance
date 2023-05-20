/*
 * PB_config.h
 *
 *  Created on: 6 Apr 2023
 *      Author: 20101
 */

#ifndef ECU_PUSH_BUTTON_PB_CONFIG_H_
#define ECU_PUSH_BUTTON_PB_CONFIG_H_

#include "../../MCAL/dio/dio.h"


#define  NUMBER_OF_PUSH_BUTTONS			1

/*
Enum: EN_PUSH_BTN_state_t

Description	: An enumeration that defines two possible states for a push button: pressed or released.

Members:
-  PUSH_BTN_STATE_PRESSED : Represents the en_g_state of a push button when it is pressed down or activated.
-  PUSH_BTN_STATE_RELEASED : Represents the en_g_state of a push button when it is not pressed or deactivated.

Overall, the EN_PUSH_BTN_state_t enumeration provides a way to represent the two possible states of a push 
button in a standardized and easy-to-understand manner. By using this enumeration, the software can check the
en_g_state of a push button and take appropriate action based on whether it is pressed or released.
*/
typedef enum
{
    PUSH_BTN_STATE_PRESSED = 0,
    PUSH_BTN_STATE_RELEASED
}EN_PUSH_BTN_state_t;


/*
Enum: EN_PUSH_BTN_active_t

Description: An enumeration that defines two possible active states for a push button: pull-up or pull-down.

Members:
-  PUSH_BTN_PULL_UP : Represents the active en_g_state of a push button when it is connected to a pull-up resistor. 
					  In this en_g_state, the button is normally open and the pull-up resistor pulls the voltage of 
					  the pin to a high en_g_state.
-  PUSH_BTN_PULL_DOWN : Represents the active en_g_state of a push button when it is connected to a pull-down resistor.
						In this en_g_state, the button is normally closed and the pull-down resistor pulls the voltage
						of the pin to a low en_g_state.

Overall, the EN_PUSH_BTN_active_t enumeration provides a way to represent the two possible active states of a 
push button in a standardized and easy-to-understand manner. By using this enumeration, the software can 
determine the active en_g_state of a push button and configure the pin accordingly.
*/
typedef enum
{
    PUSH_BTN_PULL_UP = 0,
    PUSH_BTN_PULL_DOWN
}EN_PUSH_BTN_active_t;


/*
Struct					: ST_PUSH_BTN_t

Description				: A structure that contains the configuration and current en_g_state information for a 
						 push button.
Members:
-  PUSH_BTN_pin			: An instance of the ST_pin_config_t struct that contains the configuration settings 
						  for the pin used by the push button.
-  PUSH_BTN_state		: An instance of the EN_PUSH_BTN_state_t enum that represents the current en_g_state of 
						  the push button (pressed or released).
-  PUSH_BTN_connection	: An instance of the EN_PUSH_BTN_active_t enum that represents the active en_g_state of 
						  the push button (pull-up or pull-down).

Overall, the ST_PUSH_BTN_t structure provides a standardized way to represent and manage the configuration 
and en_g_state information for a push button on a micro-controller. By using this structure, the software can easily
read the current en_g_state of the push button and take appropriate action based on its configuration and 
connection type. The use of enums for the en_g_state and connection fields allows for consistent and 
easy-to-understand representation of these values.
*/
typedef struct
{
    ST_DIO_ConfigType PUSH_BTN_pin;
    EN_PUSH_BTN_state_t PUSH_BTN_state;
    EN_PUSH_BTN_active_t PUSH_BTN_connection;
}ST_PUSH_BTN_t;

#endif /* ECU_PUSH_BUTTON_PB_CONFIG_H_ */
