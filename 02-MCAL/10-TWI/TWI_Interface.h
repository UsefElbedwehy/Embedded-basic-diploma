/***********************************************************************************/
/************** 	Author : Usef Elbedwehy              		************************************/
/**************	 	Layer : MACL 						             ***********************************/
/**************	 	SWC : TWI    						           	***********************************/
/************** 	Version : V1         						   		**********************************/
/*******************************************************************************/
#ifndef 	TWI_INTERFACE_H_
#define 	TWI_INTERFACE_H_

typedef enum{
NoError,
StartCondError,
RepeatedStartCondError,
SlaveAddressWithWriteError,
SlaveAddressWithReadError,
MasterWriteByteError,
MasterReadByteError
}TWI_ErrorStatus;
/*pass 0 in the slave address argument if master will not be addressed*/
void TWI_VoidMasterInit(u8 Copy_u8SlaveAddress);

void TWI_VoidSlaveInit(u8 Copy_u8SlaveAddress);

TWI_ErrorStatus TWI_SendStartCondition(void);

TWI_ErrorStatus TWI_SendRepeatedStartCondition(void);

TWI_ErrorStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

TWI_ErrorStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

TWI_ErrorStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte);

TWI_ErrorStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataByte);

void TWI_SendStopCondition(void);

#endif
