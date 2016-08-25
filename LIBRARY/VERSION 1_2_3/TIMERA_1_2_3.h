/*
 * 	File			:	TIMERA_1_2_3.h
 * 	Author			:	Nguyen Chinh Thuy
 *	Date created	:	03/06/2016
 *	Tool			: 	CCS6.1.2.00015
 *	Current version	:	1.2.3
 *	Description		:	Construct TimerA library
 */

#ifndef TIMERA_1_2_3_H_
#define TIMERA_1_2_3_H_
/**************************************************************************************************
 *	IMPORT
 *************************************************************************************************/
#include <msp430.h>


/**************************************************************************************************
 *	DEFINITIONs
 *************************************************************************************************/
/* TimerA */
#define		TIMER_A_0			0			// TimerA0
#define		TIMER_A_1			1			// TimerA1

/* Timer modes */
#define		MODE_UP				MC_1		// Up mode
#define		MODE_CONTI			MC_2		// Continuous mode
#define		MODE_UPDOWN			MC_3		// Up/down mode

/* Overflow interrupt */
#define		INT_OVF_OFF			0			// Disable Overflow interrupt
#define		INT_OVF_ON			TAIE		// Enable Overflow interrupt

/* Capture/Compare */
#define		CAPTURE				CAP			// Capture
#define		COMPARE				0			// Compare

/* Modules of Capture and Compare */
#define		CCR_0				0			// TimerAx_A0
#define		CCR_1				1			// TimerAx_A1
#define		CCR_2				2			// TimerAx_A2

/* Capture modes */
#define		CAP_OFF				CM_0		// No capture
#define		CAP_RISING			CM_1		// Capture in rising edge
#define		CAP_FALLING			CM_2		// Capture in falling edge
#define		CAP_BOTH			CM_3		// Capture in both edges

/* Channels of Capture */
#define		CHANNEL_A			CCIS_0		// Channel A
#define		CHANNEL_B			CCIS_1		// Channel B
#define		CHANNEL_GND			CCIS_2		// Channel GND
#define		CHANNEL_VCC			CCIS_3		// Channel VCC

/* Outmodes */
#define		PWM_OUTBIT			OUTMOD_0	// OUT bit value
#define		PWM_SET				OUTMOD_1	// Set
#define		PWM_TG_RST			OUTMOD_2	// Toggle/Reset
#define		PWM_SET_RST			OUTMOD_3	// Set/Reset
#define		PWM_TG				OUTMOD_4	// Toggle
#define		PWM_RST				OUTMOD_5	// Reset
#define		PWM_TG_SET			OUTMOD_6	// Toggle/Set
#define		PWM_RST_SET			OUTMOD_7	// Reset/Set

/* Output pins */
#define		P1_2				BIT2		// P1.2
#define		P1_6				BIT6		// P1.6
#define		P2_1				BIT1		// P2.1
#define		P2_2				BIT2		// P2.2

/* Capture/Compare interrupt */
#define		INT_CC_ON			CCIE		// Enable Capture/Compare interrupt
#define		INT_CC_OFF			0			// Disable Capture/Compare interrupt

/* Struct for timerASetup function */
typedef struct
{
	const char TIMER_A_;
	const unsigned int MODE_;
	const unsigned int DIV_;
	const unsigned int INT_OVF_;
} timer_Int;
typedef struct
{
	timer_Int sTimerIntOvfOn;
	timer_Int sTimerIntOvfOff;
} timer_Divider;
typedef struct
{
	timer_Divider sTimerDiv1;
	timer_Divider sTimerDiv2;
	timer_Divider sTimerDiv4;
	timer_Divider sTimerDiv8;
} timer_Mode;
typedef struct
{
	timer_Mode sTimerModeUp;
	timer_Mode sTimerModeContinuous;
	timer_Mode sTimerModeUpDown;
} timer_A;
typedef struct
{
	timer_A sTimerA0Setup;
	timer_A sTimerA1Setup;
} timer_A_Setup;

