/*
 * TIMER.c
 *
 * Created: 04/08/2023 03:45:12 م
 *  Author: Alaa Mohamed
 */ 

#include "TIMER.h"
#include "MACROS.h"
#include "DIO_Driver.h"
#include "INTERRUPT_CONFIG.h"

#define PRESCALAR_TIMER0 1024
#define PRESCALAR_TIMER1 1
#define PRESCALAR_TIMER2 128

void TIMER0_OVERFLOWInitializeInterrupt()
{
	/*Configuring timer clock*/
	if (PRESCALAR_TIMER0 == 1)
	{
		SET_BIT(MyTCCR0,MyCS00); 
	}
	else if (PRESCALAR_TIMER0 == 8)
	{
		SET_BIT(MyTCCR0,MyCS01);
	} 	
	else if (PRESCALAR_TIMER0 == 64)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if(PRESCALAR_TIMER0 == 256)
	{
		SET_BIT(MyTCCR0,MyCS02);
	}
	else if (PRESCALAR_TIMER0 == 1024)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS02);
	}
	/*Enable Interrupt*/
	SET_BIT(MySREG,7);
	SET_BIT(MyTIMSK,MyTOIE0);
}

void TIMER0_PHASECORRECTClearUpcount()
{
	/*Select phase correct PWM mode*/
	SET_BIT(MyTCCR0,MyWGM00);
	/*Configuring timer clock*/
	if (PRESCALAR_TIMER0 == 1)
	{
		SET_BIT(MyTCCR0,MyCS00);
	}
	else if (PRESCALAR_TIMER0 == 8)
	{
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if (PRESCALAR_TIMER0 == 64)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if(PRESCALAR_TIMER0 == 256)
	{
		SET_BIT(MyTCCR0,MyCS02);
	}
	else if (PRESCALAR_TIMER0 == 1024)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS02);
	}
	/*Load a value in OCR0 Register*/
	MyOCR0 = 64;
	/* Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting*/
	SET_BIT(MyTCCR0,MyCOM01);
}

