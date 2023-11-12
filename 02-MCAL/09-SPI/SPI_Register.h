/***********************************************************************************/
/************** 	Author : Usef Elbedwehy              		************************************/
/**************	 	Layer : MACL 						             ***********************************/
/**************	 	SWC : SPI    						           		***********************************/
/************** 	Version : V1         						   		**********************************/
/************** 	Thursday, September 21, 2023    	    *********************************/
/******************************************************************************/
#ifndef 		SPI_REGISTER_H_
#define 	SPI_REGISTER_H_
/*********************************/
#define SPI_SPDR		*((volatile u8*)0x2F)
/*********************************/
#define SPI_SPSR		*((volatile u8*)0x2E)
#define	SPSR_SPI2X	0
#define	SPSR_WCOL	6
#define	SPSR_SPIF	7
/*********************************/
#define SPI_SPCR		*((volatile u8*)0x2D)
#define	SPCR_SPR0       	0
#define	SPCR_SPR1           1
#define	SPCR_CPHA           2
#define	SPCR_CPOL           3
#define	SPCR_MSTR           4
#define	SPCR_DORD          5
#define	SPCR_SPE             6
#define	SPCR_SPIE            7
/*********************************/
#endif