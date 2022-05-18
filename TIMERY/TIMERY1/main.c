#include "led.h"
#include "keyboard.h"
#include "timer.h"

int main()
{
	InitTimer0();
	LedInit();
	
	while(1)
	{
	LedStepRight();
	WaitOnTimer0(250000);
	}	
}
