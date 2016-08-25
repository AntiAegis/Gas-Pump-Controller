/*
 *	File			:	LCD_162_1_0_1.h
 *	Date created	:	08/08/2016
 *	Author			:	Nguyen Chinh Thuy
 *	Tool			:	CCS6.1.2.00015 (C programming)
 *	Current version	:	1.0.1
 *	Description		:	Construct LCD 16x2 library
 *	Target object	:	MSP430G2553
 */
/**************************************************************************************************
 *	IMPORT
 *************************************************************************************************/
#include "LCD_162_1_0_1.h"


/**************************************************************************************************
 *	DEFINITIONs
 *************************************************************************************************/

 
/**************************************************************************************************
 *	GLOBALs
 *************************************************************************************************/


/**************************************************************************************************
 *	FUNCTIONs
 *************************************************************************************************/
/*
 * 	Function:	
 *	Purpose	:	
 * 	Input	:	
 * 	Output	:	
 */
//Khoi tao lcd
void LCD_Init()					//Cac lenh Init co delay dai hon binh thuong de dam bao chac chan
{	
	//Khoi tao chuc nang I/O
	PSELLCD  &= ~(0xF0>>SHIFT_DATA);		//Chon chuc nang I/O
	PSEL2LCD &= ~(0xF0>>SHIFT_DATA);
	DDRLCD   |=  (0xF0>>SHIFT_DATA);		//Chon xuat du lieu cho 4 chan data
	PRENLCD  &= ~(0xF0>>SHIFT_DATA);		//Khong co dien tro noi keo len
	PORTLCD  &= ~(0xF0>>SHIFT_DATA);		//Dau ra muc thap

	DDR_E    |=  E;
	DDR_RS   |=  RS;
	PORT_RS  &= ~RS;
	PORT_E   &= ~E;

	__delay_cycles(lcd_delay*40);				  //delay 1.64mS
	LCD_Init_write(0x20);					//4 bit mode					   //delay 40uS
	LCD_Command(0x28);	
	_delay_cycles(lcd_delay);
	LCD_Command(0x0C);					  // Bat hien thi,tat con tro					  //delay 40uS
	///////////////////////////////////////////
	_delay_cycles(lcd_delay);
	LCD_Command(6);						//hien thi tang va khong shift					   	//delay 40uS
	///////////////////////////////////////////
	__delay_cycles(lcd_delay);
	LCD_Command(0x01);						//Xoa man hinh hien thi
	///////////////////////////////////////////
	__delay_cycles(lcd_delay*40);				   //delay 1.64mS
	LCD_Command(0x02);						  //Tro ve dau dong
	__delay_cycles(lcd_delay*40);				  //delay 1.64mS
}

//Ghi du lieu 8 bit len lcd ban dau
void LCD_Init_write(unsigned char b)		//Cac lenh Init co delay dai hon binh thuong de dam bao chac chan
{
	PORTLCD &= ~(0xF0 >> SHIFT_DATA);
	PORT_RS &= ~RS;
	__delay_cycles(lcd_delay*40);
	b &= 0xF0;
	PORTLCD |= (b >> SHIFT_DATA);
	PORT_E  |= E;
	__delay_cycles(lcd_delay);
	PORT_E &= ~E;
	__delay_cycles(lcd_delay*40);
}



//Ham goi lenh vao LCD
void LCD_Command(unsigned char chr)
{
	unsigned char HNib,LNib,temp_data; 
	temp_data = (PORTLCD & ~(0xF0 >> SHIFT_DATA));
	HNib = (chr & 0xF0);
	LNib = ((chr<<4) & 0xF0);
	
	PORTLCD = ((HNib >> SHIFT_DATA) | temp_data);
	PORTLCD = ((HNib >> SHIFT_DATA) | temp_data);
	PORT_E |=  E;
	PORT_E &= ~E ;
	__delay_cycles(lcd_delay);
	
	PORTLCD = ((LNib >> SHIFT_DATA) | temp_data);
	PORTLCD = ((LNib >> SHIFT_DATA) | temp_data);
	PORT_E |=  E;
	PORT_E &= ~E;
	__delay_cycles(lcd_delay);
}

//Doc du lieu tu LCD
char LCD_Read2Nib()
{
	char HNib,LNib;
	PORTLCD |= (0xF0 >> SHIFT_DATA);
	
	PORT_E |=  E;
	HNib    = ((PINLCD & (0xF0 >> SHIFT_DATA)) << SHIFT_DATA);
	PORT_E &= ~E;

	PORT_E |=E;
	LNib = ((PINLCD &(0xF0>>SHIFT_DATA))<<SHIFT_DATA);
	PORT_E &=~E;
	LNib >>= 4;
	return (HNib | LNib);
}
	
//Xoa LCD
void LCD_Clear()
{
	PORT_RS &= ~RS;
	LCD_Command(0x01);
	__delay_cycles(lcd_delay*40);
}

