/*
 *	File			:	main.h
 *	Date created	:	10/08/2016
 *	Author			:	Nguyen Chinh Thuy
 *	Tool			:	CCS6.1.2.00015 (C programming)
 *	Current version	:	1.0.1
 *	Description		:	Header of source files
 *	Target object	:	MSP430G2553
 */
#ifndef MAIN_H_
#define MAIN_H_
/**************************************************************************************************
 *	IMPORT
 *************************************************************************************************/
#include <msp430g2553.h>					// From producer
#include <stdio.h>							// C standard
#include "VERSION 1_2_3/CLOCK_1_2_3.h"		// Struct inside struct
#include "VERSION 1_0_1/GPIO_1_0_1.h"		// Const parameters
#include "VERSION 1_0_1/LCD_162_1_0_1.h"	// Normal
#include "VERSION 2_0_1/USCI_I2C_2_0_1.h"	// Const parameters


/**************************************************************************************************
 *	DEFINITIONs
 *************************************************************************************************/
/* Pin mapping */
#define			PIN_74HC595_DS			BIT0	// P1.0
#define			PIN_74HC595_SHCP		BIT1	// P1.1
#define			PIN_74HC595_STCP		BIT2	// P1.2
#define			PIN_RESERVED_1			BIT3	// P1.3
#define			PIN_RESERVED_2			BIT4	// P1.4
#define			PIN_RESERVED_3			BIT5	// P1.5
#define			PIN_I2C_SCK				BIT6	// P1.6
#define			PIN_I2C_SDA				BIT7	// P1.7

#define			PIN_KEYPAD_IN_1			BIT0	// P2.0
#define			PIN_KEYPAD_IN_2			BIT1	// P2.1
#define			PIN_KEYPAD_IN_3			BIT2	// P2.2
#define			PIN_KEYPAD_IN_4			BIT3	// P2.3
#define			PIN_KEYPAD_OUT_1		BIT4	// P2.4
#define			PIN_KEYPAD_OUT_2		BIT5	// P2.5
#define			PIN_KEYPAD_OUT_3		BIT6	// P2.6
#define			PIN_KEYPAD_OUT_4		BIT7	// P2.7

/* Clock of system */
#define			FREQUENCY				1		// 1MHz

/* Delay interval */
#define			DL_ANTI_NOISE			50000	// 50ms
#define			DL_OUT					50000	// 50ms

/* Keypad */
#define			PIN_KEYPAD_IN			0x0F	// P2.0 -> P2.3
#define			PIN_KEYPAD_OUT			0xF0	// P2.4 -> P2.7

/* Firmware status register (16-bit) */
#define			FIRM_STT_MODE_SEL		BIT0	// Mode sellect
#define			FIRM_STT_EXIT_SEL		BIT1	// Exit sellect
#define			FIRM_STT_CLEAR			BIT2	// Clear number
#define			FIRM_STT_CONFIRM		BIT3	// Confirm number
#define			FIRM_STT_GET_NUM		BIT4	// Get number
#define			FIRM_STT_PERIOD			BIT5	// Get period
#define			FIRM_STT_DUTY			BIT6	// Get duty
#define			FIRM_STT_DIGIT1			BIT7	// 0 (first digit), 1 (second digit)
#define			FIRM_STT_DIGIT2			BIT8	// 0 (third digit), 1 (fourth digit)
#define			FIRM_STT_RESERVED_1		BIT9	// Reserved
#define			FIRM_STT_RESERVED_2		BIT10	// Reserved
#define			FIRM_STT_RESERVED_3		BIT11	// Reserved
#define			FIRM_STT_RESERVED_4		BIT12	// Reserved
#define			FIRM_STT_RESERVED_5		BIT13	// Reserved
#define			FIRM_STT_RESERVED_6		BIT14	// Reserved
#define			FIRM_STT_RESERVED_7		BIT15	// Reserved
#define			FIRM_STT_DIGIT			(FIRM_STT_DIGIT1 + FIRM_STT_DIGIT2)	// For all of digits

