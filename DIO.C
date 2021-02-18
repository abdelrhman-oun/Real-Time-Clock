
/*--------------------------------------------------------------------------------------------------------------------------
 * file name  : DIO.C
 * Author     : OUN
 * Created on : Jan 27, 2021
 * description: tiva c DIO source file 
 --------------------------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------INCLUDES------------------------------------------------------------*/

#include "DIO.h"

/*-------------------------------------------------FUNCTION DEFINITION-----------------------------------------------------*/

void set_num(unsigned char num_1){
        
        /* mask the first bit of the number to PD3 pin*/
	GPIO_PORTD_DATA_REG = (GPIO_PORTD_DATA_REG & 0xFFFFFFF7) | (num_1 << 3);
        /* mask the secound bit of the number to PE1 pin*/
	GPIO_PORTE_DATA_REG = (GPIO_PORTE_DATA_REG & 0xFFFFFFFD) | (num_1 & (1 << 1));
        /* mask the third bit of the number to PE2 pin*/
	GPIO_PORTE_DATA_REG = (GPIO_PORTE_DATA_REG & 0xFFFFFFFB) | (num_1 & (1 << 2));
        /* mask the fourth bit of the number to PE3 pin*/
	GPIO_PORTE_DATA_REG = (GPIO_PORTE_DATA_REG & 0xFFFFFFF7) | (num_1 & (1 << 3));
}

void ena_seg(unsigned char num_2) {
        /* write high on the specific pin*/
	switch (num_2){
	case 1:
                /* write high on PE5*/
		GPIO_PORTE_DATA_REG = (GPIO_PORTE_DATA_REG & 0xFFFFFFDF) | (1 << 5);
		break;
	case 2:
		/* write high on PB4*/
                GPIO_PORTB_DATA_REG = (GPIO_PORTB_DATA_REG & 0xFFFFFFEF) | (1 << 4);
		break;
	case 3:
                /* write high on PA5*/
		GPIO_PORTA_DATA_REG = (GPIO_PORTA_DATA_REG & 0xFFFFFFDF) | (1 << 5);
		break;
	case 4:
                /* write high on PA6*/
		GPIO_PORTA_DATA_REG = (GPIO_PORTA_DATA_REG & 0xFFFFFFBF) | (1 << 6);
		break;
	default:
		break;
	}
}
void dis_seg(unsigned char num_3) {
        /* write low on the specific pin*/
	switch (num_3) {
	case 1:
                /* write low on PE5*/
		GPIO_PORTE_DATA_REG = (GPIO_PORTE_DATA_REG & 0xFFFFFFDF) & ~(1 << 5);
		break;
	case 2:
                /* write high on PB4*/
		GPIO_PORTB_DATA_REG = (GPIO_PORTB_DATA_REG & 0xFFFFFFEF) & ~(1 << 4);
		break;
	case 3:
                /* write high on PA5*/
		GPIO_PORTA_DATA_REG = (GPIO_PORTA_DATA_REG & 0xFFFFFFDF) & ~(1 << 5);
		break;
	case 4:
                /* write high on PA6*/
		GPIO_PORTA_DATA_REG = (GPIO_PORTA_DATA_REG & 0xFFFFFFBF) & ~(1 << 6);
		break;
	default:
		break;
	}
}

/*----------------------------------------------------------ISR-------------------------------------------------------------*/

/* GPIO PORTF External Interrupt - ISR */
void GPIOPortF_Handler(void)
{
	if (GPIO_PORTF_RIS_REG & (1 << 0)) {
		SYSTICK_CTRL_REG &= ~(1 << 0);		 /* SysTick Interrupt Disable*/
		GPIO_PORTF_ICR_REG |= (1 << 0);       /* Clear Trigger flag for PF0 (Interupt Flag) */
	}
	else if (GPIO_PORTF_RIS_REG & (1 << 4)) {
		SYSTICK_CTRL_REG |= (1 << 0);
		GPIO_PORTF_ICR_REG |= (1 << 4);       /* Clear Trigger flag for PF4 (Interupt Flag) */
	}
}
