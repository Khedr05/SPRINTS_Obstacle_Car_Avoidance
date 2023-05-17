/*
 * EXT_INTERRUPT_Config.h
 *
 *  Created on: 9 Apr 2023
 *      Author: 20101
 */

#ifndef MCAL_INTERRUPT_EXTERNAL_INTERRUPT_EXT_INTERRUPT_CONFIG_H_
#define MCAL_INTERRUPT_EXTERNAL_INTERRUPT_EXT_INTERRUPT_CONFIG_H_

//#define EXT_INT0 __vector_1
#define EXT_INT1 __vector_2
#define EXT_INT2 __vector_3


#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

#define EXT_INTERRUPT_PINS			3

/*
Enum: EN_MCUCR_REG_BITS

Description: An enumeration that defines the bit fields for the `MCUCR` register on a micro-controller.

Members:
-  MCUCR_REG_ISC00_BITS : Represents the bit field for the `ISC00` bit of the `MCUCR` register.
-  MCUCR_REG_ISC01_BITS : Represents the bit field for the `ISC01` bit of the `MCUCR` register.
-  MCUCR_REG_ISC10_BITS : Represents the bit field for the `ISC10` bit of the `MCUCR` register.
-  MCUCR_REG_ISC11_BITS : Represents the bit field for the `ISC11` bit of the `MCUCR` register.


Overall, the EN_MCUCR_REG_BITS enumeration provides a way to represent and manage the individual bit 
fields within the `MCUCR` register on a micro-controller in a standardized and easy-to-understand manner.
By using this enumeration, the software can read and modify the individual bits within this register as 
needed for interrupt configuration and other purposes.
*/

typedef enum
{
	MCUCR_REG_ISC00_BITS = 0,
	MCUCR_REG_ISC01_BITS,
	MCUCR_REG_ISC10_BITS,
	MCUCR_REG_ISC11_BITS

}EN_MCUCR_REG_BITS;

/*
Enum: EN_MCUCSR_REG_BITS

Description: An enumeration that defines the bit fields for the `MCUCSR` register on a micro-controller.

Members:
-  MCUCSR_REG_ISC2_BITS : Represents the bit field for the `ISC2` bit of the `MCUCSR` register.


Overall, the EN_MCUCSR_REG_BITS enumeration provides a way to represent and manage the individual 
bit fields within the `MCUCSR` register on a micro-controller in a standardized and easy-to-understand 
manner. By using this enumeration, the software can read and modify the individual bits within
this register as needed for interrupt configuration and other purposes.
*/
typedef enum
{
	MCUCSR_REG_ISC2_BITS = 6,

}EN_MCUCSR_REG_BITS;

/*
Enum: EN_GICR_REG_BITS

Description: An enumeration that defines the bit fields for the `GICR` register on a micro-controller.

Members:
-  GICR_REG_INT2_BITS : Represents the bit field for the `INT2` bit of the `GICR` register.
-  GICR_REG_INT0_BITS : Represents the bit field for the `INT0` bit of the `GICR` register.
-  GICR_REG_INT1_BITS : Represents the bit field for the `INT1` bit of the `GICR` register.


Overall, the EN_GICR_REG_BITS enumeration provides a way to represent and manage the individual bit fields
within the `GICR` register on a micro-controller in a standardized and easy-to-understand manner. 
By using this enumeration, the software can read and modify the individual bits within this register
as needed for interrupt configuration and other purposes.
*/
typedef enum
{
	GICR_REG_INT2_BITS = 5,
	GICR_REG_INT0_BITS,
	GICR_REG_INT1_BITS

}EN_GICR_REG_BITS;

/*
Enum: EN_GIFR_REG_BITS

Description: An enumeration that defines the bit fields for the `GIFR` register on a micro-controller.

Members:
-  GIFR_REG_INTF2_BITS : Represents the bit field for the `INTF2` bit of the `GIFR` register.
-  GIFR_REG_INTF0_BITS : Represents the bit field for the `INTF0` bit of the `GIFR` register.
-  GIFR_REG_INTF1_BITS : Represents the bit field for the `INTF1` bit of the `GIFR` register.

Overall, the EN_GIFR_REG_BITS enumeration provides a way to represent and manage the individual bit fields
within the `GIFR` register on a micro-controller in a standardized and easy-to-understand manner. 
By using this enumeration, the software can read and modify the individual bits within this 
register as needed for interrupt handling and other purposes.
*/

