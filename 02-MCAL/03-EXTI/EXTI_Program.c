#include	"STDTYPES.h"
#include	"BITMATH.h"
#include	"EXTI_Interface.h"
#include	"EXTI_Private.h"
#include	"EXTI_Register.h"
#include	"EXTI_Config.h"

void (*EXTI_pvINT0Func)(void)=NULL;   /*GLOBAL POINTER TO FUNCTION TO STORE SENT FUNCTION(OF ISR) ADDRESS*/
void (*EXTI_pvINT1Func)(void)=NULL;   /*GLOBAL POINTER TO FUNCTION TO STORE SENT FUNCTION(OF ISR) ADDRESS*/
void (*EXTI_pvINT2Func)(void)=NULL;   /*GLOBAL POINTER TO FUNCTION TO STORE SENT FUNCTION(OF ISR) ADDRESS*/
/***********POST-BUILD****************/
/***********INT0*************/
void EXTI_VoidInt0Init(void)
{
#if INT0_SENSE_CONTROL	==	LOW_LEVEL
	/*set sense control for int0 to LOW_LEVEL (0,0)*/
	CLRBit(EXTI_MCUCR,MCUCR_ISC00);
	CLRBit(EXTI_MCUCR,MCUCR_ISC01);

#elif INT0_SENSE_CONTROL	==	ON_CHANGE
	/*set sense control for int0 to ON_CHANGE (0,1)*/
	SetBit(EXTI_MCUCR,MCUCR_ISC00);
	CLRBit(EXTI_MCUCR,MCUCR_ISC01);

#elif INT0_SENSE_CONTROL	==	FALLING_EDGE
	/*set sense control for int0 to FALLING_EDGE (1,0)*/
	CLRBit(EXTI_MCUCR,MCUCR_ISC00);
	SetBit(EXTI_MCUCR,MCUCR_ISC01);
#elif INT0_SENSE_CONTROL	==	RISING_EDGE
	/*set sense control for int0 to RISING_EDGE (1,1)*/
	SetBit(EXTI_MCUCR,MCUCR_ISC00);
	SetBit(EXTI_MCUCR,MCUCR_ISC01);
#else
#error "Wrong INT0 control sense Configuration option"
#endif
	/* CHECK PERIPHERAL INTERRUPT ENABLE INTIAL STATE */
#if	INT0_INITIAL_STATE	== ENABLED
	/*Periphral interrupt enable for int0*/
	SetBit(EXTI_GICR,GICR_INT0);
#elif	INT0_INITIAL_STATE	== DISABLED
	/*Periphral interrupt Disable for int0*/
	CLRBit(EXTI_GICR,GICR_INT0);
#else
#error "Wrong INT0 initial state Configuration option"
#endif
}
/***********INT1*************/
void EXTI_VoidInt1Init(void)
{
#if INT1_SENSE_CONTROL	==	LOW_LEVEL
	/*set sense control for int1 to LOW_LEVEL (0,0)*/
	CLRBit(EXTI_MCUCR,MCUCR_ISC10);
	CLRBit(EXTI_MCUCR,MCUCR_ISC11);

#elif INT1_SENSE_CONTROL	==	ON_CHANGE
	/*set sense control for int1 to ON_CHANGE (0,1)*/
	SetBit(EXTI_MCUCR,MCUCR_ISC10);
	CLRBit(EXTI_MCUCR,MCUCR_ISC11);

#elif INT1_SENSE_CONTROL	==	FALLING_EDGE
	/*set sense control for int1 to FALLING_EDGE (1,0)*/
	CLRBit(EXTI_MCUCR,MCUCR_ISC10);
	SetBit(EXTI_MCUCR,MCUCR_ISC11);
#elif INT1_SENSE_CONTROL	==	RISING_EDGE
	/*set sense control for int1 to RISING_EDGE (1,1)*/
	SetBit(EXTI_MCUCR,MCUCR_ISC10);
	SetBit(EXTI_MCUCR,MCUCR_ISC11);
#else
#error "Wrong INT1 control sense Configuration option"
#endif
	/* CHECK PERIPHERAL INTERRUPT ENABLE INTIAL STATE */
#if	INT1_INITIAL_STATE	== ENABLED
	/*Periphral interrupt enable for int1*/
	SetBit(EXTI_GICR,GICR_INT1);
#elif	INT1_INITIAL_STATE	== DISABLED
	/*Periphral interrupt Disable for int1*/
	CLRBit(EXTI_GICR,GICR_INT1);
#else
#error "Wrong INT1 initial state Configuration option"
#endif
}
/***********INT2*************/
void EXTI_VoidInt2Init(void)
{
#if INT2_SENSE_CONTROL	==	FALLING_EDGE
	/*set sense control for int2 to FALLING_EDGE (0)*/
	CLRBit(EXTI_MCUCSR,MCUCSR_ISC2);
#elif INT2_SENSE_CONTROL	==	RISING_EDGE
	/*set sense control for int2 to RISING_EDGE (1)*/
	SetBit(EXTI_MCUCSR,MCUCSR_ISC2);
#else
#error "Wrong INT2 control sense Configuration option"
#endif
	/* CHECK PERIPHERAL INTERRUPT ENABLE INTIAL STATE */
#if	INT2_INITIAL_STATE	== ENABLED
	/*Periphral interrupt enable for int2*/
	SetBit(EXTI_GICR,GICR_INT2);
#elif	INT2_INITIAL_STATE	== DISABLED
	/*Periphral interrupt Disable for int2*/
	CLRBit(EXTI_GICR,GICR_INT2);
#else
#error "Wrong INT2 initial state Configuration option"
#endif
}
/***********PRE-BUILD****************/
/***********INT0*************/
u8 EXTI_u8Int0SenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState=OK;
	switch(Copy_u8Sense)
	{
	case LOW_LEVEL:
		/*set sense control for int0 to LOW_LEVEL (0,0)*/
		CLRBit(EXTI_MCUCR,MCUCR_ISC00);
		CLRBit(EXTI_MCUCR,MCUCR_ISC01);
		break;
	case ON_CHANGE:
		/*set sense control for int0 to ON_CHANGE (0,1)*/
		SetBit(EXTI_MCUCR,MCUCR_ISC00);
		CLRBit(EXTI_MCUCR,MCUCR_ISC01);
		break;
	case FALLING_EDGE:
		/*set sense control for int0 to FALLING_EDGE (1,0)*/
		CLRBit(EXTI_MCUCR,MCUCR_ISC00);
		SetBit(EXTI_MCUCR,MCUCR_ISC01);
		break;
	case RISING_EDGE:
		/*set sense control for int0 to RISING_EDGE (1,1)*/
		SetBit(EXTI_MCUCR,MCUCR_ISC00);
		SetBit(EXTI_MCUCR,MCUCR_ISC01);
		break;
	default:	 Local_u8ErrorState=NOK;	break;
	}

	return Local_u8ErrorState;
}
/***********INT1*************/
u8 EXTI_u8Int1SenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState=OK;
	switch(Copy_u8Sense)
	{
	case LOW_LEVEL:
		/*set sense control for int1 to LOW_LEVEL (0,0)*/
		CLRBit(EXTI_MCUCR,MCUCR_ISC10);
		CLRBit(EXTI_MCUCR,MCUCR_ISC11);
		break;
	case ON_CHANGE:
		/*set sense control for int1 to ON_CHANGE (0,1)*/
		SetBit(EXTI_MCUCR,MCUCR_ISC10);
		CLRBit(EXTI_MCUCR,MCUCR_ISC11);
		break;
	case FALLING_EDGE:
		/*set sense control for int1 to FALLING_EDGE (1,0)*/
		CLRBit(EXTI_MCUCR,MCUCR_ISC10);
		SetBit(EXTI_MCUCR,MCUCR_ISC11);
		break;
	case RISING_EDGE:
		/*set sense control for int1 to RISING_EDGE (1,1)*/
		SetBit(EXTI_MCUCR,MCUCR_ISC10);
		SetBit(EXTI_MCUCR,MCUCR_ISC11);
		break;
	default:	 Local_u8ErrorState=NOK;	break;
	}

	return Local_u8ErrorState;
}
/***********INT2*************/
u8 EXTI_u8Int2SenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState=OK;
	switch(Copy_u8Sense)
	{
	case FALLING_EDGE:
		/*set sense control for int2 to FALLING_EDGE (1,0)*/
		CLRBit(EXTI_MCUCSR,MCUCSR_ISC2);
		break;
	case RISING_EDGE:
		/*set sense control for int2 to RISING_EDGE (1)*/
		SetBit(EXTI_MCUCSR,MCUCSR_ISC2);
		break;
	default:	 Local_u8ErrorState=NOK;	break;
	}

	return Local_u8ErrorState;
}
/*	Enable	and	Disable	*/
u8 EXTI_u8IntEnable(u8 Copy_u8Int)
{
	u8 Local_u8ErrorState=OK;
	switch(Copy_u8Int)
	{
	case EXIT_INT_0: SetBit(EXTI_GICR,GICR_INT0); break;
	case EXIT_INT_1: SetBit(EXTI_GICR,GICR_INT1); break;
	case EXIT_INT_2: SetBit(EXTI_GICR,GICR_INT2); break;
	default:	 Local_u8ErrorState=NOK;	break;
	}
	return Local_u8ErrorState;
}
u8 EXTI_u8IntDisable(u8 Copy_u8Int)
{
	u8 Local_u8ErrorState=OK;
	switch(Copy_u8Int)
	{
	case EXIT_INT_0: CLRBit(EXTI_GICR,GICR_INT0); break;
	case EXIT_INT_1: CLRBit(EXTI_GICR,GICR_INT1); break;
	case EXIT_INT_2: CLRBit(EXTI_GICR,GICR_INT2); break;
	default:	 Local_u8ErrorState=NOK;	break;
	}
	return Local_u8ErrorState;
}
/**************CALL BACK FUNCTION***************/
/*A FUNCTION THAT RECEIVE THE SENT FUNCTION(OF ISR) ADDRESS */
u8 EXTI_u8INT0CallBackFunc(void (*Copy_INT0)(void))
{
	u8 Local_u8ErrorState=OK;
	if(Copy_INT0!=NULL)
	{
		EXTI_pvINT0Func=Copy_INT0;
	}else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}
u8 EXTI_u8INT1CallBackFunc(void (*Copy_INT1)(void))
{
	u8 Local_u8ErrorState=OK;
	if(Copy_INT1!=NULL)
	{
		EXTI_pvINT1Func=Copy_INT1;
	}else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}
u8 EXTI_u8INT2CallBackFunc(void (*Copy_INT2)(void))
{
	u8 Local_u8ErrorState=OK;
	if(Copy_INT2!=NULL)
	{
		EXTI_pvINT2Func=Copy_INT2;
	}else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}
/*ISR-(COMPILER and TOOLCHAIN dependent)*/
void __vector_1(void) __attribute__((signal));
void __vector_1(void){
	/*using the global pointer to function as a function using ISR function address*/
	EXTI_pvINT0Func();
}
void __vector_2(void) __attribute__((signal));
void __vector_2(void){
	/*using the global pointer to function as a function using ISR function address*/
	EXTI_pvINT1Func();
}
void __vector_3(void) __attribute__((signal));
void __vector_3(void){
	/*using the global pointer to function as a function using ISR function address*/
	EXTI_pvINT2Func();
}
