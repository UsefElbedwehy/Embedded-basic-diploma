/***********************************************************************************/
/************** 	Author : Usef Elbedwehy              		************************************/
/**************	 	Layer : MACL 						             ***********************************/
/**************	 	SWC : TWI    						           	***********************************/
/************** 	Version : V1         						   		**********************************/
/*******************************************************************************/
#ifndef 		TWI_REGISTER_H_
#define 	TWI_REGISTER_H_

#define		TWI_TWDR			*((volatile u8)0x23)		/*Two-wire Serial Interface Data Register*/
#define		TWI_TWAR			*((volatile u8)0x22)		/*Two-wire Serial Interface Address Register*/
#define		TWAR_TWA6         7
#define		TWAR_TWA5         6
#define		TWAR_TWA4         5
#define		TWAR_TWA3         4
#define		TWAR_TWA2         3
#define		TWAR_TWA1         2
#define		TWAR_TWA0         1
#define		TWAR_TWGCE		0


#define		TWI_TWSR			*((volatile u8)0x21)		/*Two-wire Serial Interface Status Register*/
#define		TWSR_TWPS0		0
#define		TWSR_TWPS1       1
#define		TWSR_TWPS3       3
#define		TWSR_TWPS4       4
#define		TWSR_TWPS5       5
#define		TWSR_TWPS6       6
#define		TWSR_TWPS7       7

#define		TWI_TWBR			*((volatile u8)0x20)		/*Two-wire Serial Interface Bit Rate Register*/
#define		TWI_TWCR			*((volatile u8)0x56)		/*Two-wire Serial Interface Control Register*/
#define		TWCR_TWINT 		7
#define		TWCR_TWEA 		6
#define		TWCR_TWSTA 		5
#define		TWCR_TWSTO 		4
#define		TWCR_TWWC 		3
#define		TWCR_TWEN 		2
#define		TWCR_TWIE			0

#endif