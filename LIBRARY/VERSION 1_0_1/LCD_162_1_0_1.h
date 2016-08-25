////////////////////////////////////////////////////////////////////
// THU VIEN DINH NGHIA CAC HAM XU LY LCD 16x2
// VIET BOI : PHAM VAN THUAN	DTVT07-K55
// Version : 1.0	14/10/2014
// Email:	phthuanbk55@gmail.com
// Blog :	http://thuanbk55.blogspot.com/
// .................................................................
// MSP430 LIBRARY
//******************************************************************/
#ifndef LCD_162_1_0_1_H_
#define LCD_162_1_0_1_H_

#include <msp430.h>
//Khai bao su dung LCD

//#define USE_WAIT

#define lcd_delay 	500
//Set PIN DATA
#define DDRLCD 		P1DIR
#define PORTLCD 	P1OUT
#define PINLCD		P1IN
#define PRENLCD		P1REN
#define PSELLCD		P1SEL
#define PSEL2LCD	P1SEL2
#define SHIFT_DATA	4		// vi tri dich trai so voi vi tri goc 0xF0
//Set PIN RS
#define DDR_RS		P1DIR
#define PORT_RS		P1OUT
#define PIN_RS		P1IN
#define RS   		BIT5	//0x02
//Set PIN E
#define DDR_E		P1DIR
#define PORT_E		P1OUT
#define PIN_E		P1IN
#define E    		BIT4	//0x08

/* Chon kieu hien thi tang/giam, shift hoac khong shift */
#define LCD_DEC_CUR_SHIFT_ON()	LCD_Command(0x05);
#define LCD_DEC_CUR_SHIFT_OFF()	LCD_Command(0x04);
#define LCD_INC_CUR_SHIFT_ON()	LCD_Command(0x07);
#define LCD_INC_CUR_SHIFT_OFF()	LCD_Command(0x06);	// khuyen khich su dung cach nay

/******************************************************************************\
*					Prototype (nguyen mau ham)    						       *
\******************************************************************************/

void LCD_Init_write(unsigned char b);		  //Ghi du lieu 8bit len lcd
void LCD_Command(unsigned char chr); 	  //ghi 2 nibbles vao lcd
char LCD_Read2Nib();	
void LCD_Init();				              //khoi dong lcd
void LCD_Clear();			                  //xoa lcd
void LCD_Home();	
void LCD_Display(unsigned char chr);          //hien thi ki tu 
void LCD_Goto(unsigned char row, unsigned char column);       /* Di chuyen con tro toi vi tri hang row, cot column */
/* Dich chuyen con tro sang trai(direct=0) hoac sang phai(direct=1) "step" vi tri */
void LCD_CursorShift(unsigned char direct, unsigned char step);
void LCD_PrintString(char *str);				/* In ra man hinh xau ki tu str[] */
/* In ra man hinh so nguyen n voi so cho hien thi bang length(chua ke vi tri cua dau) */
void LCD_PrintDecimal(long n, unsigned char length);
/* In ra man hinh so thuc x voi so cho hien thi = length, so chu so sau dau phay la coma */
void LCD_PrintUnDecimal(long n, unsigned char length);
void LCD_PrintFloat(float x, unsigned char length, unsigned char coma);


#endif /* LCD_162_1_0_1_H_ */
