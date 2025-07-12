#include <LPC214x.h>
#include <stdbool.h>
#include"PLL.h"
#define led 17
#define led2 18	
bool flag = 1; 

void initTimer(void);
void PLL_SET();
void TIMER1()	__irq
{
	if(flag == 1)
	{
		IO0SET =(1<<led);//P0.17 as LOW
		IO0SET =(1<<led2);//P0.1 as HIGH
		flag = 0;
	}
	else
	{
		IO0CLR =(1<<led);//P0.31 as HIGH
		IO0CLR =(1<<led2);//P0.1 as LOW
		flag = 1;
	}
	T0IR |= (1<<0);//to reset Interrupt flag for match channel 0 or MR0
	//BIT[1] 	MR1 	Interrupt Interrupt flag for match channel 1.
	VICVectAddr = 0x00;
}

int main()
{
	IODIR0|=(1<<led)|(1<<led2);	
	initTimer();
	PLL_SET();
	while(1)
	{
		
	}
	return 0;
}

void initTimer()
{
	T0PR=59999; //Timer0 Match Register 
	T0MR0=1000; //Timer Match Control Reg
	//BIT 1 as Reset on Match
	//BIT 0 MR1I Interrupt on MR1: an interrupt is generated when MR0 matches the value in the TC.
	T0MCR |= (1<<0) | (1<<1);
	/*******INTERRUPT********************************************/
	//BIT[1] 	MR1 	Interrupt Interrupt flag for match channel 1.
	T0IR |= (1<<0);
	//Add the ISR Function with VICVect Address Table
	VICVectAddr0 = (unsigned) TIMER1;
	//VICVect Interrupt control
	VICVectCntl0 = 0x20 | 4;
	//Enable VIC interrupt table
	VICIntEnable |= (1<<4);
	//Clear Timer Control Reg and Enable Timer //T0TCR = 0x00;
	T0TCR |= (1<<0);
}

