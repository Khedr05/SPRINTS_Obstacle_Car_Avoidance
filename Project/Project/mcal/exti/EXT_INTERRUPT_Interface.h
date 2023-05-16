/*
 * EXT_INTERRUPT_Interface.h
 *
 *  Created on: 9 Apr 2023
 *      Author: 20101
 */

#ifndef MCAL_INTERRUPT_EXTERNAL_INTERRUPT_EXT_INTERRUPT_INTERFACE_H_
#define MCAL_INTERRUPT_EXTERNAL_INTERRUPT_EXT_INTERRUPT_INTERFACE_H_

#include "../../common/STD_Types.h"
#include "../../common/BIT_Math.h"
#include "EXT_INTERRUPT_Config.h"
#include "EXT_INTERRUPT_Private.h"
#include "../mcu_cfg/MCU_Interface.h"



/*
Function: EXT_vINTERRUPT_Init

Description: Initializes an external interrupt on a micro-controller with the 
			 specified configuration settings.
Parameters:
-  EXT_INTx : A pointer to an ST_EXT_INTERRUPTS_CFG struct that contains the configuration settings 
			  for the external interrupt.

Return Type: Std_ReturnType. This is a standard type used in AUTOSAR (Automotive Open System Architecture) 
			 software development to indicate the success or failure of a function call.
The possible return values for this function are:
-  E_OK : The function has completed successfully.
-  E_NOT_OK : The function has encountered an error and could not complete successfully.

Overall, the EXT_vINTERRUPT_Init function provides a way to initialize an external interrupt on a 
micro-controller with the desired configuration settings. By using this function, the software can set
up and handle external interrupts based on the specific interrupt number and sense control mode, and
execute the appropriate ISR when the interrupt is triggered.
*/
 void EXT_vINTERRUPT_Init(void);
/*
Function: EXT_vINTERRUPT_Denit

Description: Deinitializes an external interrupt on a micro-controller with
			 the specified configuration settings.

Parameters:
-  EXT_INTx : A pointer to an ST_EXT_INTERRUPTS_CFG struct that contains the configuration 
			  settings for the external interrupt.

Return Type: Std_ReturnType. This is a standard type used in AUTOSAR (Automotive Open System Architecture) 
software development to indicate the success or failure of a function call. 
The possible return values for this function are:
-  E_OK		: The function has completed successfully.
-  E_NOT_OK : The function has encountered an error and could not complete successfully.


Overall, the EXT_vINTERRUPT_Denit function provides a way to deinitialize an external 
interrupt on a micro-controller with the desired configuration settings. By using this 
function, the software can remove the interrupt and associated ISR, freeing up resources
and ensuring proper operation of the micro-controller.
*/
void EXT_vINTERRUPT_Denit(void);

void EXT_vINTERRUPT_setSenseControl(void);


void EXT_INTERRUPT_SetInterruptHandler(void);



#endif /* MCAL_INTERRUPT_EXTERNAL_INTERRUPT_EXT_INTERRUPT_INTERFACE_H_ */
