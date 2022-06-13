/*******************************************************************************/
/*******************************************************************************/
/**********************   Author:  Al-Hasan Ameer    ***************************/
/**********************   LAYER:   HAL               ***************************/
/**********************   SWC:     DCMOTOR           ***************************/
/*******************************************************************************/
/*******************************************************************************/


/***************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO/DIO_interface.h"

#include "DCMOTOR_config.h"
#include "DCMOTOR_interface.h"
#include "DCMOTOR_private.h"
/***************************************************************/

/*this function makes the DC-Motor to rotate clockwise*/
void DcMotor_voidRotateCw(void)
{
	DIO_u8SetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN1, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN0, DIO_u8PIN_HIGH);
}

/*this function makes the DC-Motor to rotate anti-clockwise*/
void DcMotor_voidRotateAnCw(void)
{
	DIO_u8SetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN0, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN1, DIO_u8PIN_HIGH);
}

/*this function stops the motor*/
void DcMotor_voidStop(void)
{
	DIO_u8SetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN0, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN1, DIO_u8PIN_LOW);
}


