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

#define INT_LOW_LEVEL            1
#define INT_LOGICAL_CHANGE       2
#define INT_FALLING_EDGE         3
#define INT_RISING_EDGE          4




/*INTERRUT_0_ Init*
 * Brief: by this function we can set INT_0 sense control and Peripheral INT disable or enable*
 * input:  void
 * output: void
*/
void EXTI_voidInt0Init(void);
#define EXTI_INT0                 5


/*INTERRUT_1_ Init*
 * Brief: by this function we can set INT_1 sense control and Peripheral INT disable or enable*
 * input:  void
 * output: void
 */
void EXTI_voidInt1Init(void);
#define EXTI_INT1                 6


/*INTERRUT_2_ Init*
 * Brief: by this function we can set INT_2 sense control and Peripheral INT disable or enable*
 * input:  void
 * output: void
*/
void EXTI_voidInt2Init(void);
#define EXTI_INT2                 7

/*IntSetSenseControL*
 * Brief: by this function we can set INT_0 sense control using postBuild Configuration*
 * input:
 	 	<<INT_LOW_LEVEL,INT_LOGICAL_CHANGE,INT_FALLING_EDGE,INT_RISING_EDGE>>
 	 	<<EXTI_INT0,EXTI_INT1,EXTI_INT2>>
 * output:
 	 	Local_u8ErrorState
*/
u8 EXTI_u8IntSetSenseControl(u8 Copy_u8SenseControlState,  u8 Copy_u8INTNum);

/*IntPeripheralState*
 * Brief: by this function we can set Peripheral INT disable or enable using postBuild Configuration*
 * input:
 	 	<<GISR_ENEBLE,GISR_DISEBLE>>
 	 	<<EXTI_INT0,EXTI_INT1,EXTI_INT2>>
 * output:
 	 	Local_u8ErrorState
*/
u8 EXTI_u8IntGISRState(u8 Copy_u8GISRState, u8 Copy_u8INTNum);
#define GISR_ENEBLE               9
#define GISR_DISEBLE              10

/*INT_0 Call Back
 * Brief:  by this function we can Handled INT0_ISR function that user write it
 * input:  *Copy_vpInt0Func
 * output: Local_u8ErrorState
 */
u8 EXTI_voidInt0SetCallBack(void (*Copy_vpInt0Func)(void));

/*INT_1 Call Back
 * Brief:  by this function we can Handled INT0_ISR function that user write it
 * input:  *Copy_vpInt1Func
 * output: Local_u8ErrorState
 */
u8 EXTI_voidInt1SetCallBack(void (*Copy_vpInt1Func)(void));

/*INT_2 Call Back
 * Brief:  by this function we can Handled INT0_ISR function that user write it
 * input:  *Copy_vpInt2Func
 * output: Local_u8ErrorState
 */
u8 EXTI_voidInt2SetCallBack(void (*Copy_vpInt2Func)(void));

#endif /* EXTI_INTERFACE_H_ */





