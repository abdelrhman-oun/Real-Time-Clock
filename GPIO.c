/*--------------------------------------------------------------------------------------------------------------------------
 * file name  : GPIO.C
 * Author     : OUN
 * Created on : Jan 27, 2021
 * description: tiva c GPIO source file 
 --------------------------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------INCLUDES------------------------------------------------------------*/

#include "GPIO.h"

/*-------------------------------------------------FUNCTION DEFINITION-----------------------------------------------------*/

void PIN_A5_out_init(void) {

	GPIO_PORTA_AMSEL_REG &= ~(1 << 5);              /* disable analog mode*/
	GPIO_PORTA_PCTL_REG &= 0xFF0FFFFF;              /* Clear PMCx bits for PA5 to use it as GPIO pin */
	GPIO_PORTA_DIR_REG |= (1 << 5);                 /* set PA5 as output pin */
	GPIO_PORTA_AFSEL_REG &= ~(1 << 5);              /* deactivate alternate functions*/
	GPIO_PORTA_DEN_REG |= (1 << 5);                 /* enable digital pin*/
	GPIO_PORTA_DATA_REG &= ~(1 << 5);               /* Clear bit 5 in Data regsiter to OUT 0 */
}

void PIN_A6_out_init(void) {

	GPIO_PORTA_AMSEL_REG &= ~(1 << 6);              /* disable analog mode*/
	GPIO_PORTA_PCTL_REG &= 0xF0FFFFFF;              /* Clear PMCx bits for PA6 to use it as GPIO pin */
	GPIO_PORTA_DIR_REG |= (1 << 6);                 /* set PA6 as output pin */
	GPIO_PORTA_AFSEL_REG &= ~(1 << 6);              /* deactivate alternate functions*/
	GPIO_PORTA_DEN_REG |= (1 << 6);                 /* enable digital pin*/
	GPIO_PORTA_DATA_REG &= ~(1 << 6);               /* Clear bit 6 in Data regsiter to OUT 0 */
}

void PIN_B4_out_init(void) {

	GPIO_PORTB_AMSEL_REG &= ~(1 << 4);              /* disable analog mode*/
	GPIO_PORTB_PCTL_REG &= 0xFFF0FFFF;              /* Clear PMCx bits for PB4 to use it as GPIO pin */
	GPIO_PORTB_DIR_REG |= (1 << 4);                 /* set PB4 as output pin */
	GPIO_PORTB_AFSEL_REG &= ~(1 << 4);              /* deactivate alternate functions*/
	GPIO_PORTB_DEN_REG |= (1 << 4);                 /* enable digital pin*/
	GPIO_PORTB_DATA_REG &= ~(1 << 4);               /* Clear bit 4 in Data regsiter to OUT 0 */
}

void PIN_D3_out_init(void) {

	GPIO_PORTD_AMSEL_REG &= ~(1 << 3);              /* disable analog mode*/
	GPIO_PORTD_PCTL_REG &= 0xFFFFF0FFF;             /* Clear PMCx bits for PD3 to use it as GPIO pin */
	GPIO_PORTD_DIR_REG |= (1 << 3);                 /* set PD3 as output pin */
	GPIO_PORTD_AFSEL_REG &= ~(1 << 3);              /* deactivate alternate functions*/
	GPIO_PORTD_DEN_REG |= (1 << 3);                 /* enable digital pin*/
	GPIO_PORTD_DATA_REG &= ~(1 << 3);               /* Clear bit 3 in Data regsiter to OUT 0 */
}

void PIN_E1_out_init(void) {

	GPIO_PORTE_AMSEL_REG &= ~(1 << 1);              /* disable analog mode*/
	GPIO_PORTE_PCTL_REG &= 0xFFFFFF0F;              /* Clear PMCx bits for PE1 to use it as GPIO pin */
	GPIO_PORTE_DIR_REG |= (1 << 1);                 /* set PE1 as output pin */
	GPIO_PORTE_AFSEL_REG &= ~(1 << 1);              /* deactivate alternate functions*/
	GPIO_PORTE_DEN_REG |= (1 << 1);                 /* enable digital pin*/
	GPIO_PORTE_DATA_REG &= ~(1 << 1);               /* Clear bit 1 in Data regsiter to OUT 0 */
}

void PIN_E2_out_init(void) {

	GPIO_PORTE_AMSEL_REG &= ~(1 << 2);              /* disable analog mode*/
	GPIO_PORTE_PCTL_REG &= 0xFFFFF0FF;              /* Clear PMCx bits for PE2 to use it as GPIO pin */
	GPIO_PORTE_DIR_REG |= (1 << 2);                 /* set PE2 as output pin */
	GPIO_PORTE_AFSEL_REG &= ~(1 << 2);              /* deactivate alternate functions*/
	GPIO_PORTE_DEN_REG |= (1 << 2);                 /* enable digital pin*/
	GPIO_PORTE_DATA_REG &= ~(1 << 2);               /* Clear bit 2 in Data regsiter to OUT 0 */
}

void PIN_E3_out_init(void) {

	GPIO_PORTE_AMSEL_REG &= ~(1 << 3);              /* disable analog mode*/
	GPIO_PORTE_PCTL_REG &= 0xFFFF0FFF;              /* Clear PMCx bits for PE3 to use it as GPIO pin */
	GPIO_PORTE_DIR_REG |= (1 << 3);                 /* set PE3 as output pin */
	GPIO_PORTE_AFSEL_REG &= ~(1 << 3);              /* deactivate alternate functions*/
	GPIO_PORTE_DEN_REG |= (1 << 3);                 /* enable digital pin*/
	GPIO_PORTE_DATA_REG &= ~(1 << 3);               /* Clear bit 3 in Data regsiter to OUT 0 */
}

void PIN_E5_out_init(void) {

	GPIO_PORTE_AMSEL_REG &= ~(1 << 5);              /* disable analog mode*/
	GPIO_PORTE_PCTL_REG &= 0xFF0FFFFF;              /* Clear PMCx bits for PE5 to use it as GPIO pin */
	GPIO_PORTE_DIR_REG |= (1 << 5);                 /* set PE5 as output pin */
	GPIO_PORTE_AFSEL_REG &= ~(1 << 5);              /* deactivate alternate functions*/
	GPIO_PORTE_DEN_REG |= (1 << 5);                 /* enable digital pin*/
	GPIO_PORTE_DATA_REG &= ~(1 << 5);               /* Clear bit 5 in Data regsiter to OUT 0 */
}