/*
 * Dio.c
 *
 * Created: 5/15/2023 5:42:04 PM
 *    Author: Speed
 */ 
#include "dio.h"


DIO_ConfigType DIO_ConfigArray[] = {
	// Example configuration for Port A, Pin 0

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
				
				
				case DIO_PORTA:	SET_BIT(DIO_PORTA_DDR_REG,DIO_ConfigArray[i].dio_pin);
				CLEAR_BIT(DIO_PORTA_PORT_REG,DIO_ConfigArray[i].dio_pin);	break;
				case DIO_PORTB:	SET_BIT(DIO_PORTB_DDR_REG,DIO_ConfigArray[i].dio_pin);
				CLEAR_BIT(DIO_PORTB_PORT_REG,DIO_ConfigArray[i].dio_pin);	break;
				
				case DIO_PORTC:	SET_BIT(DIO_PORTC_DDR_REG,DIO_ConfigArray[i].dio_pin);
				CLEAR_BIT(DIO_PORTC_PORT_REG,DIO_ConfigArray[i].dio_pin);	break;
				case DIO_PORTD:	SET_BIT(DIO_PORTD_DDR_REG,DIO_ConfigArray[i].dio_pin);
				CLEAR_BIT(DIO_PORTD_PORT_REG,DIO_ConfigArray[i].dio_pin);    break;
				default:			break;
			}
			
			if (DIO_ConfigArray[i].dio_initial_value == DIO_HIGH)
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

void DIO_Initpin(DIO_ConfigType *config_ptr)
{
	if (config_ptr->dio_mode== DIO_MODE_INPUT)
	{
		
		
		switch(config_ptr->dio_port)
		{
			
			
			case DIO_PORTA:	CLEAR_BIT(DIO_PORTA_DDR_REG,config_ptr->dio_pin);	break;
			case DIO_PORTB:	CLEAR_BIT(DIO_PORTB_DDR_REG,config_ptr->dio_pin);	break;
			case DIO_PORTC:	CLEAR_BIT(DIO_PORTC_DDR_REG,config_ptr->dio_pin);	break;
			case DIO_PORTD:	CLEAR_BIT(DIO_PORTD_DDR_REG,config_ptr->dio_pin);	break;
			default:			break;
		}

		if (config_ptr->dio_initial_value == DIOINPUT_PULLUP)
		{
			switch(config_ptr->dio_port)
			{
				
				case DIO_PORTA:	SET_BIT(DIO_PORTA_PORT_REG,config_ptr->dio_pin);	break;
				case DIO_PORTB:	SET_BIT(DIO_PORTB_PORT_REG,config_ptr->dio_pin);	break;
				case DIO_PORTC:	SET_BIT(DIO_PORTC_PORT_REG,config_ptr->dio_pin);	break;
				case DIO_PORTD:	SET_BIT(DIO_PORTD_PORT_REG,config_ptr->dio_pin);	break;
				default:			break;
			}
		}
		else
		{
			switch(config_ptr->dio_port)
			{
				
				case DIO_PORTA:	CLEAR_BIT(DIO_PORTA_PORT_REG,config_ptr->dio_pin);	break;
				case DIO_PORTB:	CLEAR_BIT(DIO_PORTB_PORT_REG,config_ptr->dio_pin);	break;
				case DIO_PORTC:	CLEAR_BIT(DIO_PORTC_PORT_REG,config_ptr->dio_pin);	break;
				case DIO_PORTD:	CLEAR_BIT(DIO_PORTD_PORT_REG,config_ptr->dio_pin);	break;
				default:			break;
			}
			
		}
	}
	else if (config_ptr->dio_mode == DIO_MODE_OUTPUT)
	{
		
		switch(config_ptr->dio_port)
		{
			
			
			case DIO_PORTA:	SET_BIT(DIO_PORTA_DDR_REG,config_ptr->dio_pin);	break;
			case DIO_PORTB:	SET_BIT(DIO_PORTB_DDR_REG,config_ptr->dio_pin);	break;
			case DIO_PORTC:	SET_BIT(DIO_PORTC_DDR_REG,config_ptr->dio_pin);	break;
			case DIO_PORTD:	SET_BIT(DIO_PORTD_DDR_REG,config_ptr->dio_pin);	break;
			default:			break;
		}
		
		if (config_ptr->dio_initial_value == DIO_HIGH)
		{
			switch(config_ptr->dio_port)
			{
				
				case DIO_PORTA:	SET_BIT(DIO_PORTA_PORT_REG,config_ptr->dio_pin);	break;
				case DIO_PORTB:	SET_BIT(DIO_PORTB_PORT_REG,config_ptr->dio_pin);	break;
				case DIO_PORTC:	SET_BIT(DIO_PORTC_PORT_REG,config_ptr->dio_pin);	break;
				case DIO_PORTD:	SET_BIT(DIO_PORTD_PORT_REG,config_ptr->dio_pin);	break;
				default:			break;
			}
			
		}
		else
		{
			switch(config_ptr->dio_port)
			{
				
				case DIO_PORTA:	CLEAR_BIT(DIO_PORTA_PORT_REG,config_ptr->dio_pin);	break;
				case DIO_PORTB:	CLEAR_BIT(DIO_PORTB_PORT_REG,config_ptr->dio_pin);	break;
				case DIO_PORTC:	CLEAR_BIT(DIO_PORTC_PORT_REG,config_ptr->dio_pin);	break;
				case DIO_PORTD:	CLEAR_BIT(DIO_PORTD_PORT_REG,config_ptr->dio_pin);	break;
				default:			break;
			}
			
		}
		
	}

}

