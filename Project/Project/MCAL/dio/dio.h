/*
 * dio.h
 *
 * Created: 5/15/2023 6:36:12 PM
 *  Author: en_g_speed
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../common/STD_Types.h"
#include "../../common/BIT_Math.h"
#include "dio_cfg.h"
#include "dio_private.h"
#include "dio_linking_config.h"

void DIO_Init(void);
void DIO_Initpin(ST_DIO_ConfigType *config_ptr);
void DIO_WritePin(EN_dio_port_t port, EN_dio_pin_t pin, EN_dio_value_t value);
void DIO_read(EN_dio_port_t port, EN_dio_pin_t pin, Uchar8_t *value);
void DIO_toggle(EN_dio_port_t port, EN_dio_pin_t pin);
void DIO_initpinn  (EN_DIO_Pin_type pin,EN_DIO_PinStatus_type status);

void DIO_writepinn (EN_DIO_Pin_type pin,EN_DIO_PinVoltage_type volt);
void DIO_readpin(EN_DIO_Pin_type pin,EN_DIO_PinVoltage_type *volt);
void DIO_togglepin(EN_DIO_Pin_type pin);

void DIO_InitDCM(Uchar8_t pin, Uchar8_t port,Uchar8_t mode);


#endif /* DIO_H_ */