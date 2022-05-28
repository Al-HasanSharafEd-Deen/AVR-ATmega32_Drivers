/*******************************************************************************/
/*******************************************************************************/
/**********************   Author:  Al-Hasan Ameer    ***************************/
/**********************   LAYER:   HAL               ***************************/
/**********************   SWC:     SSD               ***************************/
/*******************************************************************************/
/*******************************************************************************/

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"


/*STRUCT ELEMENTS
u8 copy_u8SSDPort;
u8 copy_u8EnPort;
u8 copy_u8EnPin;
u8 copy_u8SSDType;*/

u8 SSD_u8Dispaly(u8 copy_u8Number,SSD_t* SSD)
{
	u8 Local_u8ErrorState=0;
	if(copy_u8Number<=9)
	{
		if((SSD->copy_u8SSDPort<=DIO_u8PORTD) && (SSD->copy_u8EnPort<=DIO_u8PORTD )&& (SSD->copy_u8EnPin<=DIO_u8PIN7))
		{
			DIO_u8SetPortDirection(SSD->copy_u8SSDPort, DIO_u8PORT_OUTPUT);
			DIO_u8SetPinDirection(SSD->copy_u8EnPort, SSD->copy_u8EnPin, DIO_u8PIN_OUTPUT);
		}
		else{
			Local_u8ErrorState=1;
		}

		if(SSD->copy_u8SSDType==SSD_CATHODE)
		{
			DIO_u8SetPinValue(SSD->copy_u8EnPort, SSD->copy_u8EnPin,DIO_u8PIN_LOW);
			DIO_u8SetPortValue(SSD->copy_u8SSDPort, DisplayNumber[copy_u8Number]);
		}
		else if(SSD->copy_u8SSDType==SSD_ANODE)
		{
			DIO_u8SetPinValue(SSD->copy_u8EnPort, SSD->copy_u8EnPin,DIO_u8PIN_HIGH);
			DIO_u8SetPortValue(SSD->copy_u8SSDPort, ~DisplayNumber[copy_u8Number]);
		}else{
			Local_u8ErrorState=1;
		}
	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}


//u8 SSD_u8Init(u8 copy_u8SSDPort,u8 copy_u8EnPin,u8 copy_u8EnPort)
//{
//	u8 Local_u8ErrorState=0;
//	if(copy_u8SSDPort<=DIO_u8PORTD && copy_u8EnPort<=DIO_u8PORTD && copy_u8EnPin<=DIO_u8PIN7)
//	{
//		DIO_u8SetPortDirection(copy_u8SSDPort, DIO_u8PORT_OUTPUT);
//		DIO_u8SetPinDirection(copy_u8EnPort, copy_u8EnPin, DIO_u8PIN_OUTPUT);
//		DIO_u8SetPinValue(copy_u8EnPort, copy_u8EnPin,DIO_u8PIN_HIGH);
//	}
//	else
//	{
//		Local_u8ErrorState=0;
//	}
//	return Local_u8ErrorState;
//}
//
//
//u8 SSD_u8DispalyNumber(u8 copy_u8SSDPort,u8 copy_u8Number,u8 copy_u8SSDType)
//{
//	u8 Local_u8ErrorState=0;
//	if(copy_u8Number<=9)
//	{
//		if(copy_u8SSDType==SSD_CATHODE)
//		{
//			DIO_u8SetPortValue(copy_u8SSDPort, DisplayNumber[copy_u8Number]);
//		}
//		else if(copy_u8SSDType==SSD_ANODE)
//		{
//			DIO_u8SetPortValue(copy_u8SSDPort, ~DisplayNumber[copy_u8Number]);
//		}
//		else{
//			Local_u8ErrorState=1;
//		}
//	}else{
//		Local_u8ErrorState=1;
//	}
//
//	return Local_u8ErrorState;
//}







