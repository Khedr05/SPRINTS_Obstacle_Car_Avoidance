/*
 * dio_linking_config.h
 *
 * Created: 5/14/2023 10:30:00 AM
 *  Author: momen
 */ 

#ifndef DIO_LINKING_CONFIG_H
#define DIO_LINKING_CONFIG_H

#include "dio_private.h"

/************* Available Ports ****************/
typedef enum{
    DIO_PORTA,
    DIO_PORTB,
    DIO_PORTC,
    DIO_PORTD
}en_dio_port_t;


/************* Available Pins ****************/
typedef enum{
    DIO_PIN0,
    DIO_PIN1,
    DIO_PIN2,
    DIO_PIN3,
    DIO_PIN4,
    DIO_PIN5,
    DIO_PIN6,
    DIO_PIN7
}en_dio_pin_t;

/************* Available Modes ****************/
typedef enum{
    DIO_MODE_INPUT,
    DIO_MODE_OUTPUT
}en_dio_mode_t;


/************* Available Values ****************/
typedef enum{
    DIO_HIGH,
    DIO_LOW
}en_dio_value_t;


/************* Available Pull-up Resistor Settings ****************/
typedef enum{
    DIO_PULLUP_DISABLED,
    DIO_PULLUP_ENABLED
}en_dio_pullup_t;


/************* DIO Configuration ****************/
typedef struct{
    en_dio_port_t   dio_port;
    en_dio_pin_t    dio_pin;
    en_dio_mode_t   dio_mode;
    en_dio_value_t  dio_initial_value;
    en_dio_pullup_t dio_pullup_resistor;
}DIO_ConfigType;

extern DIO_ConfigType DIO_ConfigArray[];
#endif /* DIO_LINKING_CONFIG_H */