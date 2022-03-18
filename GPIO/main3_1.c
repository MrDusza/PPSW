#include <LPC21xx.H>
int main ()
{
	
	unsigned int uiPinValue;
	
	uiPinValue = 0x10000;
	
	while(1)
	{
		IO1CLR = uiPinValue;
		IO1SET = uiPinValue;		
	}
}	
