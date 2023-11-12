#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

#define EXTI0_PORT							DIO_u8PORTD
#define EXTI1_PORT							DIO_u8PORTD
#define EXTI2_PORT							DIO_u8PORTC
/**********************************************************/
#define EXTI0_PIN							DIO_u8PIN2
#define EXTI1_PIN							DIO_u8PIN3
#define EXTI2_PIN							DIO_u8PIN3
/**********************************************************/
/*FOR CONTROL SENSE...OF INT0
		CHOOSE:
					1-LOW_LEVEL		
					2-ON_CHANGE		
					3-FALLING_EDGE	
					4-RISING_EDGE
 */
#define 	INT0_SENSE_CONTROL				FALLING_EDGE
/**********************************************************/
/*FOR CONTROL SENSE...OF INT1
		CHOOSE:
					1-LOW_LEVEL
					2-ON_CHANGE
					3-FALLING_EDGE
					4-RISING_EDGE
 */
#define 	INT1_SENSE_CONTROL				RISING_EDGE
/**********************************************************/
/*FOR CONTROL SENSE...OF INT2
		CHOOSE:
					1-FALLING_EDGE
					2-RISING_EDGE
 */
#define 	INT2_SENSE_CONTROL				FALLING_EDGE
/**********************************************************/
/*FOR INITIAL STATE...
		CHOOSE:
					1-ENABLED
					2-DISABLED
 */
/*INITIAL STATE OF INT0*/
#define 	INT0_INITIAL_STATE				ENABLED
/**********************************************************/
/*INITIAL STATE OF INT1*/
#define 	INT1_INITIAL_STATE				DISABLED
/**********************************************************/
/*INITIAL STATE OF INT2*/
#define 	INT2_INITIAL_STATE				DISABLED
/**********************************************************/
#endif
