/*
 *	File			:	MATH.c
 *	Date created	:	13/08/2016
 *	Author			:	Nguyen Chinh Thuy
 *	Tool			:	CCS6.1.2.00015 (C programming)
 *	Current version	:	1.0.1
 *	Description		:	Source for Mathematic
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

extern unsigned char arrCommunication[I2C_NUM_BYTE];


/**************************************************************************************************
 *	FUNCTIONs
 *************************************************************************************************/
/*
 * 	Function:
 *	Purpose	:
 * 	Input	:
 * 	Output	:
 */
unsigned int mathBcdUnit (unsigned int varNumber)
{
	return ((varNumber & MATH_BCD_UNIT) >> MATH_BCD_UNIT_SHIFT);
}
//-------------------------------------------------------------------------------------------------
/*
 * 	Function:
 *	Purpose	:
 * 	Input	:
 * 	Output	:
 */
unsigned int mathBcdDeci (unsigned int varNumber)
{
	return ((varNumber & MATH_BCD_DECI) >> MATH_BCD_DECI_SHIFT);
}
//-------------------------------------------------------------------------------------------------
/*
 * 	Function:
 *	Purpose	:
 * 	Input	:
 * 	Output	:
 */
unsigned int mathBcdHund (unsigned int varNumber)
{
	return ((varNumber & MATH_BCD_HUND) >> MATH_BCD_HUND_SHIFT);
}
//-------------------------------------------------------------------------------------------------
/*
 * 	Function:
 *	Purpose	:
 * 	Input	:
 * 	Output	:
 */
unsigned int mathBcdThou (unsigned int varNumber)
{
	return ((varNumber & MATH_BCD_THOU) >> MATH_BCD_THOU_SHIFT);
}
//-------------------------------------------------------------------------------------------------
/*
 * 	Function:	mathGetBCDNumber
 *	Purpose	:
 * 	Input	:
 * 	Output	:
 */
void mathGetBCDNumber (unsigned int varPeDu, unsigned char varDigit, unsigned char varPosition)
{
	if(varPeDu == FIRM_STT_PERIOD)
	{
		if(varPosition == MATH_ORGI_UNIT)
		{
			regFirmPeriod = (varDigit & 0x0F);
		}
		else if ((varPosition == MATH_ORGI_DECIMAL) || (varPosition == MATH_ORGI_HUNDRED) ||
				 (varPosition == MATH_ORGI_THOUSAND))
		{
			regFirmPeriod = ((regFirmPeriod << 4) | (varDigit & 0x0F));
		}
	}
	if(varPeDu == FIRM_STT_DUTY)
	{
		if(varPosition == MATH_ORGI_UNIT)
		{
			regFirmDuty = (varDigit & 0x0F);
		}
		else if ((varPosition == MATH_ORGI_DECIMAL) || (varPosition == MATH_ORGI_HUNDRED) ||
				 (varPosition == MATH_ORGI_THOUSAND))
		{
			regFirmDuty = ((regFirmDuty << 4) | (varDigit & 0x0F));
		}
	}
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
 *	END OF COMMUNICATION.c
 *************************************************************************************************/
