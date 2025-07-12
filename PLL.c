
#include"PLL.h"
void PLL_SET()
{
	PLL0CON = 0x01; //PLL Enable
	PLL0CFG = 0x24; //PLL Multiplier value "M“ PLL Divider value “P“ PLL0FEED = 0xAA;
	PLL0FEED = 0x55;
	while(!PLL0STAT&(1<<10)); //Wait for PLL to lock to desired frequency
	PLL0CON = 0x03; //PLL Enable and Connect
	PLL0FEED = 0xAA;
	PLL0FEED = 0x55;
	VPBDIV = 0x01; // APB bus clock is the same as the processor clock.
	
}