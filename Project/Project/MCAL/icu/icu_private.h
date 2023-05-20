/*
 * icu_private.h
 *
 * Created: 5/17/2023 5:56:15 AM
 *         Author: Mahmoud Mowafey - https://github.com/Mahmoud-Mowafy
 *  Description: This file contains all Direct Current Motor (DCM) functions' implementation.
 *		MCU Datasheet: AVR ATmega32
 *                  https://ww1.microchip.com/downloads/en/DeviceDoc/Atmega32A-DataSheet-Complete-DS40002072A.pdf
 */ 


#ifndef ICU_PRIVATE_H_
#define ICU_PRIVATE_H_

 /*
  * 16-bit Timer/Counter1
  */

#define	TMR_U8_TCCR1A_REG		*( ( volatile  Uchar8_t * ) 0x4F )
#define	TMR_U8_TCCR1B_REG		*( ( volatile  Uchar8_t * ) 0x4E )
#define	TMR_U8_TCNT1H_REG		*( ( volatile  Uchar8_t * ) 0x4D )
#define	TMR_U8_TCNT1L_REG		*( ( volatile  Uchar8_t * ) 0x4C )
  /* DataType is Uint16_t * in order to get both registers ( i.e. TCNT1L and TCNT1H respectively ) locations in memory */
#define TMR_U16_TCNT1_REG		*( ( volatile  Uint16_t * ) 0x4C )
#define	TMR_U8_OCR1AH_REG		*( ( volatile  Uchar8_t * ) 0x4B )
#define	TMR_U8_OCR1AL_REG		*( ( volatile  Uchar8_t * ) 0x4A )
/* DataType is Uint16_t * in order to get both registers ( i.e. OCR1AL and OCR1AH respectively ) locations in memory */
#define TMR_U16_OCR1A_REG		*( ( volatile  Uint16_t * ) 0x4A )
#define	TMR_U8_OCR1BH_REG		*( ( volatile  Uchar8_t * ) 0x49 )
#define	TMR_U8_OCR1BL_REG		*( ( volatile  Uchar8_t * ) 0x48 )
/* DataType is Uint16_t * in order to get both registers ( i.e. OCR1BL and OCR1BH respectively ) locations in memory */
#define TMR_U16_OCR1B_REG		*( ( volatile  Uint16_t * ) 0x48 )
#define	TMR_U8_ICR1H_REG		*( ( volatile  Uchar8_t * ) 0x47 )
#define	TMR_U8_ICR1L_REG		*( ( volatile  Uchar8_t * ) 0x46 )
/* DataType is Uint16_t * in order to get both registers ( i.e. ICR1L and ICR1H respectively ) locations in memory */
#define TMR_U16_ICR1_REG		*( ( volatile  Uint16_t * ) 0x46 )

/*
 * 16-bit Timer/Counter1 Registers' Description
 */

 /* Timer/Counter1 Control Register A - TCCR1A */
 /* Bit 7:6 - COM1A1:0: Compare Output Mode for Channel A */
#define TMR_U8_COM1A1_BIT		7
#define TMR_U8_COM1A0_BIT		6
/* Bit 5:4 - COM1B1:0: Compare Output Mode for Channel B */
#define TMR_U8_COM1B1_BIT		5
#define TMR_U8_COM1B0_BIT		4
/* Bit 3 - FOC1A: Force Output Compare for Channel A */
#define TMR_U8_FOC1A_BIT		3
/* Bit 2 - FOC1B: Force Output Compare for Channel B */
#define TMR_U8_FOC1B_BIT		2
/* Bit 1:0 - WGM11:0: Waveform Generation Mode */
#define TMR_U8_WGM11_BIT		1
#define TMR_U8_WGM10_BIT		0
/* End of TCCR1A Register */