void TIMER0_PHASECORRECTClearDowncount()
{
	/*Select phase correct PWM mode*/
	SET_BIT(MyTCCR0,MyWGM00);
	/*Configuring timer clock*/
	if (PRESCALAR_TIMER0 == 1)
	{
		SET_BIT(MyTCCR0,MyCS00);
	}
	else if (PRESCALAR_TIMER0 == 8)
	{
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if (PRESCALAR_TIMER0 == 64)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if(PRESCALAR_TIMER0 == 256)
	{
		SET_BIT(MyTCCR0,MyCS02);
	}
	else if (PRESCALAR_TIMER0 == 1024)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS02);
	}
	/*Load a value in OCR0 Register*/
	MyOCR0 = 64;
	/* Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting*/
	SET_BIT(MyTCCR0,MyCOM00);
	SET_BIT(MyTCCR0,MyCOM01);
}
void TIMER0_FASTPWMNonInverting(unsigned char on_percentage)
{
	/*Setting OC0 pin as output pin*/
	SET_BIT(MyDDRB,OC0);
	/*Selecting fast PWM mode*/
	SET_BIT(MyTCCR0,MyWGM00);
	SET_BIT(MyTCCR0,MyWGM01);
	/*Configuring timer clock*/
	if (PRESCALAR_TIMER0 == 1)
	{
		SET_BIT(MyTCCR0,MyCS00);
	}
	else if (PRESCALAR_TIMER0 == 8)
	{
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if (PRESCALAR_TIMER0 == 64)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if(PRESCALAR_TIMER0 == 256)
	{
		SET_BIT(MyTCCR0,MyCS02);
	}
	else if (PRESCALAR_TIMER0 == 1024)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS02);
	}
	/*Load a value in OCR register*/
	if (on_percentage == 0)
	{
		MyOCR0 = 0;
	}
	else if (on_percentage == 25)
	{
		MyOCR0 = 63;
	}
	else if (on_percentage == 50)
	{
		MyOCR0 = 127;
	}
	else if (on_percentage == 75)
	{
		MyOCR0 = 191;
	}
	else if (on_percentage == 100)
	{
		MyOCR0 = 255;
	}
	/*Clear OC0 on compare match (Non-inverting mode)*/
	SET_BIT(MyTCCR0,MyCOM01);
}
void TIMER0_FASTPWMInverting()
{
	/*Setting OC0 pin as output pin*/
	SET_BIT(MyDDRB,OC0);
	/*Selecting fast PWM mode*/
	SET_BIT(MyTCCR0,MyWGM00);
	SET_BIT(MyTCCR0,MyWGM01);
	/*Configuring timer clock*/
	if (PRESCALAR_TIMER0 == 1)
	{
		SET_BIT(MyTCCR0,MyCS00);
	}
	else if (PRESCALAR_TIMER0 == 8)
	{
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if (PRESCALAR_TIMER0 == 64)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if(PRESCALAR_TIMER0 == 256)
	{
		SET_BIT(MyTCCR0,MyCS02);
	}
	else if (PRESCALAR_TIMER0 == 1024)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS02);
	}
	/*Load a value in OCR register*/
	MyOCR0 = 64;
	/*Set OC0 on compare match (Inverting mode)*/
	SET_BIT(MyTCCR0,MyCOM00);
	SET_BIT(MyTCCR0,MyCOM01);
}
void TIMER0_CTCInitializeInterrupt()
{
	/*Selecting CTC mode*/
	SET_BIT(MyTCCR0,MyWGM01);
	/*Configuring timer clock*/
	if (PRESCALAR_TIMER0 == 1)
	{
		SET_BIT(MyTCCR0,MyCS00);
	}
	else if (PRESCALAR_TIMER0 == 8)
	{
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if (PRESCALAR_TIMER0 == 64)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if(PRESCALAR_TIMER0 == 256)
	{
		SET_BIT(MyTCCR0,MyCS02);
	}
	else if (PRESCALAR_TIMER0 == 1024)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS02);
	}
	/*Load a value into OCR0 register*/
	MyOCR0 = 80;
	/*Enable Interrupt*/
	SET_BIT(MySREG,7);
	SET_BIT(MyTIMSK,MyOCIE0);
}
void TIMER0_CTCGenerateWave()
{
	/*Setting OC0 pin as output pin*/
	SET_BIT(MyDDRB,OC0);
	/*Selecting CTC mode*/
	SET_BIT(MyTCCR0,MyWGM01);
	/*Configuring timer clock*/
	if (PRESCALAR_TIMER0 == 1)
	{
		SET_BIT(MyTCCR0,MyCS00);
	}
	else if (PRESCALAR_TIMER0 == 8)
	{
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if (PRESCALAR_TIMER0 == 64)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if(PRESCALAR_TIMER0 == 256)
	{
		SET_BIT(MyTCCR0,MyCS02);
	}
	else if (PRESCALAR_TIMER0 == 1024)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS02);
	}
	/*Load a value into OCR0 register*/
	MyOCR0 = 38;
	/*Toggle OC0 on Compare Match*/
	SET_BIT(MyTCCR0,MyCOM00);
}

