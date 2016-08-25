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
 *	GLOBALs
 *************************************************************************************************/
extern volatile unsigned char arrCommunication[I2C_NUM_BYTE] = {0, 0, 0, 0};


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
	arrCommunication[0] = (regFirmTimeOn & (MATH_BCD_UNIT + MATH_BCD_DECI));							// Low
	arrCommunication[1] = (unsigned char)((regFirmTimeOn & (MATH_BCD_HUND + MATH_BCD_THOU)) >> 8);		// High
	arrCommunication[2] = (regFirmTimeOff & (MATH_BCD_UNIT + MATH_BCD_DECI));							// Low
	arrCommunication[3] = (unsigned char)((regFirmTimeOff & (MATH_BCD_HUND + MATH_BCD_THOU)) >> 8);		// High
}
//-------------------------------------------------------------------------------------------------
/*
 * 	Function:
 *	Purpose	:
 * 	Input	:
 * 	Output	:
 */
void communicationDecode (unsigned int varModeSel)
{
	switch (varModeSel)
	{
		case FIRM_STT_MODE_SEL_A:
			regFirmTimeOnA  = (arrCommunication[0] | (arrCommunication[1] << 8));
			regFirmTimeOffA = (arrCommunication[2] | (arrCommunication[3] << 8));
			break;
		case FIRM_STT_MODE_SEL_B:
			regFirmTimeOnB  = (arrCommunication[0] | (arrCommunication[1] << 8));
			regFirmTimeOffB = (arrCommunication[2] | (arrCommunication[3] << 8));
			break;
		case FIRM_STT_MODE_SEL_C:
			regFirmTimeOnC  = (arrCommunication[0] | (arrCommunication[1] << 8));
			regFirmTimeOffC = (arrCommunication[2] | (arrCommunication[3] << 8));
			break;
	}
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
