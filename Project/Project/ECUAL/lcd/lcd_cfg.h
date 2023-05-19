/*
 * lcd_cfg.h
 *
 * Created: 5/18/2023 7:14:12 PM
 *  Author: Momen
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_


#define M_5X7_2lines          0x38
#define Display_ON_No_C       0x0c
#define Display_ON_C          0x0e
#define Display_ON_C_Blanking 0x0f
#define CLR_INS               0x01
#define increment_No_shift    0X06

#define _4_BIT   0
#define _8_BIT   1

/* _4_BIT OR _8_BIT*/
#define  LCD_MODE  _4_BIT



#define  RS   1
#define  RW   2
#define  EN   3
#define  D7   7
#define  D6   6
#define  D5   5
#define  D4   4

#define  P7   7
#define  P6   6
#define  P5   5
#define  P4   4
#define  P3   3
#define  P2   2
#define  P1   1
#define  P0   0
#define LCD_PORT  DIO_PORTA





#endif /* LCD_CFG_H_ */