//Dua con tro ve home
void LCD_Home()
{
	PORT_RS &= ~RS;
	LCD_Command(0x02);
	__delay_cycles(lcd_delay*40);
}
//Hien thi ki tu
void LCD_Display(unsigned char chr)
{
	PORT_RS |= RS;
	LCD_Command(chr);
}


/* Di chuyen con tro toi vi tri hang row, cot column */
void LCD_Goto(unsigned char row, unsigned char column)
{
	PORT_RS &= ~RS;
	if(row == 2)
		LCD_Command(0xC0 + column - 1);
	else
		LCD_Command(0x80 + column - 1);
}



/* Dich chuyen con tro sang trai(direct=0) hoac sang phai(direct=1) "step" vi tri */
void LCD_CursorShift(unsigned char direct, unsigned char step)
{
	unsigned char i;
	PORT_RS &= ~RS;
	if (direct == 0)
		for(i=0; i<step; i++)
			LCD_Command(0x10);
	else
		for(i=0; i<step; i++)
			LCD_Command(0x14);
}


/* In ra man hinh xau ki tu str[] */
void LCD_PrintString(char *str)
{
	while(*str)
	{
		LCD_Display(*str);
		str++;
	}
}


/* In ra man hinh so nguyen n voi so cho hien thi bang length(chua ke vi tri cua dau) */
void LCD_PrintDecimal(long n, unsigned char length)
{
	unsigned char du,luu=length;
	// de trong 1 ki tu o dau cho hien thi dau
	if(n>=0)LCD_Display(' ');		//In so duong	
	else 
	{
		LCD_Display('-');			//In so am
		n*=-1;
	}	
	
	length--;
	LCD_CursorShift(1,length-1);	// dich con tro sang phai length-1 vi tri
	PORT_RS &=~RS;
	__delay_cycles(lcd_delay);
	LCD_DEC_CUR_SHIFT_OFF();		// chuyen sang che do in lui
	// Bat dau in lan luot cac chu so tu hang don vi
	while(length)
	{
		du = n % 10;
		n = n / 10;
		LCD_Display(0x30 + du);
		length--;
	}
	LCD_CursorShift(1,luu);		// dua con tro sang phai length+1 vi tri de in tiep
	PORT_RS &=~RS;
	__delay_cycles(lcd_delay);
	LCD_INC_CUR_SHIFT_OFF();		// chuyen lai ve che do in xuoi
}

void LCD_PrintUnDecimal(long n, unsigned char length)
{
	unsigned char du,luu=length;
	LCD_CursorShift(1,length-1);	// dich con tro sang phai length-1 vi tri
	PORT_RS &=~RS;
	__delay_cycles(lcd_delay);
	LCD_DEC_CUR_SHIFT_OFF();		// chuyen sang che do in lui
	// Bat dau in lan luot cac chu so tu hang don vi
	while(length)
	{
		du = n % 10;
		n = n / 10;
		LCD_Display(0x30 + du);
		length--;
	}
	LCD_CursorShift(1,luu+1);		// dua con tro sang phai length+1 vi tri de in tiep
	PORT_RS &=~RS;
	__delay_cycles(lcd_delay);
	LCD_INC_CUR_SHIFT_OFF();		// chuyen lai ve che do in xuoi
	
	
}

/* In ra man hinh so thuc x voi so cho hien thi = length, so chu so sau dau phay la coma */
void LCD_PrintFloat(float x, unsigned char length, unsigned char coma)
{
	// de trong 1 ki tu o dau cho hien thi dau
	if(x>=0)LCD_Display(' ');
	else 
	{
		LCD_Display('-');			//In so am
		x*=-1;
	}
	unsigned long n;
	unsigned char store,temp;
	store = length;						// Luu lai do dai so thuc.
	length--;								// Giam di 1 cho dau "."						
	for(temp=0;temp<coma;temp++)
		x = x*10;
	
	n = x;									// Chuyan thanh so nguyen.
	if((x-n)>=0.5)n++;

	LCD_CursorShift(1,length);				// Dich chuyen con tro sang phai
	PORT_RS &=~RS;
	__delay_cycles(lcd_delay);
	LCD_DEC_CUR_SHIFT_OFF();				// Chuyen sang che do in nguoc.

	while(coma)								// In ra phan truoc dau phay
	{
		temp = n % 10;
		n = n / 10;
		LCD_Display(0x30 + temp);
		coma--;
		length--;
	}

	LCD_Display('.');							// In ra dau "."
	
		while(length)							// In ra phan thap phan
		{
			temp = n % 10;
			n = n / 10;
			//if(temp!=n)
			LCD_Display(0x30 + temp);			
			length--;
		}
	PORT_RS &=~RS;
	__delay_cycles(lcd_delay);
	LCD_INC_CUR_SHIFT_OFF();				// Chuyen lai che do in thuan.
	LCD_CursorShift(1,store+1);					// Nhay den vi tri tiep theo.
}
//-------------------------------------------------------------------------------------------------
/*
 * 	Function:	
 *	Purpose	:	
 * 	Input	:	
 * 	Output	:	
 */
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
 *	END OF LCD_162_1_0_1.c
 *************************************************************************************************/
