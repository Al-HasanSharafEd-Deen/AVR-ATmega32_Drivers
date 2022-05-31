/*******************************************************************************/
/*******************************************************************************/
/**********************   Author:  Al-Hasan Ameer    ***************************/
/**********************   LAYER:   HAL               ***************************/
/**********************   SWC:     KPD               ***************************/
/*******************************************************************************/
/*******************************************************************************/

#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"

u8 KPD_u8GetPressedKey(void)
{
	/********************setup Direction and values By DIO Driver********************/
	/***************************we can use PORT Driver too***************************/
	DIO_u8SetPinDirection(KPD_PORT, KPD_COL0_PIN, DIO_u8PIN_HIGH);
	DIO_u8SetPinDirection(KPD_PORT, KPD_COL1_PIN, DIO_u8PIN_HIGH);
	DIO_u8SetPinDirection(KPD_PORT, KPD_COL2_PIN, DIO_u8PIN_HIGH);
	DIO_u8SetPinDirection(KPD_PORT, KPD_COL3_PIN, DIO_u8PIN_HIGH);

	DIO_u8SetPinDirection(KPD_PORT, KPD_ROW0_PIN, DIO_u8PIN_LOW);
	DIO_u8SetPinDirection(KPD_PORT, KPD_ROW1_PIN, DIO_u8PIN_LOW);
	DIO_u8SetPinDirection(KPD_PORT, KPD_ROW2_PIN, DIO_u8PIN_LOW);
	DIO_u8SetPinDirection(KPD_PORT, KPD_ROW3_PIN, DIO_u8PIN_LOW);

	DIO_u8SetPortValue(KPD_PORT, DIO_u8PORT_HIGH);
	/*********************************************************************************/

	static u8 Local_u8ColIdx,Local_u8RowIdx,Local_u8PinState;
	static u8 Local_u8PressedKey=KPD_NO_PRESSED_KEY;
	static u8 Local_u8KPDArray[ROW_NUMBER][COL_NUMBER]=KPD_ARRAY_VAL;
	static u8 Local_u8KPDColArray[COL_NUMBER]=COL_PINS;
	static u8 Local_u8KPDRowArray[ROW_NUMBER]=ROW_PINS;

	for(Local_u8ColIdx=0;Local_u8ColIdx<COL_NUMBER;Local_u8ColIdx++)
	{
		/*Activate Current Column*/
		DIO_u8SetPinValue(KPD_PORT, Local_u8KPDColArray[Local_u8ColIdx], DIO_u8PIN_LOW);
		for(Local_u8RowIdx=0;Local_u8RowIdx<ROW_NUMBER;Local_u8RowIdx++)
		{
			/*Read The Current Row*/
			DIO_u8GetPinValue(KPD_PORT, Local_u8KPDRowArray[Local_u8RowIdx], &Local_u8PinState);
			/*Check pressed switch*/
			if(DIO_u8PIN_LOW==Local_u8PinState)
			{
				Local_u8PressedKey=Local_u8KPDArray[Local_u8RowIdx][Local_u8ColIdx];
				/*Busy waiting*/
				while(DIO_u8PIN_LOW==Local_u8PinState){
					DIO_u8GetPinValue(KPD_PORT, Local_u8KPDRowArray[Local_u8RowIdx], &Local_u8PinState);
				}
				return Local_u8PressedKey;
			}
		}
		/*Deactivate Current Column*/
		DIO_u8SetPinValue(KPD_PORT, Local_u8KPDColArray[Local_u8ColIdx], DIO_u8PIN_HIGH);
	}

	return Local_u8PressedKey;
}
