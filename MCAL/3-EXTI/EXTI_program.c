/*************************************************************************/
/*************************************************************************/
/**********************   Author:  Al-Hasan Ameer   **********************/
/**********************   LAYER:   MCAL             **********************/
/**********************   SWC:     EXTI             **********************/
/**********************   VERSION: 1.00             **********************/
/*************************************************************************/
/*************************************************************************/


/*************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_register.h"
/*************************************************************************/

/*Global Pointer to Function parameters*/
void (*EXTI_pvInt0Func)(void)= NULL;
void (*EXTI_pvInt1Func)(void)= NULL;
void (*EXTI_pvInt2Func)(void)= NULL;

/*INTERRUT_0_ Init*
 * Brief: by this function we can set INT_0 sense control and Peripheral INT disable or enable*
*/
void EXTI_voidInt0Init(void)
{
	/*Set sense control for INT0 to LOW Level*/
#if INT0_SENCE_CONTROL_STATE == INT0_LOW_LEVEL
	/*Set sense control for INT0 to LOW Level*/
	CLRBIT(MCUCR,MCUCR_ISC01);
	CLRBIT(MCUCR,MCUCR_ISC00);
	/*Set sense control for INT0 to any Logical change*/
#elif INT0_SENCE_CONTROL_STATE ==INT0_LOGICAL_CHANGE
	/*Set sense control for INT0 to any Logical change*/
	CLRBIT(MCUCR,MCUCR_ISC01);
	SETBIT(MCUCR,MCUCR_ISC00);
	/*Set sense control for INT0 to falling edge*/
#elif INT0_SENCE_CONTROL_STATE == INT0_FALLING_EDGE
	/*Set sense control for INT0 to falling edge*/
	SETBIT(MCUCR,MCUCR_ISC01);
	CLRBIT(MCUCR,MCUCR_ISC00);

	/*Set sense control for INT0 to rising edge*/
#elif INT0_SENCE_CONTROL_STATE ==INT0_RISING_EDGE
	/*Set sense control for INT0 to rising edge*/
	SETBIT(MCUCR,MCUCR_ISC01);
	SETBIT(MCUCR,MCUCR_ISC00);
#else
#error "wrong INT0 configuration option"
#endif

	/*Peripheral Interrupt enable | disable for INT0*/
#if GISR_STATE == GISR_ENEBLE
	SETBIT(GICR,GICR_INT0);
#elif GISR_STATE == GISR_DISEBLE
	CLRBIT(GICR,GICR_INT0);
#else
#error "wrong GISR INT0 configuration option"
#endif

}


/*INTERRUT_1_ Init*
 * Brief: by this function we can set INT_1 sense control and Peripheral INT disable or enable*
*/
void EXTI_voidInt1Init(void)
{

	/*Set sense control for INT1 to LOW Level*/
#if INT1_SENCE_CONTROL_STATE == INT1_LOW_LEVEL
	/*Set sense control for INT1 to LOW Level*/
	CLRBIT(MCUCR,MCUCR_ISC11);
	CLRBIT(MCUCR,MCUCR_ISC10);
	/*Set sense control for INT1 to any Logical change*/
#elif INT1_SENCE_CONTROL_STATE == INT1_LOGICAL_CHANGE
	/*Set sense control for INT1 to any Logical change*/
	CLRBIT(MCUCR,MCUCR_ISC11);
	SETBIT(MCUCR,MCUCR_ISC10);
	/*Set sense control for INT1 to falling edge*/
#elif INT1_SENCE_CONTROL_STATE == INT1_FALLING_EDGE
	/*Set sense control for INT1 to falling edge*/
	SETBIT(MCUCR,MCUCR_ISC11);
	CLRBIT(MCUCR,MCUCR_ISC10);
	/*Set sense control for INT1 to rising edge*/
#elif INT1_SENCE_CONTROL_STATE ==  INT1_RISING_EDGE
	/*Set sense control for INT1 to rising edge*/
	SETBIT(MCUCR,MCUCR_ISC11);
	SETBIT(MCUCR,MCUCR_ISC10);
#else
#error "wrong INT1 configuration option"
#endif

	/*Peripheral Interrupt enable | disable for INT1*/
#if GISR_STATE == GISR_ENEBLE
	SETBIT(GICR,GICR_INT1);
#elif GISR_STATE == GISR_DISEBLE
	CLRBIT(GICR,GICR_INT1);
#else
#error "wrong GISR INT1 configuration option"
#endif

}