/* Timer/Counter1 Control Register B - TCCR1B */
/* Bit 7 - ICNC1: Input Capture Noise Canceler */
#define TMR_U8_ICNC1_BIT		7
/* Bit 6 - ICES1: Input Capture Edge Select */
#define TMR_U8_ICES1_BIT		6
/* Bit 4:3 - WGM13:2: Waveform Generation Mode */
#define TMR_U8_WGM13_BIT		4
#define TMR_U8_WGM12_BIT		3
/* Bit 2:0 - CS12:0: Clock Select */
#define TMR_U8_CS12_BIT			2
#define TMR_U8_CS11_BIT			1
#define TMR_U8_CS10_BIT			0
/* End of TCCR1B Register */


/**
 * ISR function prototypes for External Interrupt Request 0 ( INT0 )
 * */


/* Global Interrutpt */
#define GLOBAL_INTERRUPT_ENABLE_BIT      7
#define TIMER_U8_SREG_REG            *( ( volatile Uchar8_t * ) 0x5F )

/* EXI Registers' Locations */

#define EXI_U8_MCUCR_REG		*( ( volatile Uchar8_t * ) 0x55 )
#define EXI_U8_MCUCSR_REG		*( ( volatile Uchar8_t * ) 0x54 )
#define EXI_U8_GICR_REG			*( ( volatile Uchar8_t * ) 0x5B )
#define EXI_U8_GIFR_REG			*( ( volatile Uchar8_t * ) 0x5A )

/* ***********************************************************************************************/
/* EXI Registers' Description */

/* MCU Control Register - MCUCR: Configure External Interrupt 0 & 1 */
/* Interrupt 0:
 * Bit 0, 1 -> ISC00, ISC01: Interrupt Sense Control 0
 */
#define EXI_U8_ISC00_BIT	    0
#define EXI_U8_ISC01_BIT	    1
/* Interrupt 1:
 * Bit 2, 3 -> ISC10, ISC11: Interrupt Sense Control 1
 */
#define EXI_U8_ISC10_BIT	    2
#define EXI_U8_ISC11_BIT	    3
/* End of MCUCR Register */

/* MCU Control and Status Register - MCUCSR: Configure External Interrupt 2 */
/* Interrupt 2 (Asynchronous External Interrupt):
 * Bit 6 -> ISC2: Interrupt Sense Control 2
 */
#define EXI_U8_ISC2_BIT		    6
/* End of MCUCSR Register */

/* General Interrupt Control Register - GICR: Enable External Interrupt 0, 1 and 2 */
/* Bit 6 -> INT0: External Interrupt Request 0 Enable */
#define EXI_U8_INT0_BIT		    6
/* Bit 7 -> INT1: External Interrupt Request 1 Enable */
#define EXI_U8_INT1_BIT		    7
/* Bit 5 -> INT2: External Interrupt Request 2 Enable */
#define EXI_U8_INT2_BIT		    5
/* End of GICR Register */

/* General Interrupt Flag Register - GIFR: Flags of External Interrupt 0, 1 and 2 */
/* Bit 6 -> INTF0: External Interrupt Flag 0 */
#define EXI_U8_INTF0_BIT	    6
/* Bit 7 -> INTF1: External Interrupt Flag 1 */
#define EXI_U8_INTF1_BIT	    7
/* Bit 5 -> INTF2: External Interrupt Flag 2 */
#define EXI_U8_INTF2_BIT	    5
/* End of GIFR Register */

/* The 3 External Interrupts counted from 0 to 2 */
#define EXI_U8_INT0						0
#define EXI_U8_INT1 					1
#define EXI_U8_INT2 					2

/* Interrupts Sense Control */
#define EXI_U8_SENSE_LOW_LEVEL			0
#define EXI_U8_SENSE_LOGICAL_CHANGE		1
#define EXI_U8_SENSE_FALLING_EDGE		2
#define EXI_U8_SENSE_RISING_EDGE		3

/* ***********************************************************************************************/
/* EXI Functions' Prototypes */




#endif /* ICU_PRIVATE_H_ */