/*
 *	File			:	LCD.c
 *	Date created	:	10/08/2016
 *	Author			:	Nguyen Chinh Thuy
 *	Tool			:	CCS6.1.2.00015 (C programming)
 *	Current version	:	1.0.1
 *	Description		:	Source for LCD
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
 * 	Function:
 *	Purpose	:
 * 	Input	:
 * 	Output	:
 */
void lcdNotifyOverFlowDigit (unsigned int varPeDu)
{
	LCD_Clear();
	LCD_Home();
	LCD_PrintString("Digit Overflow?!");
	__delay_cycles(DL_1S);
	LCD_Clear();
	LCD_Home();
	LCD_PrintString("Mode "); LCD_Display(varFirmMode); LCD_Display(':');
	LCD_Goto(2, 2);
	if(varPeDu == FIRM_STT_PERIOD)
	{
		LCD_PrintString("Period=");
		LCD_Display((unsigned char)mathBcdThou(regFirmPeriod) + 48);
		LCD_Display((unsigned char)mathBcdHund(regFirmPeriod) + 48);
		LCD_Display((unsigned char)mathBcdDeci(regFirmPeriod) + 48);
		LCD_Display((unsigned char)mathBcdUnit(regFirmPeriod) + 48);
	}
	if(varPeDu == FIRM_STT_DUTY)
	{
		LCD_PrintString("Duty=");
		LCD_Display((unsigned char)mathBcdThou(regFirmDuty) + 48);
		LCD_Display((unsigned char)mathBcdHund(regFirmDuty) + 48);
		LCD_Display((unsigned char)mathBcdDeci(regFirmDuty) + 48);
		LCD_Display((unsigned char)mathBcdUnit(regFirmDuty) + 48);
	}
}
//-------------------------------------------------------------------------------------------------
/*
 * 	Function:
 *	Purpose	:
 * 	Input	:
 * 	Output	:
 */
void lcdNotifyNullValue (unsigned int varPeDu)
{
	LCD_Clear();
	LCD_Home();
	if(varPeDu == FIRM_STT_PERIOD)
	{
		LCD_PrintString("Period=0?!");
		__delay_cycles(DL_1S);
		LCD_Clear();
		LCD_Home();
		LCD_PrintString("Mode "); LCD_Display(varFirmMode); LCD_Display(':');
		LCD_Goto(2, 2);
		LCD_PrintString("Period=");
	}
	if(varPeDu == FIRM_STT_DUTY)
	{
		LCD_PrintString("Duty=0?!");
		__delay_cycles(DL_1S);
		LCD_Clear();
		LCD_Home();
		LCD_PrintString("Mode "); LCD_Display(varFirmMode); LCD_Display(':');
		LCD_Goto(2, 2);
		LCD_PrintString("Duty=");
	}
}
//-------------------------------------------------------------------------------------------------
/*
 * 	Function:
 *	Purpose	:
 * 	Input	:
 * 	Output	:
 */
void lcdNotifyExit (void)
{
	LCD_Clear();
	LCD_Home();
	LCD_PrintString("Select a mode...");
}
//-------------------------------------------------------------------------------------------------
/*
 * 	Function:
 *	Purpose	:
 * 	Input	:
 * 	Output	:
 */
void lcdNotifyMode (unsigned char varMode)
{
	LCD_Clear();
	LCD_Home();
	LCD_PrintString("Mode ");
	LCD_Display(varMode);
	LCD_Display(':');
}
//-------------------------------------------------------------------------------------------------
/*
 * 	Function:	lcdNotifyConfirm
 *	Purpose	:	Notify confirm completely
 * 	Input	:	None
 * 	Output	:	None
 */
void lcdNotifyConfirm (void)
{
	LCD_Clear();
	LCD_Home();
	LCD_PrintString("    Confirm    ");
	LCD_Goto(2,1);
	LCD_PrintString("  completely!  ");
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
 *	END OF LCD.c
 *************************************************************************************************/
