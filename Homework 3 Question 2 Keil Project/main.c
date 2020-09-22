// Program written by:Harrison Kania
// Date Created:9/21/20
// Last Modified: 9/21/20
//Homework 3
//Negative logic switch to port B pin 0
#include <stdint.h>
#include "M:/Keil/EECS 3100ware/Project Templates/inc/tm4c123gh6pm.h"

void initPortB(void)
{ 
	volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000002;     // 1) activate clock for Port B
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTB_AMSEL_R &= ~0x01;      // 3) disable analog on PB0
  GPIO_PORTB_PCTL_R &= ~0x0000000F; // 4) PCTL GPIO on PB0
  GPIO_PORTB_DIR_R &= ~0x01;        // 5) direction PB0 input
  GPIO_PORTB_AFSEL_R &= ~0x01;      // 6) PB0 regular port function
	GPIO_PORTB_PUR_R = 0x01;          // 7)enable pull-up on PB0
  GPIO_PORTB_DEN_R |= 0x01;         // 8) enable PB0 digital port
}

//Function that reads in the portB pin 0 data
unsigned long Switch_Input2(void)
{

  return (GPIO_PORTB_DATA_R&0x01); // 0x01 not pressed or 0 if pressed

}

int main(void)
{ 
  
	volatile unsigned long delay;
	initPortB();
	
	while(1)
	{

			Switch_Input2();
  }
}

