/*************************************************************************/
/*************************************************************************/
/**********************   Author:  Al-Hasan Ameer   **********************/
/**********************   LAYER:   MCAL             **********************/
/**********************   SWC:     EXTI             **********************/
/**********************   VERSION: 1.00             **********************/
/*************************************************************************/
/*************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


/*INTERRUT_0_ Init*
 * Brief: by this function we can set INT_0 sense control and Peripheral INT disable or enable*
 * parameters:
 	 -Copy_u8SenseControlState0--> sense control as we want
 	 <<chose:INT0_LOW_LEVEL or INT0_LOGICAL_CHANGE or INT0_FALLING_EDGE or INT0_RISING_EDGE>>
*/
u8 EXTI_voidInt0Init(u8 Copy_u8SenseControlState0);
/**********INT0 Switching cases**********/
#define INT0_LOW_LEVEL            0
#define INT0_LOGICAL_CHANGE       1
#define INT0_FALLING_EDGE         2
#define INT0_RISING_EDGE          3
/****************************************/

/*INTERRUT_1_ Init*
 * Brief: by this function we can set INT_1 sense control and Peripheral INT disable or enable*
 * parameters:
 	 -Copy_u8SenseControlState1--> sense control as we want
 	 <<chose:INT1_LOW_LEVEL or INT1_LOGICAL_CHANGE or INT1_FALLING_EDGE or INT1_RISING_EDGE>>
*/
u8 EXTI_voidInt1Init(u8 Copy_u8SenseControlState1);
/**********INT1 Switching cases**********/
#define INT1_LOW_LEVEL            0
#define INT1_LOGICAL_CHANGE       1
#define INT1_FALLING_EDGE         2
#define INT1_RISING_EDGE          3
/****************************************/

/*INTERRUT_2_ Init*
 * Brief: by this function we can set INT_2 sense control and Peripheral INT disable or enable*
 * parameters:
 	 -Copy_u8SenseControlState2--> sense control as we want
 	 <<chose:INT2_FALLING_EDGE or INT2_INT0_RISING_EDGE>>
*/
u8 EXTI_voidInt2Init(u8 Copy_u8SenseControlState2);
/**********INT2 Switching cases**********/
#define INT2_FALLING_EDGE         0
#define INT2_RISING_EDGE          1
/****************************************/





#endif /* EXTI_INTERFACE_H_ */





