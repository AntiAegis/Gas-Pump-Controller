/*
 *	File			:	COMMUNICATION.c
 *	Date created	:	11/08/2016
 *	Author			:	Nguyen Chinh Thuy
 *	Tool			:	CCS6.1.2.00015 (C programming)
 *	Current version	:	1.0.1
 *	Description		:	Source for communication (I2C)
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
void communicationEncode (void)
{
	arrCommunication[0] = (regFirmPeriod & (MATH_BCD_UNIT + MATH_BCD_DECI));							// Low
	arrCommunication[1] = (unsigned char)((regFirmPeriod & (MATH_BCD_HUND + MATH_BCD_THOU)) >> 8);		// High
	arrCommunication[2] = (regFirmDuty & (MATH_BCD_UNIT + MATH_BCD_DECI));								// Low
	arrCommunication[3] = (unsigned char)((regFirmDuty & (MATH_BCD_HUND + MATH_BCD_THOU)) >> 8);		// High
}
//-------------------------------------------------------------------------------------------------
/*
 * 	Function:
 *	Purpose	:
 * 	Input	:
 * 	Output	:
 */
void communicationTransmit (void)
{
	i2cMstWriteByte(I2C_PASSWORD);			// Password
	__delay_cycles(DL_100MS * FREQUENCY);							// Safe delay
	i2cMstWriteByte(arrCommunication[0]);	// First byte (Low)
	__delay_cycles(DL_100MS * FREQUENCY);							// Safe delay
	i2cMstWriteByte(arrCommunication[1]);	// Second byte (High)
	__delay_cycles(DL_100MS * FREQUENCY);							// Safe delay
	i2cMstWriteByte(arrCommunication[2]);	// Third byte (Low)
	__delay_cycles(DL_100MS * FREQUENCY);							// Safe delay
	i2cMstWriteByte(arrCommunication[3]);	// Fourth byte (High)
	__delay_cycles(DL_100MS * FREQUENCY);							// Safe delay
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
