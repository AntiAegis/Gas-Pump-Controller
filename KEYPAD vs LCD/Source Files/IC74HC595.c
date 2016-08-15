/*
 *	File			:	IC74HC595.c
 *	Date created	:	13/08/2016
 *	Author			:	Nguyen Chinh Thuy
 *	Tool			:	CCS6.1.2.00015 (C programming)
 *	Current version	:	1.0.1
 *	Description		:	Source for IC 74HC595
 *	Target object	:	MSP430G2553
 */
#define	USE_NOTIFIER_MCU
#define	USE_CLOCK_1_2_3
/**************************************************************************************************
 *	IMPORT
 *************************************************************************************************/
#include "main.h"


/**************************************************************************************************
 *	EXTERNs
 *************************************************************************************************/
extern unsigned char varCount;

extern unsigned int regFirmStatus;
extern unsigned int regFirmOvf;
extern unsigned int regFirmEnalbe;
extern unsigned int regFirmPeriod;
extern unsigned int regFirmDuty;

extern unsigned char varFirmNum;
extern unsigned char varFirmMode;


/**************************************************************************************************
 *	FUNCTIONs
 *************************************************************************************************/
/*
 * 	Function:	ic74hc595GetData
 *	Purpose	:	Shift data into 74HC595
 * 	Input	:	varData: Data needed to shift
 * 	Output	:	None
 */
void ic74hc595GetData (unsigned char varData)
{
	unsigned char varCount;
	gpioLow(PIN_74HC595_SHCP);
	for(varCount = 0; varCount < 8; varCount++)
	{
		if(varData & BIT7)
		{
			gpioHigh(PIN_74HC595_DS);
		}
		else
		{
			gpioLow(PIN_74HC595_DS);
		}
		varData = (varData << 1);
		gpioHigh(PIN_74HC595_SHCP);
		gpioLow(PIN_74HC595_SHCP);
	}
}
//-------------------------------------------------------------------------------------------------
/*
 * 	Function:	ic74hc595Latch
 *	Purpose	:	Latch the output
 * 	Input	:	None
 * 	Output	:	None
 */
void ic74hc595Latch (void)
{
	gpioLow(PIN_74HC595_STCP);
	__delay_cycles(5);
	gpioHigh(PIN_74HC595_STCP);
	gpioLow(PIN_74HC595_STCP);
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
 *	END OF IC74HC595.c
 *************************************************************************************************/
