#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

// Private constants and macros
#define DIO_PORTA_OFFSET 0x00
#define DIO_PORTB_OFFSET 0x01
#define DIO_PORTC_OFFSET 0x02
#define DIO_PORTD_OFFSET 0x03

#define DIO_PORTA_DDR_REG *((volatile Uchar8_t*) (0x3A))
#define DIO_PORTA_PORT_REG *((volatile Uchar8_t*) (0x3B))
#define DIO_PORTA_PIN_REG  *((volatile Uchar8_t*) (0x39))

#define DIO_PORTB_DDR_REG *((volatile Uchar8_t*) (0x37))
#define DIO_PORTB_PORT_REG *((volatile Uchar8_t*) (0x38))
#define DIO_PORTB_PIN_REG  *((volatile Uchar8_t*) (0x36))

#define DIO_PORTC_DDR_REG *((volatile Uchar8_t*) (0x34))
#define DIO_PORTC_PORT_REG *((volatile Uchar8_t*) (0x35))
#define DIO_PORTC_PIN_REG  *((volatile Uchar8_t*) (0x33))

#define DIO_PORTD_DDR_REG *((volatile Uchar8_t*) (0x31))
#define DIO_PORTD_PORT_REG *((volatile Uchar8_t*) (0x32))
#define DIO_PORTD_PIN_REG  *((volatile Uchar8_t*) (0x30))


#endif /* DIO_PRIVATE_H */