/*
 * keypad_config.h
 *
 * Created: 5/16/2023 3:23:08 PM
 *  Author: Sharpel
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_




/* according to number of rows you need to define Rx pins here we have just one row so we define R1 only*/
#define NUMBER_OF_ROWS 1
#define KEPAD_PORT  DIO_PORTA
#define R1    2
//#define R2 DIO_PINA_1
//#define R3 DIO_PINA_2
//#define R4 DIO_PINA_3


/* according to number of cols you need to define Cx pins here we have just two cols so we define C1 and C2*/
#define NUMBER_OF_COLS 2

#define C1 5
#define C2 6
//#define C3 DIO_PINA_6
//#define C4 DIO_PINA_7



/* enum to define all keys we can change it according to our keypad size (we need two keys only) */
typedef enum EN_KEYPAD_KEYS{
	KEY_NOTHING = 0 ,
	KEY_1 ,
	KEY_2 ,
	//KEY_3 ,
	//KEY_4 ,
	//KEY_5 ,
	//KEY_6 ,
	//KEY_7 ,
	//KEY_8 ,
	//KEY_9 ,
	//KEY_10 ,
	//KEY_11,
	//KEY_12 ,
	//KEY_13 ,
	//KEY_14 ,
	//KEY_15 ,
	//KEY_16 ,
	
}EN_KEYPAD_KEYS;

/* this struct contain all keypad configs */
typedef struct ST_KEYPAD_CONFIG{
	
	/* array that holds all cols pins */
	DIO_ConfigType u8_arr_cols[NUMBER_OF_COLS];
	
	/* array that holds all rows pins */
	DIO_ConfigType u8_arr_rows[NUMBER_OF_ROWS];
	
	/* 2D array that holds all keys values according to it's position [row][col] */
	EN_KEYPAD_KEYS u8_arr_keys[NUMBER_OF_ROWS][NUMBER_OF_COLS];
}ST_KEYPAD_CONFIG;



#endif /* KEYPAD_CONFIG_H_ */