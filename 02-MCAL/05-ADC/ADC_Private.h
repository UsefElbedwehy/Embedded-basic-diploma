#ifndef		ADC_PRIVATE_H_
#define		ADC_PRIVATE_H_
/*Voltage Reference Selection*/
#define	AREF							1
#define	AVCC               				2
#define	Internal_2Point56V  			3
/*ADC Prescaler Selections*/
#define	PrescalerDivisionBy2			1
#define	PrescalerDivisionBy4            2
#define	PrescalerDivisionBy8  			3
#define	PrescalerDivisionBy16			4
#define	PrescalerDivisionBy32           5
#define	PrescalerDivisionBy64  			6
#define	PrescalerDivisionBy128			7

#define	ADC_PRESCALER_MASK				0b11111000

/*ADLAR: Left adjust result*/
#define	LEFT_ADJUST						1
#define	RIGHT_ADJUST               		2


#endif
