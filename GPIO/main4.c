#include <LPC21xx.H>

void delay(int iMiliseconds)
{
	unsigned long int i;
	for(i = 0 ; i < 7500 * iMiliseconds ; i = i + 1)
	{}
}

int main ()
{
	unsigned int uiPinValue;
	
	uiPinValue = 0x10000;
	
	while(1)
	{
		IO1CLR = uiPinValue;
		delay(17);
		IO1SET = uiPinValue;		
	}
}	
