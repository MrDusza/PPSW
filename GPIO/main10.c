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

int main ()
{
	IO1DIR = IO1DIR | LED3_bm;
	
	while(1)
	{ 
		IO1SET = IO1SET | LED3_bm;	
		delay(50);
		IO1CLR = IO1SET | LED3_bm;
		delay(50);		
	}
}	
