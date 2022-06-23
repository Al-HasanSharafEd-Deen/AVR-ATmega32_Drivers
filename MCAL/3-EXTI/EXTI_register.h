/*************************************************************************/
/*************************************************************************/
/**********************   Author:  Al-Hasan Ameer   **********************/
/**********************   LAYER:   MCAL             **********************/
/**********************   SWC:     EXTI             **********************/
/**********************   VERSION: 1.00             **********************/
/*************************************************************************/
/*************************************************************************/

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

/*external Interrupt Registers define*/
#define MCUCR                *((volatile u8*) 0x55)
#define MCUCSR               *((volatile u8*) 0x54)
#define GICR                 *((volatile u8*) 0x5B)
#define GIFR                 *((volatile u8*) 0X5A)

/*setup of MCU CONTROL REG bits*/
#define MCUCR_ISC00          0
#define MCUCR_ISC01          1
#define MCUCR_ISC10          2
#define MCUCR_ISC11          3

/*setup of MCU CONTROL and STATUS REG bit*/
#define MCUCSR_ISC2          6

/*setup of GLOBAL INTERRUPT CONTROL REG bits*/
#define GICR_INT1            7
#define GICR_INT0            6
#define GICR_INT2            5

/*setup of GLOBAL INTERRUPT FLAG REG bits*/
#define GIFR_INTF1           7
#define GIFR_INTF0           6
#define GIFR_INTF2           5

#endif /* EXTI_REGISTER_H_ */
