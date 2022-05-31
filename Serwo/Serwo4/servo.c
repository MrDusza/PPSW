#include <LPC21xx.H>
#include "led.h"
#include "timer_interrupts.h"
#include "servo.h"

#define DETECTOR_bm (1<<10)

enum ServoState {CALLIB, IDLE, IN_PROGRESS};

struct Servo
{
	enum ServoState eState;
	unsigned int uiCurrentPosition; 
	unsigned int uiDesiredPosition;
}; 

struct Servo sServo;

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
	switch(sServo.eState)
	{
		case CALLIB:
			
		if(eReadDetector() == ACTIVE)
		{
			sServo.eState = IDLE;
			sServo.uiCurrentPosition = 0;
			sServo.uiDesiredPosition = 0;
		}
		
		else
		{
			LedStepLeft();
		}
		break;
		
		case IDLE:
		
		if(sServo.uiCurrentPosition == sServo.uiDesiredPosition)
		{
			sServo.eState = IDLE;
		}
		
		else
		{
			sServo.eState = IN_PROGRESS;
		}
		break;
		
		case IN_PROGRESS:
		
		if(sServo.uiDesiredPosition > sServo.uiCurrentPosition)
		{
			sServo.uiCurrentPosition++;
			LedStepRight();
		}
		
		else if(sServo.uiDesiredPosition < sServo.uiCurrentPosition)
		{
			sServo.uiCurrentPosition--;
			LedStepLeft();
		}
		
		else
		{
			sServo.eState = IDLE;
		}
		break;
	}
}

void ServoInit(unsigned int uiServoFrequency)
{
	DetectorInit();
	sServo.eState = CALLIB;
	LedInit();
	Timer1Interrupts_Init(1000000 / uiServoFrequency, &Automat);
}

void ServoCallib(void)
{
	sServo.eState = CALLIB;
}

void ServoGoTo(unsigned int uiPosition)
{
	sServo.uiDesiredPosition = uiPosition;
}

