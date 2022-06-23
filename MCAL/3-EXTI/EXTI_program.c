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

/*INTERRUT_0_ Init*
 * Brief: by this function we can set INT_0 sense control and Peripheral INT disable or enable*
 * parameters:
 	 -Copy_u8SenseControlState0--> sense control as we want
 	 <<chose:INT0_LOW_LEVEL or INT0_LOGICAL_CHANGE or INT0_FALLING_EDGE or INT0_RISING_EDGE>>
*/
u8 EXTI_voidInt0Init(u8 Copy_u8SenseControlState0)
{
	u8 Local_u8ErrorState=0;
	switch(Copy_u8SenseControlState0)
	{
	/*Set sense control for INT0 to LOW Level*/
	case INT0_LOW_LEVEL:
		/*Set sense control for INT0 to LOW Level*/
		CLRBIT(MCUCR,MCUCR_ISC01);
		CLRBIT(MCUCR,MCUCR_ISC00);

		/*Peripheral Interrupt enable | disable for INT0*/
        #if GISR_STATE == GISR_ENEBLE
		SETBIT(GICR,GICR_INT0);
        #elif GISR_STATE == GISR_DISEBLE
		CLRBIT(GICR,GICR_INT0);
        #endif
		break;

		/*Set sense control for INT0 to any Logical change*/
	case INT0_LOGICAL_CHANGE:
		/*Set sense control for INT0 to any Logical change*/
		CLRBIT(MCUCR,MCUCR_ISC01);
		SETBIT(MCUCR,MCUCR_ISC00);
		/*Peripheral Interrupt enable | disable for INT0*/
        #if GISR_STATE == GISR_ENEBLE
		SETBIT(GICR,GICR_INT0);
        #elif GISR_STATE == GISR_DISEBLE
		CLRBIT(GICR,GICR_INT0);
        #endif
		break;

		/*Set sense control for INT0 to falling edge*/
	case INT0_FALLING_EDGE:
		/*Set sense control for INT0 to falling edge*/
		SETBIT(MCUCR,MCUCR_ISC01);
		CLRBIT(MCUCR,MCUCR_ISC00);
		/*Peripheral Interrupt enable | disable for INT0*/
		#if GISR_STATE == GISR_ENEBLE
		SETBIT(GICR,GICR_INT0);
		#elif GISR_STATE == GISR_DISEBLE
		CLRBIT(GICR,GICR_INT0);
		#endif
		break;
		/*Set sense control for INT0 to rising edge*/
	case INT0_RISING_EDGE:
		/*Set sense control for INT0 to rising edge*/
		SETBIT(MCUCR,MCUCR_ISC01);
		SETBIT(MCUCR,MCUCR_ISC00);
		/*Peripheral Interrupt enable | disable for INT0*/
		#if GISR_STATE == GISR_ENEBLE
		SETBIT(GICR,GICR_INT0);
		#elif GISR_STATE == GISR_DISEBLE
		CLRBIT(GICR,GICR_INT0);
		#endif
		break;
	default: Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}


/*INTERRUT_1_ Init*
 * Brief: by this function we can set INT_1 sense control and Peripheral INT disable or enable*
 * parameters:
 	 -Copy_u8SenseControlState1--> sense control as we want
 	 <<chose:INT1_LOW_LEVEL or INT1_LOGICAL_CHANGE or INT1_FALLING_EDGE or INT1_RISING_EDGE>>
*/
u8 EXTI_voidInt1Init(u8 Copy_u8SenseControlState1)
{
	u8 Local_u8ErrorState=0;
	switch(Copy_u8SenseControlState1)
	{
	/*Set sense control for INT1 to LOW Level*/
	case INT1_LOW_LEVEL:
		/*Set sense control for INT1 to LOW Level*/
		CLRBIT(MCUCR,MCUCR_ISC11);
		CLRBIT(MCUCR,MCUCR_ISC10);
		/*Peripheral Interrupt enable | disable for INT1*/
		#if GISR_STATE == GISR_ENEBLE
		SETBIT(GICR,GICR_INT1);
		#elif GISR_STATE == GISR_DISEBLE
		CLRBIT(GICR,GICR_INT1);
		#endif
		break;

		/*Set sense control for INT1 to any Logical change*/
	case INT1_LOGICAL_CHANGE:
		/*Set sense control for INT1 to any Logical change*/
		CLRBIT(MCUCR,MCUCR_ISC11);
		SETBIT(MCUCR,MCUCR_ISC10);
		/*Peripheral Interrupt enable | disable for INT1*/
        #if GISR_STATE == GISR_ENEBLE
		SETBIT(GICR,GICR_INT1);
		#elif GISR_STATE == GISR_DISEBLE
		CLRBIT(GICR,GICR_INT1);
		#endif
		break;

		/*Set sense control for INT1 to falling edge*/
	case INT1_FALLING_EDGE:
		/*Set sense control for INT1 to falling edge*/
		SETBIT(MCUCR,MCUCR_ISC11);
		CLRBIT(MCUCR,MCUCR_ISC10);
		/*Peripheral Interrupt enable | disable for INT1*/
		#if GISR_STATE == GISR_ENEBLE
		SETBIT(GICR,GICR_INT1);
		#elif GISR_STATE == GISR_DISEBLE
		CLRBIT(GICR,GICR_INT1);
		#endif
		break;

		/*Set sense control for INT1 to rising edge*/
	case INT1_RISING_EDGE:
		/*Set sense control for INT1 to rising edge*/
		SETBIT(MCUCR,MCUCR_ISC11);
		SETBIT(MCUCR,MCUCR_ISC10);
		/*Peripheral Interrupt enable | disable for INT1*/
		#if GISR_STATE == GISR_ENEBLE
		SETBIT(GICR,GICR_INT1);
		#elif GISR_STATE == GISR_DISEBLE
		CLRBIT(GICR,GICR_INT1);
		#endif
		break;
	default: Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}


/*INTERRUT_2_ Init*
 * Brief: by this function we can set INT_2 sense control and Peripheral INT disable or enable*
 * parameters:
 	 -Copy_u8SenseControlState2--> sense control as we want
 	 <<chose:INT2_FALLING_EDGE or INT2_INT0_RISING_EDGE>>
*/
u8 EXTI_voidInt2Init(u8 Copy_u8SenseControlState2)
{
	u8 Local_u8ErrorState=0;
	switch(Copy_u8SenseControlState2)
	{
	/*Set sense control for INT2 to falling edge*/
	case INT2_FALLING_EDGE:
		/*Set sense control for INT2 to falling edge*/
		CLRBIT(MCUCSR,MCUCSR_ISC2);
		/*Peripheral Interrupt enable | disable for INT2*/
		#if GISR_STATE == GISR_ENEBLE
		SETBIT(GICR,GICR_INT2);
		#elif GISR_STATE == GISR_DISEBLE
		CLRBIT(GICR,GICR_INT2);
		#endif
		break;

	/*Set sense control for INT2 to falling edge*/
	case INT2_RISING_EDGE:
		/*Set sense control for INT2 to falling edge*/
		SETBIT(MCUCSR,MCUCSR_ISC2);
		/*Peripheral Interrupt enable | disable for INT2*/
		#if GISR_STATE == GISR_ENEBLE
		SETBIT(GICR,GICR_INT2);
		#elif GISR_STATE == GISR_DISEBLE
		CLRBIT(GICR,GICR_INT2);
		#endif
		break;
	default: Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}




