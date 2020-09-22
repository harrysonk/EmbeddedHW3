// Program written by: Harrison Kania
// Date Created: 9/21/2020
// Last Modified: 9/21/2020
//Homework 3
// Positive logic switch LED port C pin 6

#include <stdint.h>
#include "M:/Keil/EECS 3100ware/Project Templates/inc/tm4c123gh6pm.h"


void initPortC(void)
{ 
	volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000004;     // 1) activate clock for Port C
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTC_AMSEL_R &= ~0x40;      // 3) disable analog on PC6
  GPIO_PORTC_PCTL_R &= ~0x0F000000; // 4) PCTL GPIO on PC6
  GPIO_PORTC_DIR_R = 0x40;        // 5) direction PC6 output
  GPIO_PORTC_AFSEL_R &= ~0x40;      // 6) PC6 regular port function
  GPIO_PORTC_DEN_R |= 0x40;         // 7) enable PC6 digital port
}

// Make PC6 high
void LED_On(void)
{
  GPIO_PORTC_DATA_R = 0x40;
}

int main(void)
{ 
  
	volatile unsigned long delay;
	initPortC();
  GPIO_PORTC_DATA_R = 0x40;
	
	while(1)	
	{


  }
}