/* Struct for timerACapSetup function */
typedef struct
{
	const char TIMER_A_;
	const unsigned int CCR_;
	const unsigned int CHANNEL_;
	const unsigned int MODE_;
	const unsigned int INT_CC_;
} timer_A_Cap_Int;
typedef struct
{
	timer_A_Cap_Int sIntCcOn;
	timer_A_Cap_Int sIntCcOff;
} timer_A_Cap_Mode;
typedef struct
{
	timer_A_Cap_Mode sRising;
	timer_A_Cap_Mode sFalling;
	timer_A_Cap_Mode sBoth;
} timer_A_Pin;
typedef struct
{
	timer_A_Pin sP1_1;
} timer_A0_CCR0;
typedef struct
{
	timer_A_Pin sP1_2;
} timer_A0_CCR1;
typedef struct
{
	timer_A_Pin sP2_0;
	timer_A_Pin sP2_3;
} timer_A1_CCR0;
typedef struct
{
	timer_A_Pin sP2_1;
	timer_A_Pin sP2_2;
} timer_A1_CCR1;
typedef struct
{
	timer_A_Pin sP2_4;
	timer_A_Pin sP2_5;
} timer_A1_CCR2;
typedef struct
{
	timer_A0_CCR0 sCCR0;
	timer_A0_CCR1 sCCR1;
} timer_A0_Cap;
typedef struct
{
	timer_A1_CCR0 sCCR0;
	timer_A1_CCR1 sCCR1;
	timer_A1_CCR2 sCCR2;
} timer_A1_Cap;
typedef struct
{
	timer_A0_Cap sTimerA0Cap;
	timer_A1_Cap sTimerA1Cap;
} timer_A_Cap_Setup;

/* Struct for timerACmpSetup function */
typedef struct
{
	const char TIMER_A_;
	const unsigned int CCR_;
	const unsigned int INT_CC_;
} timer_A_Cmp_Int;
typedef struct
{
	timer_A_Cmp_Int sTimerCmpIntOn;
	timer_A_Cmp_Int sTimerCmpIntOff;
} timer_A_Cmp_Ccr;
typedef struct
{
	timer_A_Cmp_Ccr sTimerCmpCCR0;
	timer_A_Cmp_Ccr sTimerCmpCCR1;
	timer_A_Cmp_Ccr sTimerCmpCCR2;
} timer_A_Cmp;
typedef struct
{
	timer_A_Cmp sTimerA0Cmp;
	timer_A_Cmp sTimerA1Cmp;
} timer_A_Cmp_Setup;

/* Struct for pwmSetup function */
typedef struct
{
	const unsigned int TIMER_A_;
	const unsigned int MODE_;
	const unsigned int PIN_;
	const unsigned int PWM_;
} pwm_Out;
typedef struct
{
	pwm_Out sP1_2TgRst;
	pwm_Out sP1_2SetRst;
	pwm_Out sP1_2TgSet;
	pwm_Out sP1_2RstSet;
} pwm_P1_2;
typedef struct
{
	pwm_Out sP1_6TgRst;
	pwm_Out sP1_6SetRst;
	pwm_Out sP1_6TgSet;
	pwm_Out sP1_6RstSet;
} pwm_P1_6;
typedef struct
{
	pwm_P1_2 sP1_2;
	pwm_P1_6 sP1_6;
} pwm_A0_Up;
typedef struct
{
	pwm_Out sP2_1TgRst;
	pwm_Out sP2_1SetRst;
	pwm_Out sP2_1TgSet;
	pwm_Out sP2_1RstSet;
} pwm_P2_1;
typedef struct
{
	pwm_Out sP2_2TgRst;
	pwm_Out sP2_2SetRst;
	pwm_Out sP2_2TgSet;
	pwm_Out sP2_2RstSet;
} pwm_P2_2;
typedef struct
{
	pwm_P2_1 sP2_1;
	pwm_P2_2 sP2_2;
} pwm_A1_Up;
typedef struct
{
	pwm_A0_Up sA0ModeUp;
} pwm_A0;
typedef struct
{
	pwm_A1_Up sA1ModeUp;
} pwm_A1;
typedef struct
{
	pwm_A0 sTimerA0;
	pwm_A1 sTimerA1;
} pwm_Setup;

