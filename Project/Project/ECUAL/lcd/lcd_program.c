/*
 * lcd_program.c
 *
 * Created: 5/18/2023 7:13:27 PM
 *  Author: Momen
 */ 


#define  F_CPU 1000000UL
#include <util/delay.h>
#include "../../MCAL/dio/dio.h"
#include "lcd_cfg.h"
#include "lcd_interface.h"


#if LCD_MODE==_8_BIT
static void WriteIns(Uchar8_t ins)
{
	DIO_writepin(RS,LOW);
	DIO_WritePort(LCD_PORT,ins);
	DIO_writepin(EN,HIGH);
	_delay_ms(1);
	DIO_writepin(EN,LOW);
	_delay_ms(1);
}

static void WriteData(Uchar8_t data)
{
	DIO_writepin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_writepin(EN,HIGH);
	_delay_ms(1);
	DIO_writepin(EN,LOW);
	_delay_ms(1);
}



void LCD_Init(void)
{
	
	_delay_ms(100);
	
	WriteIns(M_5X7_2lines);//5*7 2 lines
	WriteIns(Display_ON_No_C);//0x0c,0x0e,0x0f cursor
	WriteIns(CLR_INS);//clear screen
	_delay_ms(1);
	WriteIns(increment_No_shift);// increment DDRAM address, no shift
	CLEAR_BIT(DIO_PORTA_PORT_REG,2);
	
}

#elif LCD_MODE ==_4_BIT


static void WriteIns(Uchar8_t ins)
{
	DIO_writepinn(RS,LOW);
	DIO_writepinn(D7,GET_BIT(ins,P7));
	DIO_writepinn(D6,GET_BIT(ins,P6));
	DIO_writepinn(D5,GET_BIT(ins,P5));
	DIO_writepinn(D4,GET_BIT(ins,P4));
	DIO_writepinn(EN,HIGH);
	_delay_ms(1);
	DIO_writepinn(EN,LOW);
	_delay_ms(1);
	DIO_writepinn(D7,GET_BIT(ins,P3));
	DIO_writepinn(D6,GET_BIT(ins,P2));
	DIO_writepinn(D5,GET_BIT(ins,P1));
	DIO_writepinn(D4,GET_BIT(ins,P0));
	DIO_writepinn(EN,HIGH);
	_delay_ms(1);
	DIO_writepinn(EN,LOW);
	_delay_ms(1);
}
static void WriteData(Uchar8_t data)
{
	
	DIO_writepinn(RS,HIGH);
	DIO_writepinn(D7,GET_BIT(data,P7));
	DIO_writepinn(D6,GET_BIT(data,P6));
	DIO_writepinn(D5,GET_BIT(data,P5));
	DIO_writepinn(D4,GET_BIT(data,P4));

	DIO_writepinn(EN,HIGH);
	_delay_ms(1);
	DIO_writepinn(EN,LOW);
	_delay_ms(1);
	DIO_writepinn(D7,GET_BIT(data,P3));
	DIO_writepinn(D6,GET_BIT(data,P2));
	DIO_writepinn(D5,GET_BIT(data,P1));
	DIO_writepinn(D4,GET_BIT(data,P0));
	DIO_writepinn(EN,HIGH);
	_delay_ms(1);
	DIO_writepinn(EN,LOW);
	_delay_ms(1);
}



void LCD_Init(void)
{
	LCD_PinsInit();
	_delay_ms(100);
	WriteIns(0x02);
	WriteIns(0x28);//5*7 2 lines
	WriteIns(0x0c);//0x0c,0x0e,0x0f cursor
	WriteIns(0x01);//clear screen
	_delay_ms(1);
	WriteIns(0x06);// increment DDRAM address, no shift
}

#endif

//should be send address in ddram befor this function
void LCD_WriteChar(Uchar8_t ch)
{
	WriteData(ch);
}
void LCD_WriteString(Uchar8_t*str)
{
	Uchar8_t i;
	for (i=0;str[i];i++)
	{
		LCD_WriteChar(str[i]);
	}
	
}
void LCD_SetCursor(Uchar8_t line,Uchar8_t cell)
{
	if (line==0)
	{
		WriteIns(0x80|cell);
	}
	else if (line ==1)
	{
		WriteIns(0x80+0x40+cell);
	}
	
}
void LCD_Clear(void)
{
	WriteIns(CLR_INS);
	_delay_ms(1);
}


void LCD_WriteNumber(Sint32_t num)
{
	Uchar8_t str[10],i=0,j;
	if (num==0)
	{
		LCD_WriteChar('0');
		return;
	}
	if (num<0)
	{
		num=num*(-1);
		LCD_WriteChar('-');
	}
	
	while(num)
	{
		str[i]=num%10 +'0';
		i++;
		num=num/10;
	}
	for (j=i;j>0;j--)
	{
		LCD_WriteChar(str[j-1]);
	}

}
void LCD_WriteBinary(Uchar8_t num)
{
	Schar8_t i;
	for (i=7;i>=0;i--)
	{
		LCD_WriteChar(GET_BIT(num,i)+'0');
	}
	
}
void LCD_ClearLoc(Uchar8_t line ,Uchar8_t cell,Uchar8_t num)
{
	Uchar8_t i;
	LCD_SetCursor(line,cell);
	for (i=0;i<num;i++)
	{
		LCD_WriteChar(' ');
	}
	
}
void LCD_WriteNumber_3D(Uint16_t num)
{
	//LCD_WriteChar(((num%100000)/10000)+'0');
	LCD_WriteChar(((num%10000)/1000)+'0');
	LCD_WriteChar(((num%1000)/100)+'0');
	LCD_WriteChar(((num%100)/10)+'0');
	LCD_WriteChar(((num%10)/1)+'0');
}
void LCD_CustomChar(Uchar8_t loc,Uchar8_t*pattern)
{
	WriteIns(0x40+loc*8);
	for(Uchar8_t i=0;i<8;i++)
	{
		WriteData(pattern[i]);
	}
	WriteIns(0x80);
}
void LCD_PinsInit ()
{
	DIO_initpinn(RS,OUTPUT);
	DIO_initpinn(EN,OUTPUT);
	DIO_initpinn(RW,OUTPUT);
	DIO_initpinn(D4,OUTPUT);
	DIO_initpinn(D5,OUTPUT);
	DIO_initpinn(D6,OUTPUT);
	DIO_initpinn(D7,OUTPUT);

}