/* Firmware overflow register (16-bit) */
#define			FIRM_OVF_DIGIT			BIT0	// Digit overflow
#define			FIRM_OVF_CONFIRM		BIT1	// Confirm overflow
#define			FIRM_OVF_RESERVED_1		BIT2	// Reserved
#define			FIRM_OVF_RESERVED_2		BIT3	// Reserved
#define			FIRM_OVF_RESERVED_3		BIT4	// Reserved
#define			FIRM_OVF_RESERVED_4		BIT5	// Reserved
#define			FIRM_OVF_RESERVED_5		BIT6	// Reserved
#define			FIRM_OVF_RESERVED_6		BIT7	// Reserved
#define			FIRM_OVF_RESERVED_7		BIT8	// Reserved
#define			FIRM_OVF_RESERVED_8		BIT9	// Reserved
#define			FIRM_OVF_RESERVED_9		BIT10	// Reserved
#define			FIRM_OVF_RESERVED_10	BIT11	// Reserved
#define			FIRM_OVF_RESERVED_11	BIT12	// Reserved
#define			FIRM_OVF_RESERVED_12	BIT13	// Reserved
#define			FIRM_OVF_RESERVED_13	BIT14	// Reserved
#define			FIRM_OVF_RESERVED_14	BIT15	// Reserved

/* Firmware enable register (16-bit) */
#define			FIRM_EN_MODE_A			BIT0	// Mode Sellect A
#define			FIRM_EN_MODE_B			BIT1	// Mode Sellect B
#define			FIRM_EN_MODE_C			BIT2	// Mode Sellect C
#define			FIRM_EN_MODE_D			BIT3	// Mode Exit
#define			FIRM_EN_RESERVED_1		BIT4	// Reserved
#define			FIRM_EN_RESERVED_2		BIT5	// Reserved
#define			FIRM_EN_RESERVED_3		BIT6	// Reserved
#define			FIRM_EN_RESERVED_4		BIT7	// Reserved
#define			FIRM_EN_RESERVED_5		BIT8	// Reserved
#define			FIRM_EN_RESERVED_6		BIT9	// Reserved
#define			FIRM_EN_RESERVED_7		BIT10	// Reserved
#define			FIRM_EN_RESERVED_8		BIT11	// Reserved
#define			FIRM_EN_RESERVED_9		BIT12	// Reserved
#define			FIRM_EN_RESERVED_10		BIT13	// Reserved
#define			FIRM_EN_RESERVED_11		BIT14	// Reserved
#define			FIRM_EN_RESERVED_12		BIT15	// Reserved

/* I2C communication */
#define			I2C_ADDR_SLAVE			0x48	// Address of slave
#define			I2C_PASSWORD			0x11	// Password of communicatting frame
#define			I2C_NUM_BYTE			4		// these 4 bytes for data, one more byte for password

/* LED 7-segment font */
#define			LED_7SEG_FONT_0			0x3F	// Number 0
#define			LED_7SEG_FONT_1			0x06	// Number 1
#define			LED_7SEG_FONT_2			0x5B	// Number 2
#define			LED_7SEG_FONT_3			0x4F	// Number 3
#define			LED_7SEG_FONT_4			0x66	// Number 4
#define			LED_7SEG_FONT_5			0x6D	// Number 5
#define			LED_7SEG_FONT_6			0x7D	// Number 6
#define			LED_7SEG_FONT_7			0x47	// Number 7
#define			LED_7SEG_FONT_8			0x7F	// Number 8
#define			LED_7SEG_FONT_9			0x6F	// Number 9
#define			LED_7SEG_FONT_NULL		0x00	// Nul symbol
#define			LED_7SEG_FONT_ERROR		0x40	// Error symbol
#define			LED_7SEG_FONT_LENGTH	12

/* Math */
#define			MATH_LIMIT_NUMBER		999		// The maximum number can be used
#define			MATH_LIMIT_NUMBER_BCD	0x0999	// The maximum BCD number can be used
#define			MATH_LIMIT_DIGIT		3		// Just use 3 LED to dislay 3 digits of number

#define			MATH_BCD_UNIT_SHIFT		0		// Shift used in calculate BCD for unit digit
#define			MATH_BCD_DECI_SHIFT		4		// Shift used in calculate BCD for decimal digit
#define			MATH_BCD_HUND_SHIFT		8		// Shift used in calculate BCD for hundred digit
#define			MATH_BCD_THOU_SHIFT		12		// Shift used in calculate BCD for thousand digit

#define			MATH_ORGI_UNIT			0		// Orginal of unit digit
#define			MATH_ORGI_DECIMAL		1		// Orginal of decimal digit
#define			MATH_ORGI_HUNDRED		2		// Orginal of hundred digit
#define			MATH_ORGI_THOUSAND		3		// Orginal of thousand digit

