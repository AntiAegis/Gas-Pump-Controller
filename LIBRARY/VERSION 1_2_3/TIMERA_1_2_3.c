/*
 * 	File			:	TIMERA_1_2_3.c
 * 	Author			:	Nguyen Chinh Thuy
 *	Date created	:	03/06/2016
 *	Tool			: 	CCS6.1.2.00015
 *	Current version	:	1.2.1
 *	Description		:	Construct TimerA library
 */
 #define USE_TIMERA_1_2_3
/**************************************************************************************************
 *	IMPORT
 *************************************************************************************************/
#include "TIMERA_1_2_3.h"


/**************************************************************************************************
 *	DEFINITIONs
 *************************************************************************************************/
extern const timer_A_Setup sTimerASetup;
extern const timer_A_Cap_Setup sTimerACapSetup;
extern const timer_A_Cmp_Setup sTimerACmpSetup;
extern const pwm_Setup sPwmSetup;
 

/**************************************************************************************************
 *	FUNCTIONs
 *************************************************************************************************/
/*
 * Function : timerASetup
 * Input	: Struct with type of timer_A_Setup
 * Output	: Setup TimerA
 */
void timerASetup (timer_Int sTimerASetup_, unsigned int varTarInit, unsigned int varCcr0Init)
{
	if(sTimerASetup_.TIMER_A_ == TIMER_A_0)
	{
		TA0CTL = TASSEL_2 + sTimerASetup_.MODE_ + sTimerASetup_.DIV_ + sTimerASetup_.INT_OVF_;
		TA0R = varTarInit;
		TA0CCR0 = varCcr0Init;			// Used in Up mode and Up/Down mode
		if (sTimerASetup_.INT_OVF_ == INT_OVF_ON)
		{
			__bis_SR_register(GIE);
		}
	}
	if(sTimerASetup_.TIMER_A_ == TIMER_A_1)
	{
		TA1CTL = TASSEL_2 + sTimerASetup_.MODE_ + sTimerASetup_.DIV_ + sTimerASetup_.INT_OVF_;
		TA1R = varTarInit;
		TA1CCR0 = varCcr0Init;			// Used in Up mode and Up/Down mode
		if (sTimerASetup_.INT_OVF_ == INT_OVF_ON)
		{
			__bis_SR_register(GIE);
		}
	}
}
//-------------------------------------------------------------------------------------------------
/*
 * Function : 	timerASetup
 * Purpose	:	Stop timerA operation
 * Input	:	TIMER_A_0 or TIMER_A_1
 * Output	: 	None
 */
void timerAStop (const char TIMER_A_)
{
	if(TIMER_A_ == TIMER_A_0)
	{
		TA0CTL &= 0xFFCF;
	}
	if(TIMER_A_ == TIMER_A_1)
	{
		TA1CTL &= 0xFFCF;
	}
}
//-------------------------------------------------------------------------------------------------
/*
 * Function :	timerACapSetup
 * Purpose	:	Setup timerA Capture
 * Input	:	Struct inside struct
 * Output	:	None
 */