void TIMER2_OVERFLOWInitializeInterrupt()
{
	/*Configuring timer clock*/
	if (PRESCALAR_TIMER2 == 1)
	{
		SET_BIT(MyTCCR0,MyCS20);
	}
	else if (PRESCALAR_TIMER2 == 8)
	{
		SET_BIT(MyTCCR0,MyCS21);
	}
	else if (PRESCALAR_TIMER2 == 32)
	{
		SET_BIT(MyTCCR0,MyCS20);
		SET_BIT(MyTCCR0,MyCS21);
	}
	else if (PRESCALAR_TIMER2 == 64)
	{
		SET_BIT(MyTCCR0,MyCS22);
	}
	else if(PRESCALAR_TIMER2 == 128)
	{
		SET_BIT(MyTCCR0,MyCS20);
		SET_BIT(MyTCCR0,MyCS22);
	}
	else if(PRESCALAR_TIMER2 == 256)
	{
		SET_BIT(MyTCCR0,MyCS21);
		SET_BIT(MyTCCR0,MyCS22);
	}
	else if (PRESCALAR_TIMER2 == 1024)
	{
		SET_BIT(MyTCCR0,MyCS20);
		SET_BIT(MyTCCR0,MyCS21);
		SET_BIT(MyTCCR0,MyCS22);
	}
	/*Select external clock for Timer/Counter2*/
	SET_BIT(MyASSR,MyAS2);
	/*Enable Interrupt*/
	SET_BIT(MySREG,7);
	SET_BIT(MyTIMSK,MyTOIE2);
}

void TIMER2_FASTPWMNonInverting(unsigned char on_percentage)
{
	/*Setting OC2 pin as output pin*/
	SET_BIT(MyDDRD,OC2);
	/*Selecting fast PWM mode*/
	SET_BIT(MyTCCR2,MyWGM20);
	SET_BIT(MyTCCR2,MyWGM21);
	/*Configuring timer clock, prescalar = 1024*/
	SET_BIT(MyTCCR2,MyCS20);
	SET_BIT(MyTCCR2,MyCS21);
	SET_BIT(MyTCCR2,MyCS22);
	/*Load a value in OCR register*/
	if (on_percentage == 0)
	{
		MyOCR2 = 0;
	}
	else if (on_percentage == 25)
	{
		MyOCR2 = 63;
	}
	else if (on_percentage == 50)
	{
		MyOCR2 = 127;
	}
	else if (on_percentage == 75)
	{
		MyOCR2 = 191;
	}
	else if (on_percentage == 100)
	{
		MyOCR2 = 255;
	}
	/*Clear OC2 on compare match (Non-inverting mode)*/
	SET_BIT(MyTCCR2,MyCOM21);
}

void TIMER1_OVERFLOWInitializeInterrupt()
{
	/*Configuring timer clock*/
	if (PRESCALAR_TIMER1 == 1)
	{
		SET_BIT(MyTCCR1B,MyCS10);
	}
	else if (PRESCALAR_TIMER1 == 8)
	{
		SET_BIT(MyTCCR1B,MyCS11);
	}
	else if (PRESCALAR_TIMER1 == 64)
	{
		SET_BIT(MyTCCR1B,MyCS10);
		SET_BIT(MyTCCR1B,MyCS11);
	}
	else if(PRESCALAR_TIMER1 == 256)
	{
		SET_BIT(MyTCCR1B,MyCS12);
	}
	else if (PRESCALAR_TIMER1 == 1024)
	{
		SET_BIT(MyTCCR1B,MyCS10);
		SET_BIT(MyTCCR1B,MyCS12);
	}
	/*Enable Interrupt*/
	SET_BIT(MySREG,7);
	SET_BIT(MyTIMSK,MyTOIE1);
}

void TIMER1_FASTPWMWave(double time_ms)
{
	/*set OC1A Pin as output*/
	SET_BIT(MyDDRD,OC1A);
	/*Configuring timer clock, prescalar = 8*/
	SET_BIT(MyTCCR1B,MyCS11);
	/*Select Fast PWM mode with ICR1 as top value*/
	SET_BIT(MyTCCR1A,MyWGM11);
	SET_BIT(MyTCCR1B,MyWGM12);
	SET_BIT(MyTCCR1B,MyWGM13);
	/*load a value in OCR1A and ICR1*/
	MyOCR1A = time_ms*1000;
	MyICR1 = 19999;
	/*clear OC1A at compare match, set at bottom*/
	SET_BIT(MyTCCR1A,MyCOM1A1);
}