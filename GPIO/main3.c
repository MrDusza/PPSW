#include <LPC21xx.H>
int main ()
{
	while(1)
	{
		IO1DIR = 0x8000;
		
		if(IO1SET == 0x8000)
			IO1SET = 0xFFFF7FFF;
		else
			IO1SET = 0x8000;
	}
}	
