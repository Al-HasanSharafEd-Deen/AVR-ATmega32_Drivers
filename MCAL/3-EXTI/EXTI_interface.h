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



u8 EXTI_voidInt0Init(u8 Copy_u8SenseControlState0);
#define INT0_LOW_LEVEL            0
#define INT0_LOGICAL_CHANGE       1
#define INT0_FALLING_EDGE         2
#define INT0_RISING_EDGE          3


u8 EXTI_voidInt1Init(u8 Copy_u8SenseControlState1);
#define INT1_LOW_LEVEL            0
#define INT1_LOGICAL_CHANGE       1
#define INT1_FALLING_EDGE         2
#define INT1_RISING_EDGE          3


u8 EXTI_voidInt2Init(u8 Copy_u8SenseControlState2);
#define INT2_FALLING_EDGE         0
#define INT2_RISING_EDGE          1

#endif /* EXTI_INTERFACE_H_ */





