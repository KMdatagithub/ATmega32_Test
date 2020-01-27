/*
 * ATmega32_Test.c
 *
 * Created: 1/17/2020 1:26:47 PM
 * Author : Khaled Magdy
 */ 
#include "registers.h"
#include "softwareDelay.h"
#include "gpio.h"
#include "led.h"
#include "pushButton.h"
#include "timers.h"
#include "dcMotor.h"
#include "sevenSeg.h"

int main(void)
{
	sevenSegInit(SEG_0);
	sevenSegInit(SEG_1);
	uint8_t counter = 0, c=0, digit0, digit1;
	while(1)
	{
		digit1 = counter/10;
		digit0 = counter%10;
		
		sevenSegWrite(SEG_0, digit0);
		sevenSegEnable(SEG_0);
		sevenSegDisable(SEG_1);
		softwareDelayMs(10);
		
		sevenSegWrite(SEG_1, digit1);
		sevenSegEnable(SEG_1);
		sevenSegDisable(SEG_0);
		softwareDelayMs(10);
		
		c++;
		if(c==50)   // Each 1 Second
		{
			c=0;
			counter++;
			if(counter==100)
			counter = 0;
		}
	}
}