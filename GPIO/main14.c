#include <LPC21xx.H>

#define LED0_bm (1 << 16)
#define LED1_bm (1 << 17)
#define LED2_bm (1 << 18)
#define LED3_bm (1 << 19)

void delay(unsigned long int uiMiliseconds)
{
	unsigned long int i;
	for(i = 0 ; i < uiMiliseconds ; i++)
	{
		unsigned long int i;
		for(i = 0 ; i < 7500 ; i++){}
	}
}

void LedInit()
{
	IO1DIR = IO1DIR | LED0_bm | LED1_bm | LED2_bm | LED3_bm;
}

void LedOn(unsigned char ucLedIndeks)
	{
		IO1CLR = IO1CLR | LED0_bm;
		IO1CLR = IO1CLR | LED1_bm;
		IO1CLR = IO1CLR | LED2_bm;
		IO1CLR = IO1CLR | LED3_bm;
		
		if(ucLedIndeks == 0)
		{
			IO1SET = IO1SET | LED0_bm;
		}
		else if(ucLedIndeks == 1)
		{	
			IO1SET = IO1SET | LED1_bm;		
		}
		else if(ucLedIndeks == 2)
		{		
			IO1SET = IO1SET | LED2_bm;	
		}
		else if(ucLedIndeks == 3)
		{
			IO1SET = IO1SET | LED3_bm;	
		}
		else 
		{		
			IO1CLR = IO1CLR | LED0_bm;
			IO1CLR = IO1CLR | LED1_bm;
			IO1CLR = IO1CLR | LED2_bm;
			IO1CLR = IO1CLR | LED3_bm;
		}
	}
	
int main ()
{	
	while(1)
	{ 
		LedInit();
		LedOn(0);
		delay(250);
		LedOn(1);
		delay(250);
		LedOn(2);
		delay(250);
		LedOn(3);
		delay(250);
			
	}
}	
