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
	
	IO1CLR = IO1CLR | LED1_bm;
	IO1CLR = IO1CLR | LED2_bm;
	IO1CLR = IO1CLR | LED3_bm;
	IO1SET = IO1SET | LED0_bm;
}

int main ()
{
	IO1DIR = IO1DIR | LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	
	while(1)
	{ 
		LedInit();
		delay(250);
		IO1SET = IO1SET | LED1_bm;	
		IO1CLR = IO1CLR | LED0_bm;
		delay(250);
		IO1SET = IO1SET | LED2_bm;	
		IO1CLR = IO1CLR | LED1_bm;
		delay(250);
		IO1SET = IO1SET | LED3_bm;	
		IO1CLR = IO1CLR | LED2_bm;
		delay(250);
			
	}
}	
