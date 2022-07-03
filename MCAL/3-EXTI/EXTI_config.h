/*************************************************************************/
/*************************************************************************/
/**********************   Author:  Al-Hasan Ameer   **********************/
/**********************   LAYER:   MCAL             **********************/
/**********************   SWC:     EXTI             **********************/
/**********************   VERSION: 1.00             **********************/
/*************************************************************************/
/*************************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*chose:
 * INT0_LOW_LEVEL
 * INT0_LOGICAL_CHANGE
 * INT0_FALLING_EDGE
 * INT0_RISING_EDGE    */
#define INT0_SENCE_CONTROL_STATE           INT0_FALLING_EDGE

/*chose:
 * INT1_LOW_LEVEL
 * INT1_LOGICAL_CHANGE
 * INT1_FALLING_EDGE
 * INT1_RISING_EDGE    */
#define INT1_SENCE_CONTROL_STATE           INT1_FALLING_EDGE

/*chose:
 * INT1_FALLING_EDGE
 * INT1_RISING_EDGE    */
#define INT2_SENCE_CONTROL_STATE           INT2_FALLING_EDGE

/*chose:
 * GISR_ENEBLE for enable GISR
 * GISR_DISEBLE FOR disable GISR*/
#define GISR_STATE                         GISR_ENEBLE

#endif /* EXTI_CONFIG_H_ */
