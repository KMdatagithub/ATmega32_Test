/*
 * dcMotor.c
 *
 * Created: 1/26/2020 10:28:05 AM
 *  Author: Khaled Magdy
 */ 
#include "dcMotor.h"

//---------------------------------------------------------------------
//----------------------[ DC Motor 1 Control ]-------------------------
//---------------------------------------------------------------------
void dcMotor1Enable(void)
{
	gpioPinDirection(M1EN_GPIO, M1EN_BIT, OUTPUT);
	gpioPinDirection(M1D1_GPIO, M1D1_BIT, OUTPUT);
	gpioPinDirection(M1D2_GPIO, M1D2_BIT, OUTPUT);
	gpioPinWrite(M1EN_GPIO, M1EN_BIT, HIGH);
	dcMotor1SetDCD(0, 0);
}
void dcMotor1Disable(void)
{
	gpioPinWrite(M1EN_GPIO, M1EN_BIT, LOW);
	timer2SoftPWM_start(M1EN_GPIO, M1EN_BIT, 0, 0);
}
void dcMotor1SetDCD(uint8_t u8_dutyCycle, uint8_t u8_direction)
{
	
	timer2SoftPWM_start(M1EN_GPIO, M1EN_BIT, u8_dutyCycle, 0);
	switch(u8_direction)
	{
		case 0:
		        gpioPinWrite(M1D1_GPIO, M1D1_BIT, HIGH);
				gpioPinWrite(M1D2_GPIO, M1D2_BIT, LOW);
				break;	
	    case 1:
				gpioPinWrite(M1D1_GPIO, M1D1_BIT, LOW);
				gpioPinWrite(M1D2_GPIO, M1D2_BIT, HIGH);
				break;
		default:
		        break;
	}
}
//---------------------------------------------------------------------
//----------------------[ DC Motor 2 Control ]-------------------------
//---------------------------------------------------------------------
void dcMotor2Enable(void)
{
	gpioPinDirection(M2EN_GPIO, M2EN_BIT, OUTPUT);
	gpioPinDirection(M2D1_GPIO, M2D1_BIT, OUTPUT);
	gpioPinDirection(M2D2_GPIO, M2D2_BIT, OUTPUT);
	gpioPinWrite(M2EN_GPIO, M2EN_BIT, HIGH);
	dcMotor2SetDCD(0, 0);
}
void dcMotor2Disable(void)
{
	gpioPinWrite(M2EN_GPIO, M2EN_BIT, LOW);
	timer2SoftPWM_start(M2EN_GPIO, M2EN_BIT, 0, 1);
}
void dcMotor2SetDCD(uint8_t u8_dutyCycle, uint8_t u8_direction)
{
	
	timer2SoftPWM_start(M2EN_GPIO, M2EN_BIT, u8_dutyCycle, 1);
	switch(u8_direction)
	{
		case 0:
		        gpioPinWrite(M2D1_GPIO, M2D1_BIT, HIGH);
				gpioPinWrite(M2D2_GPIO, M2D2_BIT, LOW);
				break;	
	    case 1:
				gpioPinWrite(M2D1_GPIO, M2D1_BIT, LOW);
				gpioPinWrite(M2D2_GPIO, M2D2_BIT, HIGH);
				break;
		default:
		        break;
	}
}
//---------------------------------------------------------------------
//----------------------[ Robotic Car Control ]------------------------
//---------------------------------------------------------------------
void MoveForward(uint8_t u8_dutyCycle)
{
	gpioPinWrite(M2D1_GPIO, M2D1_BIT, HIGH);
	gpioPinWrite(M2D2_GPIO, M2D2_BIT, LOW);
	gpioPinWrite(M1D1_GPIO, M1D1_BIT, HIGH);
	gpioPinWrite(M1D2_GPIO, M1D2_BIT, LOW);
	timer2SoftPWM_start(M1EN_GPIO, M1EN_BIT, u8_dutyCycle, 0);
	timer2SoftPWM_start(M2EN_GPIO, M2EN_BIT, u8_dutyCycle, 1);
}
void MoveBackward(uint8_t u8_dutyCycle)
{
	gpioPinWrite(M2D1_GPIO, M2D1_BIT, LOW);
	gpioPinWrite(M2D2_GPIO, M2D2_BIT, HIGH);
	gpioPinWrite(M1D1_GPIO, M1D1_BIT, LOW);
	gpioPinWrite(M1D2_GPIO, M1D2_BIT, HIGH);
	timer2SoftPWM_start(M1EN_GPIO, M1EN_BIT, u8_dutyCycle, 0);
	timer2SoftPWM_start(M2EN_GPIO, M2EN_BIT, u8_dutyCycle, 1);
}
void CWrotate(uint8_t u8_dutyCycle)
{
	gpioPinWrite(M2D1_GPIO, M2D1_BIT, HIGH);
	gpioPinWrite(M2D2_GPIO, M2D2_BIT, LOW);
	gpioPinWrite(M1D1_GPIO, M1D1_BIT, LOW);
	gpioPinWrite(M1D2_GPIO, M1D2_BIT, HIGH);
	timer2SoftPWM_start(M1EN_GPIO, M1EN_BIT, u8_dutyCycle, 0);
	timer2SoftPWM_start(M2EN_GPIO, M2EN_BIT, u8_dutyCycle, 1);
}
void CCWrotate(uint8_t u8_dutyCycle)
{
	gpioPinWrite(M2D1_GPIO, M2D1_BIT, LOW);
	gpioPinWrite(M2D2_GPIO, M2D2_BIT, HIGH);
	gpioPinWrite(M1D1_GPIO, M1D1_BIT, HIGH);
	gpioPinWrite(M1D2_GPIO, M1D2_BIT, LOW);
	timer2SoftPWM_start(M1EN_GPIO, M1EN_BIT, u8_dutyCycle, 0);
	timer2SoftPWM_start(M2EN_GPIO, M2EN_BIT, u8_dutyCycle, 1);
}
void carSTOP(void)
{
	dcMotor1Disable();
	dcMotor2Disable();
}