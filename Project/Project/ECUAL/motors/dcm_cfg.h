 /*
  * DCM_cfg.h
  *
  *     Created on: Apr 11, 2023
  *         Author: Mahmoud Mowafey - https://github.com/Mahmoud-Mowafy
  *    Description: This file contains all Direct Current Motor (DCM) functions' prototypes and definitions (Macros) to avoid magic numbers.
  *		MCU Datasheet: AVR ATmega32 - https://ww1.microchip.com/downloads/en/DeviceDoc/Atmega32A-DataSheet-Complete-DS40002072A.pdf
  */

#ifndef DCM_CFG_H_
#define DCM_CFG_H_

/*******************************************************************************************************************************************************************/
/* DCM Includes */
/*******************************************************************************************************************************************************************/

 /*******************************************************************************************************************************************************************/
 /* ATmega32(L) interfacing with DCM: */
 /*
								 One-Dirction Mode											Two-Dirction Mode
				  --------------                   ----------				 --------------                   ----------
				 |   ATmega32   |                 |   DCM    |				|   ATmega32   |                 |   DCM    |
				 |              |                 |          |				|              |                 |          |
				 | 	 (OCR0) PB4|---------------->|Ctrl Pin  |				| 	 (OC1B) PD4|---------------->|CW        |
				  -------------- 				  ----------				| 	 (OC1A) PD5|---------------->|CCW       |
																			  --------------                   ----------
  */
  /********************* Motor_0 Configurations ***********************/



typedef struct {
	u8 DCM_g_motEnPinNumber0;
	u8 DCM_g_motEnPinNumber1;
	u8 DCM_g_motPWMPinNumber;
	EN_DIO_PORT_T DCM_g_motEnPortNumber;
	u8 DCM_g_motPWMPortNumber;
}ST_DCM_g_Config_t;



#endif /* DCM_CFG_H_ */