void timerACapSetup (timer_A_Cap_Int sTimerACapSetup_)
{
	if(sTimerACapSetup_.TIMER_A_ == TIMER_A_0)
	{
		if(sTimerACapSetup_.CCR_ == CCR_0)
		{
			if(sTimerACapSetup_.CHANNEL_ == CHANNEL_A)
			{
				P1SEL   |=  BIT1;
				P1SEL2  &= ~BIT1;
				P1DIR   &= ~BIT1;
				TA0CCTL0 = CAPTURE + sTimerACapSetup_.MODE_ + sTimerACapSetup_.CHANNEL_ + sTimerACapSetup_.INT_CC_;
				TA0R = 0;
				if(sTimerACapSetup_.INT_CC_ == INT_CC_ON)
				{
					__bis_SR_register(GIE);
				}
				TA0CCTL0 &= ~COV;
			}
		}
		if(sTimerACapSetup_.CCR_ == CCR_1)
		{
			if(sTimerACapSetup_.CHANNEL_ == CHANNEL_A)
			{
				P1SEL   |=  BIT2;
				P1SEL2  &= ~BIT2;
				P1DIR   &= ~BIT2;
				TA0CCTL1 = CAPTURE + sTimerACapSetup_.MODE_ + sTimerACapSetup_.CHANNEL_ + sTimerACapSetup_.INT_CC_;
				TA0R = 0;
				if(sTimerACapSetup_.INT_CC_ == INT_CC_ON)
				{
					__bis_SR_register(GIE);
				}
				TA0CCTL1 &= ~COV;
			}
		}
	}
	if(sTimerACapSetup_.TIMER_A_ == TIMER_A_1)
	{
		if(sTimerACapSetup_.CCR_ == CCR_0)
		{
			if(sTimerACapSetup_.CHANNEL_ == CHANNEL_A)
			{
				P2SEL   |=  BIT0;
				P2SEL2  &= ~BIT0;
				P2DIR   &= ~BIT0;
				TA1CCTL0 = CAPTURE + sTimerACapSetup_.MODE_ + sTimerACapSetup_.CHANNEL_ + sTimerACapSetup_.INT_CC_;
				TA1R = 0;
				if(sTimerACapSetup_.INT_CC_ == INT_CC_ON)
				{
					__bis_SR_register(GIE);
				}
				TA1CCTL0 &= ~COV;
			}
			if(sTimerACapSetup_.CHANNEL_ == CHANNEL_B)
			{
				P2SEL   |=  BIT3;
				P2SEL2  &= ~BIT3;
				P2DIR   &= ~BIT3;
				TA1CCTL0 = CAPTURE + sTimerACapSetup_.MODE_ + sTimerACapSetup_.CHANNEL_ + sTimerACapSetup_.INT_CC_;
				TA1R = 0;
				if(sTimerACapSetup_.INT_CC_ == INT_CC_ON)
				{
					__bis_SR_register(GIE);
				}
				TA1CCTL0 &= ~COV;
			}
		}
		if(sTimerACapSetup_.CCR_ == CCR_1)
		{
			if(sTimerACapSetup_.CHANNEL_ == CHANNEL_A)
			{
				P2SEL   |=  BIT1;
				P2SEL2  &= ~BIT1;
				P2DIR   &= ~BIT1;
				TA1CCTL1 = CAPTURE + sTimerACapSetup_.MODE_ + sTimerACapSetup_.CHANNEL_ + sTimerACapSetup_.INT_CC_;
				TA1R = 0;
				if(sTimerACapSetup_.INT_CC_ == INT_CC_ON)
				{
					__bis_SR_register(GIE);
				}
				TA1CCTL1 &= ~COV;
			}
			if(sTimerACapSetup_.CHANNEL_ == CHANNEL_B)
			{
				P2SEL   |=  BIT2;
				P2SEL2  &= ~BIT2;
				P2DIR   &= ~BIT2;
				TA1CCTL1 = CAPTURE + sTimerACapSetup_.MODE_ + sTimerACapSetup_.CHANNEL_ + sTimerACapSetup_.INT_CC_;
				TA1R = 0;
				if(sTimerACapSetup_.INT_CC_ == INT_CC_ON)
				{
					__bis_SR_register(GIE);
				}
				TA1CCTL1 &= ~COV;
			}
		}
		if(sTimerACapSetup_.CCR_ == CCR_2)
		{
			if(sTimerACapSetup_.CHANNEL_ == CHANNEL_A)
			{
				P2SEL   |=  BIT4;
				P2SEL2  &= ~BIT4;
				P2DIR   &= ~BIT4;
				TA1CCTL2 = CAPTURE + sTimerACapSetup_.MODE_ + sTimerACapSetup_.CHANNEL_ + sTimerACapSetup_.INT_CC_;
				TA1R = 0;
				if(sTimerACapSetup_.INT_CC_ == INT_CC_ON)
				{
					__bis_SR_register(GIE);
				}
				TA1CCTL2 &= ~COV;
			}
			if(sTimerACapSetup_.CHANNEL_ == CHANNEL_B)
			{
				P2SEL   |=  BIT5;
				P2SEL2  &= ~BIT5;
				P2DIR   &= ~BIT5;
				TA1CCTL2 = CAPTURE + sTimerACapSetup_.MODE_ + sTimerACapSetup_.CHANNEL_ + sTimerACapSetup_.INT_CC_;
				TA1R = 0;
				if(sTimerACapSetup_.INT_CC_ == INT_CC_ON)
				{
					__bis_SR_register(GIE);
				}
				TA1CCTL2 &= ~COV;
			}
		}
	}
}
//-------------------------------------------------------------------------------------------------
/*
 * Function :	timerACmpSetup
 * Purpose	:	Setup timerA Compare
 * Input	: 	Struct inside struct
 * Output	: 	None
 */
