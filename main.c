
/*--------------------------------------------------------------------------------------------------------------------------
 * file name  : main.c
 * Author     : OUN
 * Created on : Jan 27, 2021
 * description: application code of the clock
 --------------------------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------INCLUDES------------------------------------------------------------*/

#include "tm4c123gh6pm_registers.h"
#include "GPIO.h"
#include "DIO.h"
#include "switchs.h"

/*----------------------------------------------------DFINATIONS-----------------------------------------------------------*/

#define NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND 762

#define SYSTICK_PRIORITY_MASK  0x1FFFFFFF
#define SYSTICK_INTERRUPT_PRIORITY  3
#define SYSTICK_PRIORITY_BITS_POS   29

/* Enable IRQ Interrupts ... This Macro enables IRQ interrupts by clearing the I-bit in the PRIMASK. */
#define Enable_Interrupts()    __asm("CPSIE I")

/* Disable IRQ Interrupts ... This Macro disables IRQ interrupts by setting the I-bit in the PRIMASK. */
#define Disable_Interrupts()   __asm("CPSID I")

/* Go to low power mode while waiting for the next interrupt */
#define Wait_For_Interrupt()   __asm("WFI")

/*-------------------------------------------------GLOBAL VARIABLES---------------------------------------------------------*/

/* variable to count one minute after 59 sec*/
volatile unsigned char counter = 0;

/* varible to flag that the time now is in the range 1-9 or 10-12 */
volatile unsigned char flag = 2;

/*
* time[0] is the value of the first digit of minutes
* time[1] is the value of the second digit of minutes
* time[2] is the value of the first digit of hours
* time[3] is the value of the second digit of hours
*/unsigned char time[4] = {0};

/*-------------------------------------------------FUNCTION DEFINITION-----------------------------------------------------*/

void Delay_MS(unsigned long long n)
{
    volatile unsigned long long count = 0;
    while(count++ < (NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND * n) );
}

void SysTick_init(void) {

	SYSTICK_CTRL_REG = 0;               /* Disable the SysTick Timer by Clear the ENABLE Bit */
	SYSTICK_RELOAD_REG = 15999999;         /* Set the Reload value with 15999999 to count a Second */
	SYSTICK_CURRENT_REG = 0;               /* Clear the Current Register value */
										   /* Configure the SysTick Control Register
										   * Enable the SysTick Timer (ENABLE = 1)
										   * Enable SysTick Interrupt (INTEN = 1)
										   * Choose the clock source to be System Clock (CLK_SRC = 1) */
	SYSTICK_CTRL_REG |= 0x07;
	/* Assign priority level 3 to the SysTick Interrupt */
	NVIC_SYSTEM_PRI3_REG = (NVIC_SYSTEM_PRI3_REG & SYSTICK_PRIORITY_MASK) | (SYSTICK_INTERRUPT_PRIORITY << SYSTICK_PRIORITY_BITS_POS);
}

int main() {

	volatile unsigned long delay = 0;
	SYSCTL_REGCGC2_REG |= (1 << 0);         /* enabel clock for GPIO_PORTA*/
	SYSCTL_REGCGC2_REG |= (1 << 1);         /* enabel clock for GPIO_PORTB*/
	SYSCTL_REGCGC2_REG |= (1 << 3);         /* enabel clock for GPIO_PORTD*/
	SYSCTL_REGCGC2_REG |= (1 << 4);         /* enabel clock for GPIO_PORTE*/
        SYSCTL_REGCGC2_REG |= (1 << 5);         /* enabel clock for GPIO_PORTE*/
	delay = SYSCTL_REGCGC2_REG;

	PIN_A5_out_init();
	PIN_A6_out_init();
	PIN_B4_out_init();
	PIN_D3_out_init();
	PIN_E1_out_init();
	PIN_E2_out_init();
	PIN_E3_out_init();
	PIN_E5_out_init();
        
	SW1_Init();
        SW2_Init();
	SysTick_init();

	/* Global Interrupts Enable */
	Enable_Interrupts();


	while (1) {
          /*
	   * desplay the time
	   */
                unsigned char i;
		for (i = 0; i<4; i++) {
                        if((time[3] == 0) && i == 3) continue; 
			ena_seg(4-i);
			set_num(time[i]);
			Delay_MS(2);
			dis_seg(4-i);
		}
	}
}

/*--------------------------------------------------------ISRS--------------------------------------------------------*/

void SysTick_Handler(void) {
        /*
         * increase the time each systick interrupt
         * when overflow happen in one 7-segment the other one increases 
         */
	counter++;
	if (counter == 59) {
		counter = 0;
		if (time[0] == 9) {
			time[0] = 0;
			if (time[1] == 5) {
				time[1] = 0;
				if ((time[2] == 2) && (flag == 9)) {
					flag = 2;
					time[2] = 1;
					if (time[3] == 1) {
						time[3] = 0;
					}
					else {
						time[3]++;
					}
				}
				else if ((time[2] == 9) && (flag == 2)) {
					flag = 9;
					time[2] = 0;
					if (time[3] == 1) {
						time[3] = 0;
					}
					else {
						time[3]++;
					}
				}
				else {
					time[2]++;
				}
			}
			else {
				time[1]++;
			}
		}
		else {
			time[0]++;
		}
	}
	/*
	* increase the time with each interrupt request
	*/
}

