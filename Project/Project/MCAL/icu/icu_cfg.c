/*
 * ICU_cfg.c
 *
 * Created: 5/16/2023 8:24:24 PM
 *         Author: Mahmoud Mowafey - https://github.com/Mahmoud-Mowafy
 *  Description: This file contains all Direct Current Motor (DCM) functions' implementation.
 *		MCU Datasheet: AVR ATmega32
 *                  https://ww1.microchip.com/downloads/en/DeviceDoc/Atmega32A-DataSheet-Complete-DS40002072A.pdf
 */ 

#include "ICU_cfg.h"
ST_ICU_g_Config_t ST_g_softwareICU[1] =
{
	{ EXI_U8_INT0 ,  EXI_U8_SENSE_RISING_EDGE , EXI_U8_SENSE_FALLING_EDGE, ISR_ENABLED}
};