/*INTERRUT_2_ Init*
 * Brief: by this function we can set INT_2 sense control and Peripheral INT disable or enable*
*/
void EXTI_voidInt2Init(void)
{

	/*Set sense control for INT2 to falling edge*/
#if INT2_SENCE_CONTROL_STATE == INT2_FALLING_EDGE
	/*Set sense control for INT2 to falling edge*/
	CLRBIT(MCUCSR,MCUCSR_ISC2);
	/*Set sense control for INT2 to falling edge*/
#elif INT2_SENCE_CONTROL_STATE == INT2_RISING_EDGE
	/*Set sense control for INT2 to falling edge*/
	SETBIT(MCUCSR,MCUCSR_ISC2);
#else
#error "wrong INT2 configuration option"
#endif

	/*Peripheral Interrupt enable | disable for INT2*/
#if GISR_STATE == GISR_ENEBLE
	SETBIT(GICR,GICR_INT2);
#elif GISR_STATE == GISR_DISEBLE
	CLRBIT(GICR,GICR_INT2);
#else
#error "wrong GISR INT1 configuration option"
#endif


}

/*IntSetSenseControL*
 * Brief: by this function we can set INT_0 sense control using postBuild Configuration*
 * input:
 	 	<<INT_LOW_LEVEL,INT_LOGICAL_CHANGE,INT_FALLING_EDGE,INT_RISING_EDGE>>
 	 	<<EXTI_INT0,EXTI_INT1,EXTI_INT2>>
 * output:
 	 	Local_u8ErrorState
*/
u8 EXTI_u8IntSetSenseControl(u8 Copy_u8SenseControlState, u8 Copy_u8INTNum)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8INTNum == EXTI_INT0){
		switch(Copy_u8SenseControlState)
		{
		/*Set sense control for INT0 to LOW Level*/
		case INT_LOW_LEVEL: CLRBIT(MCUCR,MCUCR_ISC01); CLRBIT(MCUCR,MCUCR_ISC00);      break;
		/*Set sense control for INT0 to any Logical change*/
		case INT_LOGICAL_CHANGE: CLRBIT(MCUCR,MCUCR_ISC01); SETBIT(MCUCR,MCUCR_ISC00); break;
		/*Set sense control for INT0 to falling edge*/
		case INT_FALLING_EDGE: SETBIT(MCUCR,MCUCR_ISC01); CLRBIT(MCUCR,MCUCR_ISC00);   break;
		/*Set sense control for INT0 to rising edge*/
		case INT_RISING_EDGE: SETBIT(MCUCR,MCUCR_ISC01); SETBIT(MCUCR,MCUCR_ISC00);    break;
		default: Local_u8ErrorState=NOK;
		}
	}
	else if(Copy_u8INTNum == EXTI_INT1){
		switch(Copy_u8SenseControlState)
		{
		/*Set sense control for INT1 to LOW Level*/
		case INT_LOW_LEVEL:CLRBIT(MCUCR,MCUCR_ISC11); CLRBIT(MCUCR,MCUCR_ISC10);       break;
		/*Set sense control for INT1 to any Logical change*/
		case INT_LOGICAL_CHANGE:CLRBIT(MCUCR,MCUCR_ISC11); SETBIT(MCUCR,MCUCR_ISC10);  break;
		/*Set sense control for INT1 to falling edge*/
		case INT_FALLING_EDGE:SETBIT(MCUCR,MCUCR_ISC11); CLRBIT(MCUCR,MCUCR_ISC10);    break;
		/*Set sense control for INT1 to rising edge*/
		case INT_RISING_EDGE: SETBIT(MCUCR,MCUCR_ISC11); SETBIT(MCUCR,MCUCR_ISC10);    break;
		default: Local_u8ErrorState=NOK;
		}

	}
	else if(Copy_u8INTNum == EXTI_INT2){
		switch(Copy_u8SenseControlState)
		{
		/*Set sense control for INT2 to falling edge*/
		case INT_FALLING_EDGE: CLRBIT(MCUCSR,MCUCSR_ISC2); break;
		/*Set sense control for INT2 to falling edge*/
		case INT_RISING_EDGE: SETBIT(MCUCSR,MCUCSR_ISC2);  break;
		default: Local_u8ErrorState=NOK;
		}

	}
	else{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}

