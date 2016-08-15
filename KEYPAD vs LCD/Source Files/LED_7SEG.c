/*
 *	File			:	LED_7SEG.c
 *	Date created	:	13/08/2016
 *	Author			:	Nguyen Chinh Thuy
 *	Tool			:	CCS6.1.2.00015 (C programming)
 *	Current version	:	1.0.1
 *	Description		:	Source for LED 7-segment
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

extern unsigned char arrLed7segNum[];


/**************************************************************************************************
 *	FUNCTIONs
 *************************************************************************************************/
/*
 * 	Function:	led7segDisplayNumber
 *	Purpose	:
 * 	Input	:
 * 	Output	:
 */
void led7segDisplayNumber (unsigned int varPeriod, unsigned int varDuty)
{
	if(varDuty <= MATH_LIMIT_NUMBER_BCD)
	{
		ic74hc595GetData(arrLed7segNum[mathBcdUnit(varDuty)]);			// Unit digit
		ic74hc595GetData(arrLed7segNum[mathBcdDeci(varDuty)]);			// Decimal digit
		ic74hc595GetData(arrLed7segNum[mathBcdHund(varDuty)]);			// Hundred digit

		if(varPeriod <= MATH_LIMIT_NUMBER_BCD)
		{
			ic74hc595GetData(arrLed7segNum[mathBcdUnit(varPeriod)]);	// Unit digit
			ic74hc595GetData(arrLed7segNum[mathBcdDeci(varPeriod)]);	// Decimal digit
			ic74hc595GetData(arrLed7segNum[mathBcdHund(varPeriod)]);	// Hundred digit
			ic74hc595Latch();											// Export data into LED 7-segment
		}
	}
}
//-------------------------------------------------------------------------------------------------
/*
 * 	Function:	led7segNotifyConfirm
 *	Purpose	:
 * 	Input	:
 * 	Output	:
 */
void led7segNotifyConfirm (void)
{
	ic74hc595GetData(LED_7SEG_FONT_NULL);
	ic74hc595GetData(LED_7SEG_FONT_NULL);
	ic74hc595GetData(LED_7SEG_FONT_NULL);
	ic74hc595GetData(LED_7SEG_FONT_NULL);
	ic74hc595GetData(LED_7SEG_FONT_NULL);
	ic74hc595GetData(LED_7SEG_FONT_NULL);
	ic74hc595Latch();
	__delay_cycles(DL_500MS);

	led7segDisplayNumber(regFirmPeriod, regFirmDuty);
	__delay_cycles(DL_500MS);

	ic74hc595GetData(LED_7SEG_FONT_NULL);
	ic74hc595GetData(LED_7SEG_FONT_NULL);
	ic74hc595GetData(LED_7SEG_FONT_NULL);
	ic74hc595GetData(LED_7SEG_FONT_NULL);
	ic74hc595GetData(LED_7SEG_FONT_NULL);
	ic74hc595GetData(LED_7SEG_FONT_NULL);
	ic74hc595Latch();
	__delay_cycles(DL_500MS);

	led7segDisplayNumber(regFirmPeriod, regFirmDuty);
}
//-------------------------------------------------------------------------------------------------
/*
 * 	Function:	led7segNotifyError
 *	Purpose	:
 * 	Input	:
 * 	Output	:
 */
void led7segNotifyError (void)
{
	ic74hc595GetData(LED_7SEG_FONT_ERROR);
	ic74hc595GetData(LED_7SEG_FONT_ERROR);
	ic74hc595GetData(LED_7SEG_FONT_ERROR);
	ic74hc595GetData(LED_7SEG_FONT_ERROR);
	ic74hc595GetData(LED_7SEG_FONT_ERROR);
	ic74hc595GetData(LED_7SEG_FONT_ERROR);
	ic74hc595Latch();
	__delay_cycles(DL_1S);

	led7segDisplayNumber(regFirmPeriod, regFirmDuty);
}
//-------------------------------------------------------------------------------------------------
/*
 * 	Function:	led7segNotifyExit
 *	Purpose	:
 * 	Input	:
 * 	Output	:
 */
void led7segNotifyExit (void)
{
	ic74hc595GetData(LED_7SEG_FONT_NULL);
	ic74hc595GetData(LED_7SEG_FONT_NULL);
	ic74hc595GetData(LED_7SEG_FONT_NULL);
	ic74hc595GetData(LED_7SEG_FONT_NULL);
	ic74hc595GetData(LED_7SEG_FONT_NULL);
	ic74hc595GetData(LED_7SEG_FONT_NULL);
	ic74hc595Latch();
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
 *	END OF LED_7SEG.c
 *************************************************************************************************/
