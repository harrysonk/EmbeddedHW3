// Program written by: Harrison Kania
// Date Created: 9/21/2020
// Last Modified: 9/21/2020
//Homework 3
// Negative logic switch LED port D pin 3

#include <stdint.h>
#include "M:/Keil/EECS 3100ware/Project Templates/inc/tm4c123gh6pm.h"

void initPortD(void)
{ 
	volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000008;     // 1) activate clock for Port D
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTD_AMSEL_R &= ~0x08;      // 3) disable analog on PD3
  GPIO_PORTD_PCTL_R &= ~0x0000F000; // 4) PCTL GPIO on PD3
  GPIO_PORTD_DIR_R = 0x08;        // 5) direction PD3 output
  GPIO_PORTD_AFSEL_R &= ~0x08;      // 6) PD3 regular port function
  GPIO_PORTD_DEN_R |= 0x08;         // 7) enable PD3 digital port
}

// Make PD3 low
void LED_On(void)
{
  GPIO_PORTD_DATA_R = 0x08;
}

int main(void)
{ 
  
	volatile unsigned long delay;
	initPortD();
	
	LED_On();
	while(1)
	{

  }
}