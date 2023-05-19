/*
 * dio.h
 *
 * Created: 5/15/2023 6:36:12 PM
 *  Author: Speed
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../common/STD_Types.h"
#include "../../common/BIT_Math.h"
#include "dio_cfg.h"
#include "dio_private.h"
#include "dio_linking_config.h"

void DIO_Init(void);
void DIO_Initpin(DIO_ConfigType *config_ptr);
void DIO_WritePin(en_dio_port_t port, en_dio_pin_t pin, en_dio_value_t value);
void DIO_read(en_dio_port_t port, en_dio_pin_t pin, Uchar8_t *value);
void DIO_toggle(en_dio_port_t port, en_dio_pin_t pin);
void DIO_initpinn  (DIO_Pin_type pin,DIO_PinStatus_type status);

void DIO_writepinn (DIO_Pin_type pin,DIO_PinVoltage_type volt);
void DIO_readpin(DIO_Pin_type pin,DIO_PinVoltage_type *volt);
void DIO_togglepin(DIO_Pin_type pin);

void DIO_InitDCM(u8 pin, u8 port,u8 mode);


#endif /* DIO_H_ */