#ifndef USE_TIMERA_1_2_3
	//-Struct for timerASetup function-//
	const timer_A_Setup sTimerASetup =
	{
		{// TimerA0
				{// Mode up
						{// ID_0
								{TIMER_A_0, MODE_UP, ID_0, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_0, MODE_UP, ID_0, INT_OVF_OFF},// INT_OVF_OFF
						},
						{// ID_1
								{TIMER_A_0, MODE_UP, ID_1, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_0, MODE_UP, ID_1, INT_OVF_OFF},// INT_OVF_OFF
						},
						{// ID_2
								{TIMER_A_0, MODE_UP, ID_2, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_0, MODE_UP, ID_2, INT_OVF_OFF},// INT_OVF_OFF
						},
						{// ID_3
								{TIMER_A_0, MODE_UP, ID_3, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_0, MODE_UP, ID_3, INT_OVF_OFF},// INT_OVF_OFF
						},
				},
				{// Mode continuous
						{// ID_0
								{TIMER_A_0, MODE_CONTI, ID_0, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_0, MODE_CONTI, ID_0, INT_OVF_OFF},// INT_OVF_OFF
						},
						{// ID_1
								{TIMER_A_0, MODE_CONTI, ID_1, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_0, MODE_CONTI, ID_1, INT_OVF_OFF},// INT_OVF_OFF
						},
						{// ID_2
								{TIMER_A_0, MODE_CONTI, ID_2, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_0, MODE_CONTI, ID_2, INT_OVF_OFF},// INT_OVF_OFF
						},
						{// ID_3
								{TIMER_A_0, MODE_CONTI, ID_3, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_0, MODE_CONTI, ID_3, INT_OVF_OFF},// INT_OVF_OFF
						},
				},
				{// Mode up down
						{// ID_0
								{TIMER_A_0, MODE_UPDOWN, ID_0, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_0, MODE_UPDOWN, ID_0, INT_OVF_OFF},// INT_OVF_OFF
						},
						{// ID_1
								{TIMER_A_0, MODE_UPDOWN, ID_1, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_0, MODE_UPDOWN, ID_1, INT_OVF_OFF},// INT_OVF_OFF
						},
						{// ID_2
								{TIMER_A_0, MODE_UPDOWN, ID_2, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_0, MODE_UPDOWN, ID_2, INT_OVF_OFF},// INT_OVF_OFF
						},
						{// ID_3
								{TIMER_A_0, MODE_UPDOWN, ID_3, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_0, MODE_UPDOWN, ID_3, INT_OVF_OFF},// INT_OVF_OFF
						},
				},
		},
		{// TimerA1
				{// Mode up
						{// ID_0
								{TIMER_A_1, MODE_UP, ID_0, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_1, MODE_UP, ID_0, INT_OVF_OFF},// INT_OVF_OFF
						},
						{// ID_1
								{TIMER_A_1, MODE_UP, ID_1, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_1, MODE_UP, ID_1, INT_OVF_OFF},// INT_OVF_OFF
						},
						{// ID_2
								{TIMER_A_1, MODE_UP, ID_2, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_1, MODE_UP, ID_2, INT_OVF_OFF},// INT_OVF_OFF
						},
						{// ID_3
								{TIMER_A_1, MODE_UP, ID_3, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_1, MODE_UP, ID_3, INT_OVF_OFF},// INT_OVF_OFF
						},
				},
				{// Mode continuous
						{// ID_0
								{TIMER_A_1, MODE_CONTI, ID_0, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_1, MODE_CONTI, ID_0, INT_OVF_OFF},// INT_OVF_OFF
						},
						{// ID_1
								{TIMER_A_1, MODE_CONTI, ID_1, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_1, MODE_CONTI, ID_1, INT_OVF_OFF},// INT_OVF_OFF
						},
						{// ID_2
								{TIMER_A_1, MODE_CONTI, ID_2, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_1, MODE_CONTI, ID_2, INT_OVF_OFF},// INT_OVF_OFF
						},
						{// ID_3
								{TIMER_A_1, MODE_CONTI, ID_3, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_1, MODE_CONTI, ID_3, INT_OVF_OFF},// INT_OVF_OFF
						},
				},
				{// Mode up down
						{// ID_0
								{TIMER_A_1, MODE_UPDOWN, ID_0, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_1, MODE_UPDOWN, ID_0, INT_OVF_OFF},// INT_OVF_OFF
						},
						{// ID_1
								{TIMER_A_1, MODE_UPDOWN, ID_1, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_1, MODE_UPDOWN, ID_1, INT_OVF_OFF},// INT_OVF_OFF
						},
						{// ID_2
								{TIMER_A_1, MODE_UPDOWN, ID_2, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_1, MODE_UPDOWN, ID_2, INT_OVF_OFF},// INT_OVF_OFF
						},
						{// ID_3
								{TIMER_A_1, MODE_UPDOWN, ID_3, INT_OVF_ON},	// INT_OVF_ON
								{TIMER_A_1, MODE_UPDOWN, ID_3, INT_OVF_OFF},// INT_OVF_OFF
						},
				},
		}
	};
	//-Struct for timerA1CapSetup function-//
	const timer_A_Cap_Setup sTimerACapSetup =
	{
		{// TimerA0
				{// CCR0
						{// P1_1
								{// Rising
										{TIMER_A_0, CCR_0, CHANNEL_A, CAP_RISING, INT_CC_ON},	// INT_CC_ON
										{TIMER_A_0, CCR_0, CHANNEL_A, CAP_RISING, INT_CC_OFF},	// INT_CC_OFF
								},
								{// Falling
										{TIMER_A_0, CCR_0, CHANNEL_A, CAP_FALLING, INT_CC_ON},	// INT_CC_ON
										{TIMER_A_0, CCR_0, CHANNEL_A, CAP_FALLING, INT_CC_OFF},	// INT_CC_OFF
								},
								{// Both
										{TIMER_A_0, CCR_0, CHANNEL_A, CAP_BOTH, INT_CC_ON},		// INT_CC_ON
										{TIMER_A_0, CCR_0, CHANNEL_A, CAP_BOTH, INT_CC_OFF},	// INT_CC_OFF
								},
						},
				},
				{// CCR1
						{// P1_2
								{// Rising
										{TIMER_A_0, CCR_1, CHANNEL_A, CAP_RISING, INT_CC_ON},	// INT_CC_ON
										{TIMER_A_0, CCR_1, CHANNEL_A, CAP_RISING, INT_CC_OFF},	// INT_CC_OFF
								},
								{// Falling
										{TIMER_A_0, CCR_1, CHANNEL_A, CAP_FALLING, INT_CC_ON},	// INT_CC_ON
										{TIMER_A_0, CCR_1, CHANNEL_A, CAP_FALLING, INT_CC_OFF},	// INT_CC_OFF
								},
								{// Both
										{TIMER_A_0, CCR_1, CHANNEL_A, CAP_BOTH, INT_CC_ON},		// INT_CC_ON
										{TIMER_A_0, CCR_1, CHANNEL_A, CAP_BOTH, INT_CC_OFF},	// INT_CC_OFF
								},
						},
				},
		},
		{// TimerA1
				{// CCR0
						{// P2_0
								{// Rising
										{TIMER_A_1, CCR_0, CHANNEL_A, CAP_RISING, INT_CC_ON},	// INT_CC_ON
										{TIMER_A_1, CCR_0, CHANNEL_A, CAP_RISING, INT_CC_OFF},	// INT_CC_OFF
								},
								{// Falling
										{TIMER_A_1, CCR_0, CHANNEL_A, CAP_FALLING, INT_CC_ON},	// INT_CC_ON
										{TIMER_A_1, CCR_0, CHANNEL_A, CAP_FALLING, INT_CC_OFF},	// INT_CC_OFF
								},
								{// Both
										{TIMER_A_1, CCR_0, CHANNEL_A, CAP_BOTH, INT_CC_ON},		// INT_CC_ON
										{TIMER_A_1, CCR_0, CHANNEL_A, CAP_BOTH, INT_CC_OFF},	// INT_CC_OFF
								},
						},
						{// P2_3
								{// Rising
										{TIMER_A_1, CCR_0, CHANNEL_B, CAP_RISING, INT_CC_ON},	// INT_CC_ON
										{TIMER_A_1, CCR_0, CHANNEL_B, CAP_RISING, INT_CC_OFF},	// INT_CC_OFF
								},
								{// Falling
										{TIMER_A_1, CCR_0, CHANNEL_B, CAP_FALLING, INT_CC_ON},	// INT_CC_ON
										{TIMER_A_1, CCR_0, CHANNEL_B, CAP_FALLING, INT_CC_OFF},	// INT_CC_OFF
								},
								{// Both
										{TIMER_A_1, CCR_0, CHANNEL_B, CAP_BOTH, INT_CC_ON},		// INT_CC_ON
										{TIMER_A_1, CCR_0, CHANNEL_B, CAP_BOTH, INT_CC_OFF},	// INT_CC_OFF
								},
						},
				},
				{// CCR1
						{// P2_1
								{// Rising
										{TIMER_A_1, CCR_1, CHANNEL_A, CAP_RISING, INT_CC_ON},	// INT_CC_ON
										{TIMER_A_1, CCR_1, CHANNEL_A, CAP_RISING, INT_CC_OFF},	// INT_CC_OFF
								},
								{// Falling
										{TIMER_A_1, CCR_1, CHANNEL_A, CAP_FALLING, INT_CC_ON},	// INT_CC_ON
										{TIMER_A_1, CCR_1, CHANNEL_A, CAP_FALLING, INT_CC_OFF},	// INT_CC_OFF
								},
								{// Both
										{TIMER_A_1, CCR_1, CHANNEL_A, CAP_BOTH, INT_CC_ON},		// INT_CC_ON
										{TIMER_A_1, CCR_1, CHANNEL_A, CAP_BOTH, INT_CC_OFF},	// INT_CC_OFF
								},
						},
						{// P2_2
								{// Rising
										{TIMER_A_1, CCR_1, CHANNEL_B, CAP_RISING, INT_CC_ON},	// INT_CC_ON
										{TIMER_A_1, CCR_1, CHANNEL_B, CAP_RISING, INT_CC_OFF},	// INT_CC_OFF
								},
								{// Falling
										{TIMER_A_1, CCR_1, CHANNEL_B, CAP_FALLING, INT_CC_ON},	// INT_CC_ON
										{TIMER_A_1, CCR_1, CHANNEL_B, CAP_FALLING, INT_CC_OFF},	// INT_CC_OFF
								},
								{// Both
										{TIMER_A_1, CCR_1, CHANNEL_B, CAP_BOTH, INT_CC_ON},		// INT_CC_ON
										{TIMER_A_1, CCR_1, CHANNEL_B, CAP_BOTH, INT_CC_OFF},	// INT_CC_OFF
								},
						},
				},
				{// CCR2
						{// P2_4
								{// Rising
										{TIMER_A_1, CCR_2, CHANNEL_A, CAP_RISING, INT_CC_ON},	// INT_CC_ON
										{TIMER_A_1, CCR_2, CHANNEL_A, CAP_RISING, INT_CC_OFF},	// INT_CC_OFF
								},
								{// Falling
										{TIMER_A_1, CCR_2, CHANNEL_A, CAP_FALLING, INT_CC_ON},	// INT_CC_ON
										{TIMER_A_1, CCR_2, CHANNEL_A, CAP_FALLING, INT_CC_OFF},	// INT_CC_OFF
								},
								{// Both
										{TIMER_A_1, CCR_2, CHANNEL_A, CAP_BOTH, INT_CC_ON},		// INT_CC_ON
										{TIMER_A_1, CCR_2, CHANNEL_A, CAP_BOTH, INT_CC_OFF},	// INT_CC_OFF
								},
						},
						{// P2_5
								{// Rising
										{TIMER_A_1, CCR_2, CHANNEL_B, CAP_RISING, INT_CC_ON},	// INT_CC_ON
										{TIMER_A_1, CCR_2, CHANNEL_B, CAP_RISING, INT_CC_OFF},	// INT_CC_OFF
								},
								{// Falling
										{TIMER_A_1, CCR_2, CHANNEL_B, CAP_FALLING, INT_CC_ON},	// INT_CC_ON
										{TIMER_A_1, CCR_2, CHANNEL_B, CAP_FALLING, INT_CC_OFF},	// INT_CC_OFF
								},
								{// Both
										{TIMER_A_1, CCR_2, CHANNEL_B, CAP_BOTH, INT_CC_ON},		// INT_CC_ON
										{TIMER_A_1, CCR_2, CHANNEL_B, CAP_BOTH, INT_CC_OFF},	// INT_CC_OFF
								},
						},
				},
		},
	};
	//-Struct for timerACmpSetup function-//
	const timer_A_Cmp_Setup sTimerACmpSetup =
	{
		{// TimerA0
				{// CCR0
						{TIMER_A_0, CCR_0, INT_CC_ON},	// INT_ON
						{TIMER_A_0, CCR_0, INT_CC_OFF},	// INT_OFF
				},
				{// CCR1
						{TIMER_A_0, CCR_1, INT_CC_ON},	// INT_ON
						{TIMER_A_0, CCR_1, INT_CC_OFF},	// INT_OFF
				},
				{// CCR2
						{TIMER_A_0, CCR_2, INT_CC_ON},	// INT_ON
						{TIMER_A_0, CCR_2, INT_CC_OFF},	// INT_OFF
				},
		},
		{// TimerA1
				{// CCR0
						{TIMER_A_1, CCR_0, INT_CC_ON},	// INT_ON
						{TIMER_A_1, CCR_0, INT_CC_OFF},	// INT_OFF
				},
				{// CCR1
						{TIMER_A_1, CCR_1, INT_CC_ON},	// INT_ON
						{TIMER_A_1, CCR_1, INT_CC_OFF},	// INT_OFF
				},
				{// CCR2
						{TIMER_A_1, CCR_2, INT_CC_ON},	// INT_ON
						{TIMER_A_1, CCR_2, INT_CC_OFF},	// INT_OFF
				},
		}
	};
	//-Struct for pwmSetup function-//
	const pwm_Setup sPwmSetup =
	{
		{// TimerA0
				{// ModeUp
						{// P1.2
								{TIMER_A_0, MODE_UP, P1_2, PWM_TG_RST},	// Toggle/Reset
								{TIMER_A_0, MODE_UP, P1_2, PWM_SET_RST},// Set/Reset
								{TIMER_A_0, MODE_UP, P1_2, PWM_TG_SET},	// Toggle/Set
								{TIMER_A_0, MODE_UP, P1_2, PWM_RST_SET}	// Reset/Set
						},
						{// P1.6
								{TIMER_A_0, MODE_UP, P1_6, PWM_TG_RST},	// Toggle/Reset
								{TIMER_A_0, MODE_UP, P1_6, PWM_SET_RST},// Set/Reset
								{TIMER_A_0, MODE_UP, P1_6, PWM_TG_SET},	// Toggle/Set
								{TIMER_A_0, MODE_UP, P1_6, PWM_RST_SET}	// Reset/Set
						}
				}
		},
		{// TimerA1
				{// ModeUp
						{// P2.1
								{TIMER_A_1, MODE_UP, P2_1, PWM_TG_RST},	// Toggle/Reset
								{TIMER_A_1, MODE_UP, P2_1, PWM_SET_RST},// Set/Reset
								{TIMER_A_1, MODE_UP, P2_1, PWM_TG_SET},	// Toggle/Set
								{TIMER_A_1, MODE_UP, P2_1, PWM_RST_SET}	// Reset/Set
						},
						{// P2.2
								{TIMER_A_1, MODE_UP, P2_2, PWM_TG_RST},	// Toggle/Reset
								{TIMER_A_1, MODE_UP, P2_2, PWM_SET_RST},// Set/Reset
								{TIMER_A_1, MODE_UP, P2_2, PWM_TG_SET},	// Toggle/Set
								{TIMER_A_1, MODE_UP, P2_2, PWM_RST_SET}	// Reset/Set
						}
				}
		}
	};
#endif /* USE_TIMERA_1_1_3 */


/**************************************************************************************************
 *	FUNCTION'S PROTOTYPEs
 *************************************************************************************************/
 /* Setup */
void timerASetup (timer_Int sTimerASetup_,
				unsigned int varTarInit, unsigned int varCcr0Init);
void timerAStop (const char TIMER_A_);
void timerACapSetup (timer_A_Cap_Int sTimerACapSetup_);	// CCR0 is not used for ModeUp & ModeUpDown
void timerACmpSetup (timer_A_Cmp_Int sTimerACmpSetup_, unsigned int varCcrInit);
void pwmSetup (pwm_Out sPwmSetup, unsigned int varPeriod, unsigned int varDuty);


/**************************************************************************************************
 *	END OF TIMERA_1_2_3.h
 *************************************************************************************************/
#endif /* TIMERA_1_2_3_H_ */
