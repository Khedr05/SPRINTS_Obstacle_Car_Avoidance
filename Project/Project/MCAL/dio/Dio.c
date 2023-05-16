/*
 * Dio.c
 *
 * Created: 5/15/2023 5:42:04 PM
 *    Author: Speed
 */ 
#include "dio.h"

DIO_ConfigType DIO_ConfigArray[] = {
	// Example configuration for Port A, Pin 0
	{DIO_PORTA, DIO_PIN0, DIO_MODE_OUTPUT, DIOOUTPUT_LOW, DIO_PULLUP_DISABLED},
	// Example configuration for Port B, Pin 3
	{DIO_PORTB, DIO_PIN3, DIO_MODE_OUTPUT, DIOOUTPUT_LOW, DIO_PULLUP_DISABLED},
	// Add additional pin configurations as needed
};

void DIO_Init(void)
{
	Uchar8_t i;
	for (i = 0; i < sizeof(DIO_ConfigArray) / sizeof(DIO_ConfigType); i++)
	{
	

		// Set the mode of the current pin
		if (DIO_ConfigArray[i].dio_mode == DIO_MODE_INPUT)
		{
			
			
			switch(DIO_ConfigArray[i].dio_port)
			{
				
				
				case DIO_PORTA:	CLEAR_BIT(DIO_PORTA_DDR_REG,DIO_ConfigArray[i].dio_pin);	break;
				case DIO_PORTB:	CLEAR_BIT(DIO_PORTB_DDR_REG,DIO_ConfigArray[i].dio_pin);	break;
				case DIO_PORTC:	CLEAR_BIT(DIO_PORTC_DDR_REG,DIO_ConfigArray[i].dio_pin);	break;
				case DIO_PORTD:	CLEAR_BIT(DIO_PORTD_DDR_REG,DIO_ConfigArray[i].dio_pin);	break;
				default:			break;
			}

			if (DIO_ConfigArray[i].dio_initial_value == DIOINPUT_PULLUP)
			{
					switch(DIO_ConfigArray[i].dio_port)
					{
						
						case DIO_PORTA:	SET_BIT(DIO_PORTA_PORT_REG,DIO_ConfigArray[i].dio_pin);	break;
						case DIO_PORTB:	SET_BIT(DIO_PORTB_PORT_REG,DIO_ConfigArray[i].dio_pin);	break;
						case DIO_PORTC:	SET_BIT(DIO_PORTC_PORT_REG,DIO_ConfigArray[i].dio_pin);	break;
						case DIO_PORTD:	SET_BIT(DIO_PORTD_PORT_REG,DIO_ConfigArray[i].dio_pin);	break;
						default:			break;
					}
			}
			else
			{
			switch(DIO_ConfigArray[i].dio_port)
			{
				
				case DIO_PORTA:	CLEAR_BIT(DIO_PORTA_PORT_REG,DIO_ConfigArray[i].dio_pin);	break;
				case DIO_PORTB:	CLEAR_BIT(DIO_PORTB_PORT_REG,DIO_ConfigArray[i].dio_pin);	break;
				case DIO_PORTC:	CLEAR_BIT(DIO_PORTC_PORT_REG,DIO_ConfigArray[i].dio_pin);	break;
				case DIO_PORTD:	CLEAR_BIT(DIO_PORTD_PORT_REG,DIO_ConfigArray[i].dio_pin);	break;
				default:			break;
			}
			
			}
		}
		else if (DIO_ConfigArray[i].dio_mode == DIO_MODE_OUTPUT)
		{
			
			switch(DIO_ConfigArray[i].dio_port)
			{
				
				
				case DIO_PORTA:	SET_BIT(DIO_PORTA_DDR_REG,DIO_ConfigArray[i].dio_pin);	break;
				case DIO_PORTB:	SET_BIT(DIO_PORTB_DDR_REG,DIO_ConfigArray[i].dio_pin);	break;
				case DIO_PORTC:	SET_BIT(DIO_PORTC_DDR_REG,DIO_ConfigArray[i].dio_pin);	break;
				case DIO_PORTD:	SET_BIT(DIO_PORTD_DDR_REG,DIO_ConfigArray[i].dio_pin);	break;
				default:			break;
			}
			
			if (DIO_ConfigArray[i].dio_initial_value == DIOOUTPUT_HIGH)
			{
				switch(DIO_ConfigArray[i].dio_port)
				{
					
					case DIO_PORTA:	SET_BIT(DIO_PORTA_PORT_REG,DIO_ConfigArray[i].dio_pin);	break;
					case DIO_PORTB:	SET_BIT(DIO_PORTB_PORT_REG,DIO_ConfigArray[i].dio_pin);	break;
					case DIO_PORTC:	SET_BIT(DIO_PORTC_PORT_REG,DIO_ConfigArray[i].dio_pin);	break;
					case DIO_PORTD:	SET_BIT(DIO_PORTD_PORT_REG,DIO_ConfigArray[i].dio_pin);	break;
					default:			break;
				}
				
			}
			else
			{
			switch(DIO_ConfigArray[i].dio_port)
			{
				
				case DIO_PORTA:	CLEAR_BIT(DIO_PORTA_PORT_REG,DIO_ConfigArray[i].dio_pin);	break;
				case DIO_PORTB:	CLEAR_BIT(DIO_PORTB_PORT_REG,DIO_ConfigArray[i].dio_pin);	break;
				case DIO_PORTC:	CLEAR_BIT(DIO_PORTC_PORT_REG,DIO_ConfigArray[i].dio_pin);	break;
				case DIO_PORTD:	CLEAR_BIT(DIO_PORTD_PORT_REG,DIO_ConfigArray[i].dio_pin);	break;
				default:			break;
			}
			
			}
		}
	}
}
void DIO_WritePin(en_dio_port_t port, en_dio_pin_t pin, en_dio_value_t value)
{
	
	
	// Set the pin value
	
	switch (value) {
		case DIO_HIGH:
		
				switch(port)
				{
					
					case DIO_PORTA:	SET_BIT(DIO_PORTA_PORT_REG,pin);	break;
					case DIO_PORTB:	SET_BIT(DIO_PORTB_PORT_REG,pin);	break;
					case DIO_PORTC:	SET_BIT(DIO_PORTC_PORT_REG,pin);	break;
					case DIO_PORTD:	SET_BIT(DIO_PORTD_PORT_REG,pin);	break;
					default:			break;
				}
				
		break;
		case DIO_LOW:
		switch(port)
		{
			
			case DIO_PORTA:	CLEAR_BIT(DIO_PORTA_PORT_REG,pin);	break;
			case DIO_PORTB:	CLEAR_BIT(DIO_PORTB_PORT_REG,pin);	break;
			case DIO_PORTC:	CLEAR_BIT(DIO_PORTC_PORT_REG,pin);	break;
			case DIO_PORTD:	CLEAR_BIT(DIO_PORTD_PORT_REG,pin);	break;
			default:			break;
		}
		
		break;
		default:
		// Invalid pin value
		break;
	}
}
void DIO_read(en_dio_port_t port, en_dio_pin_t pin, Uchar8_t *value)
{
	
	switch(port)
	{
		case DIO_PORTA:	*value = GET_BIT(DIO_PORTA_PIN_REG,pin);		break;
		case DIO_PORTB:	*value = GET_BIT(DIO_PORTB_PIN_REG,pin);		break;
		case DIO_PORTC:	*value = GET_BIT(DIO_PORTC_PIN_REG,pin);		break;
		case DIO_PORTD:	*value = GET_BIT(DIO_PORTD_PIN_REG,pin);		break;
		default:			break;
	}


}

void DIO_toggle(en_dio_port_t port, en_dio_pin_t pin)
{
	
		
			switch(port)
			{
				case DIO_PORTA:	TOGGLE_BIT(DIO_PORTA_PORT_REG,pin);		break;
				case DIO_PORTB:	TOGGLE_BIT(DIO_PORTB_PORT_REG,pin);		break;
				case DIO_PORTC:	TOGGLE_BIT(DIO_PORTC_PORT_REG,pin);		break;
				case DIO_PORTD:	TOGGLE_BIT(DIO_PORTD_PORT_REG,pin);		break;
				default:				    break;
			}
		
	
	
}