typedef enum
{
	GIFR_REG_INTF2_BITS = 5,
	GIFR_REG_INTF0_BITS,
	GIFR_REG_INTF1_BITS

}EN_GIFR_REG_BITS;

/*
Enum: EN_EXT_INTERRUPT_Sense_Control

Description: An enumeration that defines the possible sense control modes for external 
			 interrupts on a micro-controller.

Members:
- LOW_LEVEL_SENSE_CONTROL    : Represents the sense control mode where the interrupt is triggered when 
							   the input signal is at a low level.
- ANY_LOGICAL_SENSE_CONTROL  : Represents the sense control mode where the interrupt is triggered when 
							   there is any change in the logical state of the input signal.
- FALLING_EDGE_SENSE_CONTROL : Represents the sense control mode where the interrupt is triggered when 
							   the input signal changes from a high level to a low level.
- RISING_EDGE_SENSE_CONTROL  : Represents the sense control mode where the interrupt is triggered when
							   the input signal changes from a low level to a high level.

Overall, the EN_EXT_INTERRUPT_Sense_Control enumeration provides a way to represent and manage the
different sense control modes for external interrupts on a micro-controller in a standardized and 
easy-to-understand manner. By using this enumeration, the software can configure and handle external 
interrupts based on the desired sense control mode for the specific input signal being used.
*/
typedef enum
{
	LOW_LEVEL_SENSE_CONTROL = 0,
	ANY_LOGICAL_SENSE_CONTROL,
	FALLING_EDGE_SENSE_CONTROL,
	RISING_EDGE_SENSE_CONTROL

}EN_EXT_INTERRUPT_Sense_Control;

/*
Enum: EN_EXT_INTERRUPTS

Description: An enumeration that defines the external interrupts available on a micro-controller.

Members:
- EXT0_INTERRUPTS  : Represents external interrupt 0.
- EXT1_INTERRUPTS  : Represents external interrupt 1.
- EXT2_INTERRUPTS  : Represents external interrupt 2.


Overall, the EN_EXT_INTERRUPTS enumeration provides a way to represent and manage the available external 
interrupts on a micro-controller in a standardized and easy-to-understand manner. By using this 
enumeration, the software can configure and handle external interrupts based on the specific
interrupt being used.
*/
typedef enum
{
	EXT0_INTERRUPTS = 0,
	EXT1_INTERRUPTS,
	EXT2_INTERRUPTS
}EN_EXT_INTERRUPTS;


/*
Struct: ST_EXT_INTERRUPTS_CFG

Description: A structure that contains the configuration settings for an external
			 interrupt on a micro-controller.
Members:
-  INTERRUPT_EXTERNAL_HANDLER : A function pointer to the interrupt service routine (ISR)
								for the external interrupt(call-back function).
-  EXTERNAL_INTERRUPRT_Number : An instance of the EN_EXT_INTERRUPTS enum that specifies the
								external interrupt number to be configured.
-  EXTERNAL_INTERRUPRT_Sense_Control : An instance of the EN_EXT_INTERRUPT_Sense_Control enum
									   that specifies the sense control mode for the external interrupt.


Overall, the ST_EXT_INTERRUPTS_CFG structure provides a way to represent and manage the configuration
settings for an external interrupt on a micro-controller in a standardized and easy-to-understand manner.
By using this structure, the software can configure and handle external interrupts based on the desired
interrupt number and sense control mode, and execute the appropriate ISR when the interrupt is triggered.
*/
typedef struct
{
	void(*INTERRUPT_EXTERNAL_HANDLER)(void);
	EN_EXT_INTERRUPTS EXTERNAL_INTERRUPRT_Number;
	EN_EXT_INTERRUPT_Sense_Control EXTERNAL_INTERRUPRT_Sense_Control;

}ST_EXT_INTERRUPTS_CFG;



#endif /* MCAL_INTERRUPT_EXTERNAL_INTERRUPT_EXT_INTERRUPT_CONFIG_H_ */
