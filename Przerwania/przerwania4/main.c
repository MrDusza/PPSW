#include "timer_interrupts.h"
#include "led.h"

int main (){
	unsigned int iMainLoopCtr;
	
	LedInit();
	
	Timer1Interrupts_Init(250000,&LedStepLeft);

	while(1){
	 	iMainLoopCtr++;
	}
}
