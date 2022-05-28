/*******************************************************************************/
/*******************************************************************************/
/**********************   Author:  Al-Hasan Ameer    ***************************/
/**********************   LAYER:   HAL               ***************************/
/**********************   SWC:     SSD               ***************************/
/*******************************************************************************/
/*******************************************************************************/

/*Preprocessor file guard*/
#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define SSD_CATHODE          0
#define SSD_ANODE            1

typedef struct
{
		u8 copy_u8SSDPort;
		u8 copy_u8EnPort;
		u8 copy_u8EnPin;
		u8 copy_u8SSDType;

}SSD_t;

u8 SSD_u8Dispaly(u8 copy_u8Number,SSD_t* SSD);

//u8 SSD_u8Init(u8 copy_u8SSDPort,u8 copy_u8EnPin,u8 copy_u8EnPort);
//u8 SSD_u8DispalyNumber(u8 copy_u8SSDPort,u8 copy_u8Number,u8 copy_u8SSDType);
#endif /* SSD_INTERFACE_H_ */
