/***********************************************************************************/
/************** 	Author : Usef Elbedwehy              		************************************/
/**************	 	Layer : MACL 						             ***********************************/
/**************	 	SWC : TWI    						           	***********************************/
/************** 	Version : V1         						   		**********************************/
/*******************************************************************************/
#include "STDTYPES.h"
#include "BITMATH.h"

#include "TWI_Register.h"
#include "TWI_Private.h"
#include "TWI_Config.h"
#include "TWI_Interface.h"

/*pass 0 in the slave address argument if master will not be addressed*/
void TWI_VoidMasterInit(u8 Copy_u8SlaveAddress)
{
	/*set clock freq to 400kbps*/
	/*Set TWBR*/
	TWI_TWBR=2;
	/*Clear TWPR*/
	CLRBit(TWI_TWSR,TWSR_TWPS0);
	CLRBit(TWI_TWSR,TWSR_TWPS1);
	/*Initialize the node address*/
	if(Copy_u8SlaveAddress!=0)
	{
		TWI_TWAR=(Copy_u8SlaveAddress<<1);
	}
	/*Enable the TWI*/
	SetBit(TWI_TWCR,TWCR_TWEN);
}

void TWI_VoidSlaveInit(u8 Copy_u8SlaveAddress)
{
	/*Initialize the node address*/
	TWI_TWAR=(Copy_u8SlaveAddress<<1);
	/*Enable the TWI*/
	SetBit(TWI_TWCR,TWCR_TWEN);
}

TWI_ErrorStatus TWI_SendStartCondition(void)
{
	TWI_ErrorStatus Local_ErrorState = NoError;

	/*Send Start Condition on the Bus*/
	SetBit(TWI_TWCR,TWCR_TWSTA);

	/*The flag is raised by default to let you make your setting
	 * ,so u should clear the flag to continue*/
	/*Clear the interrupt flag to start the previous operation*/
	SetBit(TWI_TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again and the previous operation is completed*/
	while((GetBit(TWI_TWCR,TWCR_TWINT))==0);

	/*Check the operation*/
	if((TWI_TWSR&0b11111000)!=START_ACK)
	{
		Local_ErrorState = StartCondError;
	}
	else
	{
		/*Do Nothing*/
	}

	return Local_ErrorState;
}

TWI_ErrorStatus TWI_SendRepeatedStartCondition(void)
{
	TWI_ErrorStatus Local_ErrorState = NoError;

	/*Send Start Condition on the Bus*/
	SetBit(TWI_TWCR,TWCR_TWSTA);

	/*The flag is raised by default to let you make your setting
	 * ,so u should clear the flag to continue*/
	/*Clear the interrupt flag to start the previous operation*/
	SetBit(TWI_TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again and the previous operation is completed*/
	while((GetBit(TWI_TWCR,TWCR_TWINT))==0);

	/*Check the operation*/
	if((TWI_TWSR&0b11111000)!=REP_START_ACK)
	{
		Local_ErrorState = RepeatedStartCondError;
	}
	else
	{
		/*Do Nothing*/
	}

	return Local_ErrorState;
}

TWI_ErrorStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus Local_ErrorState = NoError;

	/*Clear the start condition bit*/
	CLRBit(TWI_TWCR,TWCR_TWSTA);

	/*Set the slave address in the 7 MSB of data register*/
	TWI_TWDR=Copy_u8SlaveAddress<<1;
	/*Clear the R/W bit to make a write request*/
	CLRBit(TWI_TWDR,0);
	/*Clear the interrupt flag to start the previous operation*/
	SetBit(TWI_TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again and the previous operation is completed*/
	while((GetBit(TWI_TWCR,TWCR_TWINT))==0);

	/*Check the operation*/
	if((TWI_TWSR&0b11111000)!=SLAVE_ADD_AND_WR_ACK)
	{
		Local_ErrorState = SlaveAddressWithWriteError;
	}
	else
	{
		/*Do Nothing*/
	}
	return Local_ErrorState;
}

TWI_ErrorStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus Local_ErrorState = NoError;

	/*Clear the start condition bit*/
	CLRBit(TWI_TWCR,TWCR_TWSTA);

	/*Set the slave address in the 7 MSB of data register*/
	TWI_TWDR=Copy_u8SlaveAddress<<1;
	/*Set the R/W bit to make a Read request*/
	SetBit(TWI_TWDR,0);
	/*Clear the interrupt flag to start the previous operation*/
	SetBit(TWI_TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again and the previous operation is completed*/
	while((GetBit(TWI_TWCR,TWCR_TWINT))==0);

	/*Check the operation*/
	if((TWI_TWSR&0b11111000)!=SLAVE_ADD_AND_RD_ACK)
	{
		Local_ErrorState = SlaveAddressWithReadError;
	}
	else
	{
		/*Do Nothing*/
	}

	return Local_ErrorState;
}

TWI_ErrorStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{
	TWI_ErrorStatus Local_ErrorState = NoError;

	/*Write the data byte*/
	TWI_TWDR=Copy_u8DataByte;
	/*Clear the interrupt flag to start the previous operation*/
	SetBit(TWI_TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again and the previous operation is completed*/
	while((GetBit(TWI_TWCR,TWCR_TWINT))==0);

	/*Check the operation*/
	if((TWI_TWSR&0b11111000)!=MSTR_WR_BYTE_ACK)
	{
		Local_ErrorState = MasterWriteByteError;
	}
	else
	{
		/*Do Nothing*/
	}
	return Local_ErrorState;
}

TWI_ErrorStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataByte)
{
	TWI_ErrorStatus Local_ErrorState = NoError;

	/*Enable master generating acknowledge bit after receiving data*/
	SetBit(TWI_TWCR,TWCR_TWEA);

	/*Clear the interrupt flag to start the slave sending data*/
	SetBit(TWI_TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again and the previous operation is completed*/
	while((GetBit(TWI_TWCR,TWCR_TWINT))==0);

	/*Check the operation*/
	if((TWI_TWSR&0b11111000)!=MSTR_RD_BYTE_WITH_ACK)
	{
		Local_ErrorState = MasterReadByteError;
	}
	else
	{
		/*Read the received data byte*/
		*Copy_pu8DataByte=TWI_TWDR;
	}

	return Local_ErrorState;
}

void TWI_SendStopCondition(void)
{
	/*Send Stop Condition on the Bus*/
	SetBit(TWI_TWCR,TWCR_TWSTO);
	/*Clear the interrupt flag to start the previous operation*/
	SetBit(TWI_TWCR,TWCR_TWINT);
}