void  DIO_initpinn  (DIO_Pin_type pin,DIO_PinStatus_type status)
{
	DIO_Port_type port = pin/8 ;
	Uchar8_t pin_num =pin % 8;
	
	if (pin_num < 8)
	{

		switch(status)
		{
			case OUTPUT:
			switch(port)
			{
				case PA:
				SET_BIT( DIO_PORTA_DDR_REG,pin_num);
				CLEAR_BIT(DIO_PORTA_PORT_REG,pin_num);
				break;
				case PB:
				SET_BIT( DIO_PORTB_DDR_REG,pin_num);
				CLEAR_BIT(DIO_PORTB_PORT_REG,pin_num);
				break;
				case PC:
				SET_BIT( DIO_PORTC_DDR_REG,pin_num);
				CLEAR_BIT(DIO_PORTC_PORT_REG,pin_num);
				break;
				case PD:
				SET_BIT( DIO_PORTD_DDR_REG,pin_num);
				CLEAR_BIT(DIO_PORTD_PORT_REG,pin_num);
				break;
				default:
				break;
			}
			break;
			case INFREE:
			switch(port)
			{
				case PA:
				CLEAR_BIT(DIO_PORTA_DDR_REG,pin_num);
				CLEAR_BIT(DIO_PORTA_PORT_REG,pin_num);
				break;
				case PB:
				CLEAR_BIT(DIO_PORTB_DDR_REG,pin_num);
				CLEAR_BIT(DIO_PORTB_PORT_REG,pin_num);
				break;
				case PC:
				CLEAR_BIT(DIO_PORTC_DDR_REG,pin_num);
				CLEAR_BIT(DIO_PORTC_PORT_REG,pin_num);
				break;
				case PD:
				CLEAR_BIT(DIO_PORTD_DDR_REG,pin_num);
				CLEAR_BIT(DIO_PORTD_PORT_REG,pin_num);
				break;
				default:
				break;
			}
			break;

			case INPULL:
			switch(port)
			{
				case PA:
				CLEAR_BIT(DIO_PORTA_DDR_REG,pin_num);
				SET_BIT(DIO_PORTA_PORT_REG,pin_num);
				break;
				case PB:
				CLEAR_BIT(DIO_PORTB_DDR_REG,pin_num);
				SET_BIT(DIO_PORTB_PORT_REG,pin_num);
				break;
				case PC:
				CLEAR_BIT(DIO_PORTC_DDR_REG,pin_num);
				SET_BIT(DIO_PORTC_PORT_REG,pin_num);
				break;
				case PD:
				CLEAR_BIT(DIO_PORTD_DDR_REG,pin_num);
				SET_BIT(DIO_PORTD_PORT_REG,pin_num);
				break;
				default:
				break;
			}
			break;
			default:
			break;
		}
	}
	else
	{
	}

}