void timerACmpSetup (timer_A_Cmp_Int sTimerACmpSetup_, unsigned int varCcrInit)
{
	if(sTimerACmpSetup_.TIMER_A_ == TIMER_A_0)
	{
		if(sTimerACmpSetup_.CCR_ == CCR_0)
		{
			TA0CCTL0 = sTimerACmpSetup_.INT_CC_;
			TA0CCR0 = varCcrInit;
			if(sTimerACmpSetup_.INT_CC_ == INT_CC_ON)
			{
				__bis_SR_register(GIE);
			}
		}
		if(sTimerACmpSetup_.CCR_ == CCR_1)
		{
			TA0CCTL1 = sTimerACmpSetup_.INT_CC_;
			TA0CCR1 = varCcrInit;
			if(sTimerACmpSetup_.INT_CC_ == INT_CC_ON)
			{
				__bis_SR_register(GIE);
			}
		}
		if(sTimerACmpSetup_.CCR_ == CCR_2)
		{
			TA0CCTL2 = sTimerACmpSetup_.INT_CC_;
			TA0CCR2 = varCcrInit;
			if(sTimerACmpSetup_.INT_CC_ == INT_CC_ON)
			{
				__bis_SR_register(GIE);
			}
		}
	}
	if(sTimerACmpSetup_.TIMER_A_ == TIMER_A_1)
	{
		if(sTimerACmpSetup_.CCR_ == CCR_0)
		{
			TA1CCTL0 = sTimerACmpSetup_.INT_CC_;
			TA1CCR0 = varCcrInit;
			if(sTimerACmpSetup_.INT_CC_ == INT_CC_ON)
			{
				__bis_SR_register(GIE);
			}
		}
		if(sTimerACmpSetup_.CCR_ == CCR_1)
		{
			TA1CCTL1 = sTimerACmpSetup_.INT_CC_;
			TA1CCR1 = varCcrInit;
			if(sTimerACmpSetup_.INT_CC_ == INT_CC_ON)
			{
				__bis_SR_register(GIE);
			}
		}
		if(sTimerACmpSetup_.CCR_ == CCR_2)
		{
			TA1CCTL2 = sTimerACmpSetup_.INT_CC_;
			TA1CCR2 = varCcrInit;
			if(sTimerACmpSetup_.INT_CC_ == INT_CC_ON)
			{
				__bis_SR_register(GIE);
			}
		}
	}
}
//-------------------------------------------------------------------------------------------------
/*
 * Function : pwmSetup
 * Input	: Struct with type of pwm_Setup
 * Output	: Setup PWM module of TimerA
 */
void pwmSetup (pwm_Out sPwmSetup_, unsigned int varPeriod, unsigned int varDuty)
{
	if(sPwmSetup_.TIMER_A_ == TIMER_A_0)
	{
		if(sPwmSetup_.MODE_ == MODE_UP)		// Output: P1.2 & P1.6
		{
			P1DIR |= sPwmSetup_.PIN_;
			P1SEL |= sPwmSetup_.PIN_;
			P1SEL2 &= ~sPwmSetup_.PIN_;
			TA0CCTL1 = sPwmSetup_.PWM_;
			TA0CCR0 = varPeriod;
			if((sPwmSetup_.PWM_ == PWM_TG_RST) || (sPwmSetup_.PWM_ == PWM_SET_RST))	//Mode 2 & 3
			{
				TA0CCR1 = varPeriod - varDuty;
			}
			if((sPwmSetup_.PWM_ == PWM_TG_SET) || (sPwmSetup_.PWM_ == PWM_RST_SET))	//Mode 6 & 7
			{
				TA0CCR1 = varDuty;
			}
		}
	}
	if(sPwmSetup_.TIMER_A_ == TIMER_A_1)
	{
		if(sPwmSetup_.MODE_ == MODE_UP)		// Output: P2.1 & P2.2
		{
			P2DIR |= sPwmSetup_.PIN_;
			P2SEL |= sPwmSetup_.PIN_;
			P2SEL2 &= ~sPwmSetup_.PIN_;
			TA1CCTL1 = sPwmSetup_.PWM_;
			TA1CCR0 = varPeriod;
			if((sPwmSetup_.PWM_ == PWM_TG_RST) || (sPwmSetup_.PWM_ == PWM_SET_RST))	//Mode 2 & 3
			{
				TA1CCR1 = varPeriod - varDuty;
			}
			if((sPwmSetup_.PWM_ == PWM_TG_SET) || (sPwmSetup_.PWM_ == PWM_RST_SET))	//Mode 6 & 7
			{
				TA1CCR1 = varDuty;
			}
		}
	}
}


/****************************************************************************************
 *	END OF TIMERA_1_2_3.c
 ***************************************************************************************/
