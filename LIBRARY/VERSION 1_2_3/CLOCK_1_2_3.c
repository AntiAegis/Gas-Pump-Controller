/*
 * 	File			:	CLOCK_1_2_3.c
 * 	Author			:	Nguyen Chinh Thuy
 *	Date created	:	31/05/2016
 *	Tool			: 	CCS6.1.2.00015
 *	Current version	:	1.2.3
 *	Description		:	Construct Clock library
 */
/**************************************************************************************************
 *	IMPORT
 *************************************************************************************************/
#include "CLOCK_1_2_3.h"


/**************************************************************************************************
 *	GLOBALs
 *************************************************************************************************/
/* Mode struct array */
extern volatile clk_Setup sClkSetup =
{
	{// DCO_1MHZ
			{// SWDT_ON
					CLK_DCO_1MHZ,
					SWDT_ON
			},
			{// SWDT_OFF
					CLK_DCO_1MHZ,
					SWDT_OFF
			}
	},
	{// DCO_8MHZ
			{// SWDT_ON
					CLK_DCO_8MHZ,
					SWDT_ON
			},
			{// SWDT_OFF
					CLK_DCO_8MHZ,
					SWDT_OFF
			}
	},
	{// DCO_12MHZ
			{// SWDT_ON
					CLK_DCO_12MHZ,
					SWDT_ON
			},
			{// SWDT_OFF
					CLK_DCO_12MHZ,
					SWDT_OFF
			}
	},
	{// DCO_16MHZ
			{// SWDT_ON
					CLK_DCO_16MHZ,
					SWDT_ON
			},
			{// SWDT_OFF
					CLK_DCO_16MHZ,
					SWDT_OFF
			}
	}
};


/**************************************************************************************************
 *	FUNCTIONs
 *************************************************************************************************/
/*
 *	Function:	clkSetup
 *	Purpose	:	Setup clock module
 *	Input	: 	Mode struct path
 *	Output	:	None
 */
void clkSetup (const clk_Wdt sClkSetup)
{
	switch (sClkSetup.CLK_)
	{
		case CLK_DCO_1MHZ:
		{
			BCSCTL1  = CALBC1_1MHZ;
			DCOCTL   = CALDCO_1MHZ;
			break;
		}
		case CLK_DCO_8MHZ:
		{
			BCSCTL1  = CALBC1_8MHZ;
			DCOCTL   = CALDCO_8MHZ;
			break;
		}
		case CLK_DCO_12MHZ:
		{
			BCSCTL1  = CALBC1_12MHZ;
			DCOCTL   = CALDCO_12MHZ;
			break;
		}
		case CLK_DCO_16MHZ:
		{
			BCSCTL1  = CALBC1_16MHZ;
			DCOCTL   = CALDCO_16MHZ;
			break;
		}
		default:
		{
			break;
		}
	}
	if (sClkSetup.SWDT_ == SWDT_ON)
	{
		WDTCTL = WDTPW + WDTHOLD;	// Stop watchdog timer
	}
	else
	{
		WDTCTL &= ~(WDTPW + WDTHOLD);	// Don't stop watchdog timer
	}
}


/**************************************************************************************************
 *	END OF CLOCK_1_2_3.c
 *************************************************************************************************/
