/*
 *	File			:	GPIO_1_2_3.h
 *	Date created	:	31/05/2016
 *	Author			:	Nguyen Chinh Thuy
 *	Tool			:	CCS6.1.2.00015 (C programming)
 *	Current version	:	1.2.3
 *	Description		:	Construct Clock library
 *	Target object	:	MSP430G2553
 */
/**************************************************************************************************
 *						PROGRESS
 *		This is the version 1.2.1 of this library about Clock.
 *		In the version 1.0.1, functions operate with parameters as const unsigned char/int numbers.
 *		In the version 1.1.1, all const parameters, which are transfered into functions, are repla-
 *	ced by structs. In file source, we provide some structs that contain usual modes of configurat-
 *	ion, users just need to declare them by key-word "extern" in main.c file for taking these ones.
 *	Otherwise, people can also create new structs and transfer them into functions.
 *		This version is released at 03/06/2016. In this version, we reconstruct structs becoming a
 *	system of struct (struct inside struct). Thank to this feature, users don't need to pay attent-
 *	ion to what modes are availably supporting. When using functions, we think it will be well as -
 *	you make struct pointers pointing to "struct paths", e.g. &sClkSetup.DCO_1MHZ.SWDT_ON, then put
 *	them into functions.
 *		We recommend that if your purpose is variable, you should use version 1.0.1, and if you wa-
 *	nt to operate your chip in some specific modes, you should create structs and version 1.1.1 is
 *	the better choice for you. Yet, considering to version 1.2.1 as things mentioned above.
 *************************************************************************************************/
#ifndef CLOCK_1_2_3_H_
#define CLOCK_1_2_3_H_
/**************************************************************************************************
 *	IMPORT
 *************************************************************************************************/
#include <msp430.h>


/**************************************************************************************************
 *	DEFINITIONs
 *************************************************************************************************/
/* DCO Oscillator and frequency */
#define		CLK_DCO_1MHZ		1
#define		CLK_DCO_8MHZ		8
#define		CLK_DCO_12MHZ		12
#define		CLK_DCO_16MHZ		16

/* Stop Wacthdog Timer */
#define		SWDT_ON				1
#define		SWDT_OFF			0

/* Some special delay intervals */
//-(Base on frequency = 1MHz)-//
//-s-//
#define		DL_10S				10000000
#define		DL_5S				5000000
#define		DL_2S				2000000
#define		DL_1S				1000000
//-ms-//
#define		DL_500MS			500000
#define		DL_100MS			100000
#define		DL_50MS				50000
#define		DL_10MS				10000
#define		DL_5MS				5000
#define		DL_1MS				1000

/* Structs for clkSetup function */
typedef struct
{
	const unsigned int CLK_;	// What oscillator is and what frequency is?
	const unsigned int SWDT_;	// Stop Watchdog timer or not?
} clk_Wdt;
typedef struct
{
	clk_Wdt sSwdtOn;	// Turn on Stop Watchdog Timer
	clk_Wdt sSwdtOff;	// Turn off Stop Watchdog Timer
} clk_Ocs_Fre;
typedef struct
{
	clk_Ocs_Fre sDco1mhz;
	clk_Ocs_Fre sDco8mhz;
	clk_Ocs_Fre sDco12mhz;
	clk_Ocs_Fre sDco16mhz;
} clk_Setup;

extern volatile clk_Setup sClkSetup;


/**************************************************************************************************
 *	FUNCTION'S PROTOTYPEs
 *************************************************************************************************/
/* Setup */
void clkSetup (const clk_Wdt sClkSetup);


/**************************************************************************************************
 *	END OF CLOCK_1_2_3.h
 *************************************************************************************************/
#endif /* CLOCK_1_2_3_H_ */
