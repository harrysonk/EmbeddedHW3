// Program written by: Harrison Kania
// Date Created: 9/21/2020
// Last Modified: 9/22/2020
//Homework 3
//Code initializes PA5, PA4, and PA3 as outputs
//Writes to these three pins using a 3 bit number (0-7)

#include <stdint.h>
#include "M:/Keil/EECS 3100ware/Project Templates/inc/tm4c123gh6pm.h"

void initPortA(void)
{ 
	volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000001;     // 1) activate clock for Port A
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTA_AMSEL_R &= ~0x38;      // 3) disable analog on PA5, PA4, and PA3
  GPIO_PORTA_PCTL_R &= ~0x00FFF000; // 4) PCTL GPIO on PA5, PA4, and PA3
  GPIO_PORTA_DIR_R |= 0x38;        // 5) direction PA5, PA4, and PA3 output
  GPIO_PORTA_AFSEL_R &= ~0x38;      // 6) PA7 regular port function
  GPIO_PORTA_DEN_R |= 0x38;         // 7) enable PA7 digital port
}

void writeToPins(unsigned char value)
{
	if(value > 0x07)
	{
		//Can only accept values 0x00-0x07, return
		return;
	}
	//Shift over to the left three to get the correct position of the bits in
	//PA5-PA3
	GPIO_PORTA_DATA_R = (value << 3);
	
}
int main(void)
{ 	
	//Initialize Port A with correct parameters
	initPortA();
	
	//Call write to pins function with applicable values
	writeToPins(0x00);
	writeToPins(0x01);
	writeToPins(0x02);
	writeToPins(0x03);
	writeToPins(0x04);
	writeToPins(0x05);
	writeToPins(0x06);
	writeToPins(0x07);
	while(1)
		{
			
		}
}

