/*******************************************************************************/
/*******************************************************************************/
/**********************   Author:  Al-Hasan Ameer    ***************************/
/**********************   LAYER:   HAL               ***************************/
/**********************   SWC:     STPMOTOR          ***************************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef STEPMOTOR_INTERFACE_H_
#define STEPMOTOR_INTERFACE_H_

#define STEPMOTOR_CW                     0
#define STEPMOTOR_ACW                    1
#define STEPMOTOR_STOP                   2

typedef struct
{
	u8 Copy_u8_StepMotorPort;
	u8 Copy_u8_StepMotorBlueCoil;
	u8 Copy_u8_StepMotorPinkCoil;
	u8 Copy_u8_StepMotorYellowCoil;
	u8 Copy_u8_StepMotorOrangCoil;

}STP_config;

u8 StepMotor_u8RotateControl(u8 Copy_u8State,STP_config* StpConfig);
u8 StepMotor_u8RotateAngle(u8 Copy_u8State,STP_config* StpConfig,u16 Copy_u16Angle);

#endif /* STEPMOTOR_INTERFACE_H_ */