#define			MATH_BCD_UNIT			0x000F	// 4 BCD unit bits
#define			MATH_BCD_DECI			0x00F0	// 4 BCD decimal bits
#define			MATH_BCD_HUND			0x0F00	// 4 BCD hundred bits
#define			MATH_BCD_THOU			0xF000	// 4 BCD thousand bits


/**************************************************************************************************
 *	GLOBALs
 *************************************************************************************************/
#ifndef USE_NOTIFIER_MCU

	/* Keypad */
	unsigned char varCount;
	unsigned char arrOut[4] = {0xEF, 0xDF, 0xBF, 0x7F};

	/* Communication */
	unsigned char arrCommunication[I2C_NUM_BYTE];

	/* LED 7-segment */
	unsigned char arrLed7segNum[LED_7SEG_FONT_LENGTH] =
	{LED_7SEG_FONT_0, LED_7SEG_FONT_1, LED_7SEG_FONT_2, LED_7SEG_FONT_3, LED_7SEG_FONT_4,
	 LED_7SEG_FONT_5, LED_7SEG_FONT_6, LED_7SEG_FONT_7, LED_7SEG_FONT_8, LED_7SEG_FONT_9,
	 LED_7SEG_FONT_ERROR, LED_7SEG_FONT_NULL};

	/* Firmware */
	unsigned int regFirmStatus;		// Firmware status register
	unsigned int regFirmOvf;		// Firmware overflow register
	unsigned int regFirmPeriod;		// Firmware period data register
	unsigned int regFirmDuty;		// Firmware duty data register
	unsigned int regFirmEnalbe;		// Firmware enable register

	unsigned char varFirmNum;		// Stores gotten number from keypad
	unsigned char varFirmMode;		// Stores gotten mode from keypad

#endif /* USE_NOTIFY_MCU */


/**************************************************************************************************
 *	FUNCTION'S PROTOTYPEs
 *************************************************************************************************/
/* Keypad */
void keypadButtonIdentify	(unsigned char regPortIfg);
void keypadSetRegSttMode	(unsigned char varMode);
void keypadSetRegSttControl (unsigned char varControl);
void keypadSetRegSttNum 	(unsigned char varNum);

/* LCD */
void lcdNotifyOverFlowDigit (unsigned int varPeDu);
void lcdNotifyNullValue		(unsigned int varPeDu);
void lcdNotifyExit			(void);
void lcdNotifyMode			(unsigned char varMode);
void lcdNotifyConfirm		(void);

/* Led 7-segment */
void led7segDisplayNumber	(unsigned int varPeriod, unsigned int varDuty);
void led7segNotifyConfirm	(void);
void led7segNotifyError		(void);
void led7segNotifyExit		(void);

/* 74HC595 */
void ic74hc595GetData	(unsigned char varData);
void ic74hc595Latch		(void);

/* Communication */
void communicationEncode	(void);
void communicationTransmit  (void);

/* Math */
unsigned int mathBcdUnit 		(unsigned int varNumber);
unsigned int mathBcdDeci 		(unsigned int varNumber);
unsigned int mathBcdHund 		(unsigned int varNumber);
unsigned int mathBcdThou 		(unsigned int varNumber);
void		 mathGetBCDNumber	(unsigned int varPeDu, unsigned char varDigit, unsigned char varPosition);

/* Firmware */
void 			firmwareConfirm 			(void);
void 			firmwareClearTempValue 		(unsigned int varPeDu);
void 			firmwareNullValue 			(unsigned int varPeDu);
void			firmwareExit				(void);
void 			firmwareConfirmNextValue 	(void);
void			firmwareConfirmAllValue 	(void);
unsigned char 	firmwareGetDigitOrdinal 	(void);
void 			firmwareFirstDigit 			(unsigned int varPeDu);
void 			firmwareSecondDigit 		(unsigned int varPeDu);
void			firmwareThirdDigit 			(unsigned int varPeDu);
void			firmwareFourthDigit 		(unsigned int varPeDu);
void 			firmwareInputValue 			(unsigned int varPeDu);
void			firmwareEnalbe 				(unsigned int varEnable);
void			firmwareCheckEnable 		(unsigned int varCheck);


/**************************************************************************************************
 *	END OF main.h
 *************************************************************************************************/
#endif /* MAIN_H_ */
