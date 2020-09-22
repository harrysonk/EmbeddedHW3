// Program written by: Harrison Kania
// Date Created: 9/21/2020
// Last Modified: 9/21/2020
//Homework 3
// Positive logic switch to port A pin 7

#include <stdint.h>
#include "M:/Keil/EECS 3100ware/Project Templates/inc/tm4c123gh6pm.h"

void initPortA(void)
{ 
	volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000001;     // 1) activate clock for Port A
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTA_AMSEL_R &= ~0x80;      // 3) disable analog on PA7
  GPIO_PORTA_PCTL_R &= ~0xF0000000; // 4) PCTL GPIO on PA7
  GPIO_PORTA_DIR_R &= ~0x80;        // 5) direction PA7 input
  GPIO_PORTA_AFSEL_R &= ~0x80;      // 6) PA7 regular port function
  GPIO_PORTA_DEN_R |= 0x80;         // 7) enable PA7 digital port
}

//Function that reads in the portA pin 7 data
unsigned long Switch_Input2(void)
{

  return (GPIO_PORTA_DATA_R&0x80); // 0x80(pressed) or 0(not pressed)

}

int main(void)
{ 
  
	volatile unsigned long delay;
	volatile unsigned long test;
	initPortA();
	
	while(1)
		{
			//Test to check input
			test = Switch_Input2();
		}
}

