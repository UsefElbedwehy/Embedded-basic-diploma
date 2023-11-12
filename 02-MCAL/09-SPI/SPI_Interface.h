/***********************************************************************************/
/************** 	Author : Usef Elbedwehy              		************************************/
/**************	 	Layer : MACL 						             ***********************************/
/**************	 	SWC : SPI    						           		***********************************/
/************** 	Version : V1         						   		**********************************/
/************** 	Thursday, September 21, 2023    	    *********************************/
/******************************************************************************/
#ifndef 		SPI_INTERFACE_H_
#define 	SPI_INTERFACE_H_

void SPI_VoidMasterInit(void);
void SPI_VoidSlaveInit(void);
u8 SPI_u8Transeive(u8 Copy_u8Data);

#endif