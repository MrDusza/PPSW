#include <LPC21xx.H>
#include "timer_interrupts.h"
#include "led.h"
#include "keyboard.h"

#define DETECTOR_bm (1<<10)

void DetectorInit()
{
	IO0DIR &= ~DETECTOR_bm;
}

enum State {ACTIVE, INACTIVE};

enum State eReadDetector()
{
	if((IO0PIN&DETECTOR_bm) == 0)
	{
		return ACTIVE;
	}
	
	else
	{
		return INACTIVE;
	}
}

void Automat()
{	
	enum LedState{STOP, TURN_RIGHT, TURN_LEFT, CHANGE_TURN_LEFT, CALLIB};
	static enum LedState eLedState = CALLIB;

	static unsigned char ucStepCounter;

	switch(eLedState)
	{
		case CALLIB:
			
		if(eReadDetector() == ACTIVE)
		{
			eLedState = STOP;
		}
		
		else
		{
			LedStepLeft();
		}
		break;
		
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
	DetectorInit();
	
	Timer1Interrupts_Init(20000,&Automat);

	while(1){
	 	iMainLoopCtr++;
	}
}
