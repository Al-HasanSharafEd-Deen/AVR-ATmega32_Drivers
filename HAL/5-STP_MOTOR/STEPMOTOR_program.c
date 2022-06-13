/*******************************************************************************/
/*******************************************************************************/
/**********************   Author:  Al-Hasan Ameer    ***************************/
/**********************   LAYER:   HAL               ***************************/
/**********************   SWC:     STPMOTOR          ***************************/
/*******************************************************************************/
/*******************************************************************************/


/*****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO/DIO_interface.h"
#include "STEPMOTOR_config.h"
#include "STEPMOTOR_interface.h"
#include "STEPMOTOR_private.h"

#include <util/delay.h>
/*****************************************************************/

//typedef struct
//{
//	u8 Copy_u8_StepMotorPort;
//	u8 Copy_u8_StepMotorBlueCoil;
//	u8 Copy_u8_StepMotorPinkCoil;
//	u8 Copy_u8_StepMotorYellowCoil;
//	u8 Copy_u8_StepMotorOrangCoil;
//
//}STP_config;


/* rotate Control Function
 * Brief: By this function we can control the stepper motor Clockwise, Anti-Clockwise or Stop.
 * Parameters:
   - Copy_u8State --> the rotate state as we want
   <<chose: STEPMOTOR_CW == Clockwise rotation, STEPMOTOR_ACW == Anti-Clockwise rotation, STEPMOTOR_STOP==Stop>>
   - StpConfig --> struct of stepper motor configuration
   <<Copy_u8_StepMotorPort; Copy_u8_StepMotorBlueCoil; Copy_u8_StepMotorPinkCoil; Copy_u8_StepMotorYellowCoil; Copy_u8_StepMotorOrangCoil;>>
 */
u8 StepMotor_u8RotateControl(u8 Copy_u8State,STP_config* StpConfig)
{
	u8 Local_u8ErrorState=0;
	switch(Copy_u8State)
	{
	case STEPMOTOR_ACW :
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorBlueCoil,   DIO_u8PIN_LOW);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorPinkCoil,  DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorYellowCoil,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorOrangCoil, DIO_u8PIN_HIGH);
		_delay_ms(2);

		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorBlueCoil,  DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorPinkCoil,   DIO_u8PIN_LOW);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorYellowCoil,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorOrangCoil, DIO_u8PIN_HIGH);
		_delay_ms(2);

		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorBlueCoil,  DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorPinkCoil,  DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorYellowCoil, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorOrangCoil, DIO_u8PIN_HIGH);
		_delay_ms(2);

		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorBlueCoil,  DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorPinkCoil,  DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorYellowCoil,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorOrangCoil, DIO_u8PIN_LOW);
		_delay_ms(2);
		break;

	case STEPMOTOR_CW :
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorBlueCoil,  DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorPinkCoil,  DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorYellowCoil,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorOrangCoil,  DIO_u8PIN_LOW);
		_delay_ms(2);

		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorBlueCoil,  DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorPinkCoil,  DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorYellowCoil, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorOrangCoil, DIO_u8PIN_HIGH);
		_delay_ms(2);

		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorBlueCoil,  DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorPinkCoil,   DIO_u8PIN_LOW);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorYellowCoil,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorOrangCoil, DIO_u8PIN_HIGH);
		_delay_ms(2);

		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorBlueCoil,   DIO_u8PIN_LOW);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorPinkCoil,  DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorYellowCoil,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorOrangCoil, DIO_u8PIN_HIGH);
		_delay_ms(2);
		break;

	case STEPMOTOR_STOP :
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorBlueCoil,  DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorPinkCoil,  DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorYellowCoil,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorOrangCoil, DIO_u8PIN_HIGH);
		_delay_ms(2);

		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorBlueCoil,  DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorPinkCoil,  DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorYellowCoil,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorOrangCoil, DIO_u8PIN_HIGH);
		_delay_ms(2);

		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorBlueCoil,  DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorPinkCoil,  DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorYellowCoil,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorOrangCoil, DIO_u8PIN_HIGH);
		_delay_ms(2);

		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorBlueCoil,  DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorPinkCoil,  DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorYellowCoil,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(StpConfig->Copy_u8_StepMotorPort, StpConfig->Copy_u8_StepMotorOrangCoil, DIO_u8PIN_HIGH);
		_delay_ms(2);
		break;
	default:Local_u8ErrorState=1;

	}
	return Local_u8ErrorState;
}


/* rotate Angle Function
 * Brief: By this function we can control the stepper motor angle of rotation.
          we can control state of rotation by this function too.
 * Parameters:
   - Copy_u16Angle --> the rotation angle.
   << we can set the angle degree of rotation, max 360 degree.
   - Copy_u8State --> the rotate state as we want
   <<chose: STEPMOTOR_CW == Clockwise rotation, STEPMOTOR_ACW == Anti-Clockwise rotation, STEPMOTOR_STOP==Stop>>
   - StpConfig --> struct of stepper motor configuration
   <<Copy_u8_StepMotorPort; Copy_u8_StepMotorBlueCoil; Copy_u8_StepMotorPinkCoil; Copy_u8_StepMotorYellowCoil; Copy_u8_StepMotorOrangCoil;>>
 */
u8 StepMotor_u8RotateAngle(u8 Copy_u8State,STP_config* StpConfig,u16 Copy_u16Angle)
{
	u8 Local_u8ErrorState=0;
	u32 Local_u32Steps;
	u32 Local_u32counter;
	if(Copy_u16Angle<=360)
	{
		Local_u32Steps=(u32)((2048* (u32)Copy_u16Angle) / (360 * 4));
		for(Local_u32counter=0;Local_u32counter<Local_u32Steps;Local_u32counter++)
		{
			StepMotor_u8RotateControl(Copy_u8State, StpConfig);
		}
	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}