/*IntPeripheralState*
 * Brief: by this function we can set Peripheral INT disable or enable using postBuild Configuration*
 * input:
 	 	<<GISR_ENEBLE,GISR_DISEBLE>>
 	 	<<EXTI_INT0,EXTI_INT1,EXTI_INT2>>
 * output:
 	 	Local_u8ErrorState
*/
u8 EXTI_u8IntGISRState(u8 Copy_u8GISRState, u8 Copy_u8INTNum)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8GISRState == GISR_ENEBLE){
		switch(Copy_u8INTNum){
		case EXTI_INT0: SETBIT(GICR,GICR_INT0); break;
		case EXTI_INT1: SETBIT(GICR,GICR_INT1); break;
		case EXTI_INT2: SETBIT(GICR,GICR_INT2); break;
		default: Local_u8ErrorState=NOK;
		}

	}
	else if(Copy_u8GISRState == GISR_DISEBLE){
		switch(Copy_u8INTNum){
		case EXTI_INT0: CLRBIT(GICR,GICR_INT0); break;
		case EXTI_INT1: CLRBIT(GICR,GICR_INT1); break;
		case EXTI_INT2: CLRBIT(GICR,GICR_INT2); break;
		default: Local_u8ErrorState=NOK;
		}
	}
	return Local_u8ErrorState;
}

/*INT_0 Call Back
 * Brief:  by this function we can Handled INT0_ISR function that user write it
 * input:  *Copy_vpInt0Func
 * output: Local_u8ErrorState
 */
u8 EXTI_voidInt0SetCallBack(void (*Copy_vpInt0Func)(void))
{
	u8 Local_u8ErrorState=OK;
	if(Copy_vpInt0Func != NULL)
	{
		EXTI_pvInt0Func = Copy_vpInt0Func;
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}
/*INT_0 ISR*/
void __vector_1 (void)  __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvInt0Func !=NULL){
	EXTI_pvInt0Func();
	}
	else
	{
		/*NOTING*/
	}
}

/*INT_1 Call Back
 * Brief:  by this function we can Handled INT0_ISR function that user write it
 * input:  *Copy_vpInt1Func
 * output: Local_u8ErrorState
 */
u8 EXTI_voidInt1SetCallBack(void (*Copy_vpInt1Func)(void))
{
	u8 Local_u8ErrorState=OK;
	if(Copy_vpInt1Func != NULL)
	{
		EXTI_pvInt1Func = Copy_vpInt1Func;
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}
/*INT_1 ISR*/
void __vector_2 (void)  __attribute__((signal));
void __vector_2 (void)
{
	if(EXTI_pvInt1Func !=NULL){
	EXTI_pvInt1Func();
	}
	else
	{
		/*NOTING*/
	}
}

/*INT_2 Call Back
 * Brief:  by this function we can Handled INT0_ISR function that user write it
 * input:  *Copy_vpInt2Func
 * output: Local_u8ErrorState
 */
u8 EXTI_voidInt2SetCallBack(void (*Copy_vpInt2Func)(void))
{
	u8 Local_u8ErrorState=OK;
	if(Copy_vpInt2Func != NULL)
	{
		EXTI_pvInt2Func = Copy_vpInt2Func;
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}
/*INT_2 ISR*/
void __vector_3 (void)  __attribute__((signal));
void __vector_3 (void)
{
	if(EXTI_pvInt2Func !=NULL){
	EXTI_pvInt2Func();
	}
	else
	{
		/*NOTING*/
	}
}