void  DIO_writepinn (DIO_Pin_type pin,DIO_PinVoltage_type volt)
{
	DIO_Port_type port = pin/8 ;
	Uchar8_t pin_num =pin % 8;
	if (pin_num<8)
	{
		switch (volt)
		{
			case HIGH:

			switch(port)
			{
				case PA:

				SET_BIT(DIO_PORTA_PORT_REG,pin_num);
				break;
				case PB:

				SET_BIT(DIO_PORTB_PORT_REG,pin_num);
				break;
				case PC:

				SET_BIT(DIO_PORTC_PORT_REG,pin_num);
				break;
				case PD:

				SET_BIT(DIO_PORTD_PORT_REG,pin_num);
				break;
				default:
				break;
			}
			break;

			case LOW:

			switch(port)
			{
				case PA:

				CLEAR_BIT(DIO_PORTA_PORT_REG,pin_num);
				break;
				case PB:

				CLEAR_BIT(DIO_PORTB_PORT_REG,pin_num);
				break;
				case PC:

				CLEAR_BIT(DIO_PORTC_PORT_REG,pin_num);
				break;
				case PD:

				CLEAR_BIT(DIO_PORTD_PORT_REG,pin_num);
				break;
				default:
				break;
			}

			break;

			default:
			break;

		}
	}
	else
	{
	}

}
void  DIO_readpin(DIO_Pin_type pin,DIO_PinVoltage_type *volt)
{
	DIO_Port_type port = pin/8 ;
	Uchar8_t pin_num =pin % 8;
	if (pin_num < 8)
	{

		switch(port)
		{
			case PA:

			*volt=GET_BIT(DIO_PORTA_PIN_REG,pin_num);
			break;
			case PB:

			*volt=GET_BIT(DIO_PORTB_PIN_REG,pin_num);
			break;
			case PC:

			*volt=GET_BIT(DIO_PORTC_PIN_REG,pin_num);
			break;
			case PD:

			*volt=GET_BIT(DIO_PORTD_PIN_REG,pin_num);
			break;
			default:
			break;
		}

	}
	else
	{
	}
}
void  DIO_togglepin(DIO_Pin_type pin)
{
	DIO_Port_type port = pin/8 ;
	Uchar8_t pin_num =pin % 8;
	if (pin_num< 8)
	{
		switch(port)
		{
			case PA:
			TOGGLE_BIT(DIO_PORTA_PORT_REG,pin_num);
			break;
			case PB:
			TOGGLE_BIT(DIO_PORTB_PORT_REG,pin_num);
			break;
			case PC:
			TOGGLE_BIT(DIO_PORTC_PORT_REG,pin_num);
			break;
			case PD:
			TOGGLE_BIT(DIO_PORTD_PORT_REG,pin_num);
			break;
			default:
			break;
		}
	}
	else
	{
	}
}



void DIO_InitDCM(u8 pin, u8 port,u8 mode)
{
		if ( mode == DIO_MODE_INPUT)
		{
			switch(port)
			{
				case DIO_PORTA:	CLEAR_BIT(DIO_PORTA_DDR_REG,pin);	break;
				case DIO_PORTB:	CLEAR_BIT(DIO_PORTB_DDR_REG,pin);	break;
				case DIO_PORTC:	CLEAR_BIT(DIO_PORTC_DDR_REG,pin);	break;
				case DIO_PORTD:	CLEAR_BIT(DIO_PORTD_DDR_REG,pin);	break;
				default:			break;
			}
		}
		else if ( mode == DIO_MODE_OUTPUT)
		{
			switch( port )
			{
				case DIO_PORTA:	SET_BIT(DIO_PORTA_DDR_REG,pin);	break;
				case DIO_PORTB:	SET_BIT(DIO_PORTB_DDR_REG,pin);	break;
				case DIO_PORTC:	SET_BIT(DIO_PORTC_DDR_REG,pin);	break;
				case DIO_PORTD:	SET_BIT(DIO_PORTD_DDR_REG,pin);	break;
				default:			break;
			}
			
		}
}