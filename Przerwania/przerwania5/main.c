#include "timer_interrupts.h"
#include "led.h"
#include "keyboard.h"

void Automat()
{	
	enum LedState{STOP, TURN_RIGHT, TURN_LEFT, CHANGE_TURN_LEFT,};
	static enum LedState eLedState = STOP;

	static unsigned char ucStepCounter;

	switch(eLedState)
	{
		case TURN_RIGHT:
		
			if(eKeyboardRead() == BUTTON_1)
			{
				eLedState = STOP;
			}
			
			else if(eKeyboardRead() == BUTTON_3)
			{
				eLedState = CHANGE_TURN_LEFT;
			}
			
			else
			{
				LedStepRight();
			}
			break;
			
		case TURN_LEFT:
		
			if(eKeyboardRead() == BUTTON_1)
			{
				eLedState = STOP;
			}
	
			else
			{
				LedStepLeft();
			}
			break;
			
		case STOP:
		
			if(eKeyboardRead() == BUTTON_2)
			{
				eLedState = TURN_RIGHT;
			}
			else if(eKeyboardRead() == BUTTON_0)
			{
				eLedState = TURN_LEFT;
			}
			break;	
			
		case CHANGE_TURN_LEFT:
		
			if(ucStepCounter > 6)
			{
				ucStepCounter = 0;
				eLedState = TURN_LEFT;
			}
			
			else
			{
				ucStepCounter++;
				
				if(ucStepCounter%2 == 0)
				{
					LedOn(0);
				}
				
				else
				{
					LedOn(4);
				}
			}
			break;		
	}
}

int main (){
	unsigned int iMainLoopCtr;
	
	LedInit();
	KeyboardInit();
	
	Timer1Interrupts_Init(20000,&Automat);

	while(1){
	 	iMainLoopCtr++;	
		iMainLoopCtr++;	
		iMainLoopCtr++;	
		iMainLoopCtr++;
	}
}
