/*
 * air_conditioner_and_heater.c
 *
 * Created: 13/08/2023 07:38:13 م
 *  Author: Alaa Mohamed
 */ 


#include "ADC.h"
#include "LCD.h"
#include "TIMER.h"

int main(void)
{
	LCD_Initialize();
	ADC_Initialize();
	LCD_SendString("Temperature=");
	unsigned short voltage,temperature;
	while(1)
	{
		voltage = ADC_read() * 2.5;
		if (voltage >= 1000) //temperature is positive
		{
			temperature = (voltage - 1000)/10;
			if (temperature < 10)
			{
				LCD_MoveCursor(1,13);
				LCD_SendCharacter(temperature+48);
				LCD_SendCharacter(0xDF);
				LCD_SendCharacter('C');
				LCD_SendCharacter(' ');
				LCD_MoveCursor(2,1);
				LCD_SendString("Heater level:1  ");
				TIMER2_FASTPWMNonInverting(25);
				TIMER0_FASTPWMNonInverting(0);
			}
			else if(temperature < 100)
			{
				LCD_MoveCursor(1,13);
				LCD_SendCharacter((temperature/10)+48);
				LCD_SendCharacter((temperature%10)+48);
				LCD_SendCharacter(0xDF);
				LCD_SendCharacter('C');
				LCD_SendCharacter(' ');
				if(temperature < 30)
				{
					LCD_MoveCursor(2,1);
					LCD_SendString("AC,Heater:off   ");
					TIMER0_FASTPWMNonInverting(0);
					TIMER2_FASTPWMNonInverting(0);
				}
				else if (temperature >= 30 && temperature < 35)
				{
					LCD_MoveCursor(2,1);
					LCD_SendString("AC is on,level 1");
					TIMER0_FASTPWMNonInverting(25);
					TIMER2_FASTPWMNonInverting(0);
				}
				else if (temperature >= 35 && temperature < 40)
				{
					LCD_MoveCursor(2,1);
					LCD_SendString("AC is on,level 2");
					TIMER0_FASTPWMNonInverting(50);
					TIMER2_FASTPWMNonInverting(0);
				}
				else if (temperature >= 40 && temperature < 45)
				{
					LCD_MoveCursor(2,1);
					LCD_SendString("AC is on,level 3");
					TIMER0_FASTPWMNonInverting(75);
					TIMER2_FASTPWMNonInverting(0);
				}
				else if(temperature >= 45)
				{
					LCD_MoveCursor(2,1);
					LCD_SendString("AC is on,level 4");
					TIMER0_FASTPWMNonInverting(100);
					TIMER2_FASTPWMNonInverting(0);
				}
			}
			else
			{
				LCD_MoveCursor(1,13);
				LCD_SendCharacter((temperature/100)+48);
				LCD_SendCharacter(((temperature/10)%10)+48);
				LCD_SendCharacter((temperature%10)+48);
				LCD_SendCharacter(0xDF);
				LCD_SendCharacter('C');
				LCD_MoveCursor(2,1);
				LCD_SendString("AC is on,level 4");
				TIMER0_FASTPWMNonInverting(100);
				TIMER2_FASTPWMNonInverting(0);
			}
		}
		else //temperature is negative
		{
			temperature = (1000 - voltage )/10;
			if (temperature < 10)
			{
				LCD_MoveCursor(1,13);
				LCD_SendCharacter('-');
				LCD_SendCharacter(temperature+48);
				LCD_SendCharacter(0xDF);
				LCD_SendCharacter('C');
				LCD_SendCharacter(' ');
				LCD_MoveCursor(2,1);
				LCD_SendString("Heater level:2  ");
				TIMER2_FASTPWMNonInverting(50);
				TIMER0_FASTPWMNonInverting(0);
			}
			else if(temperature < 100)
			{
				LCD_MoveCursor(1,13);
				LCD_SendCharacter('-');
				LCD_SendCharacter((temperature/10)+48);
				LCD_SendCharacter((temperature%10)+48);
				LCD_SendCharacter(0xDF);
				LCD_SendCharacter('C');
				LCD_SendCharacter(' ');
				if(temperature >= 10 && temperature < 15)
				{
					LCD_MoveCursor(2,1);
					LCD_SendString("Heater level:3  ");
					TIMER2_FASTPWMNonInverting(75);
					TIMER0_FASTPWMNonInverting(0);
				}
				else if (temperature >= 15)
				{
					LCD_MoveCursor(2,1);
					LCD_SendString("Heater level:4  ");
					TIMER2_FASTPWMNonInverting(100);
					TIMER0_FASTPWMNonInverting(0);
				}
			}
			else
			{
				LCD_MoveCursor(1,13);
				LCD_SendCharacter('-');
				LCD_SendCharacter((temperature/100)+48);
				LCD_SendCharacter(((temperature/10)%10)+48);
				LCD_SendCharacter((temperature%10)+48);
				LCD_SendCharacter(0xDF);
				LCD_SendCharacter('C');
				LCD_MoveCursor(2,1);
				LCD_SendString("Heater level:4  ");
				TIMER2_FASTPWMNonInverting(100);
				TIMER0_FASTPWMNonInverting(0);
			}
		}
	}
}