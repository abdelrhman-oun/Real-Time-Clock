/*--------------------------------------------------------------------------------------------------------------------------
 * file name  : switchs.C
 * Author     : OUN
 * Created on : Jan 27, 2021
 * description: tiva c switchs source file 
 --------------------------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------INCLUDES------------------------------------------------------------*/

#include "switchs.h"

/*----------------------------------------------------DFINATIONS-----------------------------------------------------------*/

#define GPIO_PORTF_PRIORITY_MASK      0xFF1FFFFF
#define GPIO_PORTF_PRIORITY_BITS_POS  21
#define GPIO_PORTF_INTERRUPT_PRIORITY 2

/*-------------------------------------------------FUNCTION DEFINITION-----------------------------------------------------*/

/* Enable PF4 (SW1) and activate external interrupt with falling edge */
void SW1_Init(void)
{
    GPIO_PORTF_LOCK_REG   = 0x4C4F434B;   /* Unlock the GPIO_PORTF_CR_REG */
    GPIO_PORTF_CR_REG    |= (1<<4);       /* Enable changes on PF4 */
    GPIO_PORTF_AMSEL_REG &= ~(1<<4);      /* Disable Analog on PF4 */
    GPIO_PORTF_PCTL_REG  &= 0xFFF0FFFF;   /* Clear PMCx bits for PF4 to use it as GPIO pin */
    GPIO_PORTF_DIR_REG   &= ~(1<<4);      /* Configure PF4 as input pin */
    GPIO_PORTF_AFSEL_REG &= ~(1<<4);      /* Disable alternative function on PF4 */
    GPIO_PORTF_PUR_REG   |= (1<<4);       /* Enable pull-up on PF4 */
    GPIO_PORTF_DEN_REG   |= (1<<4);       /* Enable Digital I/O on PF4 */
    GPIO_PORTF_IS_REG    &= ~(1<<4);      /* PF0 detect edges */
    GPIO_PORTF_IBE_REG   &= ~(1<<4);      /* PF0 will detect a certain edge */
    GPIO_PORTF_IEV_REG   &= ~(1<<4);      /* PF0 will detect a falling edge */
    GPIO_PORTF_ICR_REG   |= (1<<4);       /* Clear Trigger flag for PF4 (Interupt Flag) */
    GPIO_PORTF_IM_REG    |= (1<<4);       /* Enable Interrupt on PF4 pin */
    /* Set GPIO PORTF priotiy as 2 by set Bit number 22, 23 and 24 with value 2 */
    NVIC_PRI7_REG = (NVIC_PRI7_REG & GPIO_PORTF_PRIORITY_MASK) | (GPIO_PORTF_INTERRUPT_PRIORITY<<GPIO_PORTF_PRIORITY_BITS_POS); 
    NVIC_EN0_REG         |= 0x40000000;   /* Enable NVIC Interrupt for GPIO PORTF by set bit number 30 in EN0 Register */
}

/* Enable PF0 (SW2) and activate external interrupt with falling edge */
void SW2_Init(void)
{
    GPIO_PORTF_LOCK_REG   = 0x4C4F434B;   /* Unlock the GPIO_PORTF_CR_REG */
    GPIO_PORTF_CR_REG    |= (1<<0);       /* Enable changes on PF0 */
    GPIO_PORTF_AMSEL_REG &= ~(1<<0);      /* Disable Analog on PF0 */
    GPIO_PORTF_PCTL_REG  &= 0xFFFFFFF0;   /* Clear PMCx bits for PF0 to use it as GPIO pin */
    GPIO_PORTF_DIR_REG   &= ~(1<<0);      /* Configure PF0 as input pin */
    GPIO_PORTF_AFSEL_REG &= ~(1<<0);      /* Disable alternative function on PF0 */
    GPIO_PORTF_PUR_REG   |= (1<<0);       /* Enable pull-up on PF0 */
    GPIO_PORTF_DEN_REG   |= (1<<0);       /* Enable Digital I/O on PF0 */
    GPIO_PORTF_IS_REG    &= ~(1<<0);      /* PF0 detect edges */
    GPIO_PORTF_IBE_REG   &= ~(1<<0);      /* PF0 will detect a certain edge */
    GPIO_PORTF_IEV_REG   &= ~(1<<0);      /* PF0 will detect a falling edge */
    GPIO_PORTF_ICR_REG   |= (1<<0);       /* Clear Trigger flag for PF0 (Interupt Flag) */
    GPIO_PORTF_IM_REG    |= (1<<0);       /* Enable Interrupt on PF0 pin */
    /* Set GPIO PORTF priotiy as 2 by set Bit number 22, 23 and 24 with value 2 */
    NVIC_PRI7_REG = (NVIC_PRI7_REG & GPIO_PORTF_PRIORITY_MASK) | (GPIO_PORTF_INTERRUPT_PRIORITY<<GPIO_PORTF_PRIORITY_BITS_POS); 
    NVIC_EN0_REG         |= 0x40000000;   /* Enable NVIC Interrupt for GPIO PORTF by set bit number 30 in EN0 Register */
}
