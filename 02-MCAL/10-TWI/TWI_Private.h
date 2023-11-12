/***********************************************************************************/
/************** 	Author : Usef Elbedwehy              		************************************/
/**************	 	Layer : MACL 						             ***********************************/
/**************	 	SWC : TWI    						           	***********************************/
/************** 	Version : V1         						   		**********************************/
/*******************************************************************************/
#ifndef 	TWI_PRIVATE_H_
#define 	TWI_PRIVATE_H_


#define START_ACK							0x08  /*start has been sent*/
#define REP_START_ACK						0x10  /* A repeated START condition has been transmitted*/
#define SLAVE_ADD_AND_WR_ACK				0x18  /*SLA+W has been transmitted , ACK has been received*/
#define SLAVE_ADD_AND_RD_ACK				0x40  /*SLA+R has been transmitted , ACK has been received*/
#define MSTR_WR_BYTE_ACK					0x28  /*Data byte has been transmitted , ACK has been received*/
#define MSTR_RD_BYTE_WITH_ACK				0x50  /*Data byte has been received , ACK has been returned*/
#define MSTR_RD_BYTE_WITH_NACK				0x58  /*Data byte has been received , NACK has been returned*/
#define SLAVE_ADD_RCVD_RD_REQ				0xA8  /*Own SLA+R has been received , ACK has been returned*/
#define SLAVE_ADD_RCVD_WR_REQ				0x60  /*Own SLA+W has been received , ACK has been returned*/
#define SLAVE_DATA_RECEIVE					0x80  /*Previously addressed with own SLA+W , data has been received , ACK has been returned*/
#define SLAVE_BYTE_TRANSMITTED				0xB8  /*Data byte in TWDR has been transmitted , ACK has been received*/

#define SLAVE_ADD_AND_WR_NACK				0x20  /*SLA+W has been transmitted , NACK has been received*/
#define MSTR_WR_BYTE_NACK					0x30  /*Data byte has been transmitted , NACK has been received*/

#endif
