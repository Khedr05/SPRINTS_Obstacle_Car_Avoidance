/*
 * lcd_interface.h
 *
 * Created: 5/18/2023 7:13:51 PM
 *  Author: Momen
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_




void LCD_Init(void);
void LCD_WriteChar(Uchar8_t ch);
void LCD_WriteString(Uchar8_t*str);
void LCD_WriteNumber(Sint32_t num);
void LCD_SetCursor(Uchar8_t line,Uchar8_t cell);
void LCD_Clear(void);
void LCD_PinsInit ();



#endif /* LCD_INTERFACE_H_ */