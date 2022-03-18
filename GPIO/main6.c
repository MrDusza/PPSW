#include <LPC21xx.H>


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
	unsigned int uiPinValue;
	
	IO1DIR = 0x10000;
	uiPinValue = 0x10000;
	
	while(1)
	{ 
		IO1SET = uiPinValue;	
		delay(1000);
		IO1CLR = uiPinValue;
		delay(1000);
			
	}
}	
