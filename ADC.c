/*
 * ADC.c
 *
 * Created: 15/07/2023 06:45:01 م
 *  Author: Alaa Mohamed
 */ 

#include "ADC.h"
#include "MACROS.h"

void ADC_Initialize()
{
	/*Adjust Vref to be internal 2.56V*/
	SET_BIT(MyADMUX,MyREFS0);
	SET_BIT(MyADMUX,MyREFS1);
	/*Enable ADC*/
	SET_BIT(MyADCSRA,MyADEN);
	/*Differential mode with gain = 0 dB (ADC0 = positive input and ADC1 = negative input)*/
	SET_BIT(MyADMUX,MyMUX4);
	/*Adjusting the clock to be 125KHz*/
	SET_BIT(MyADCSRA,MyADPS1);
	SET_BIT(MyADCSRA,MyADPS2);
}

unsigned short ADC_read()
{
	unsigned short ADC_Read_Value;
	SET_BIT(MyADCSRA,MyADSC); // start conversion 
	while(READ_BIT(MyADCSRA,MyADSC)==1); //stand still until conversion is complete
	/* 
	//Or do this
	while(READ_BIT(MyADCSRA,MyADIF)==0); //stand still until conversion is complete
	SET_BIT(MyADCSRA,MyADIF) //clear flag
	*/
	ADC_Read_Value = (MyADCL);
	ADC_Read_Value |= (MyADCH<<8);
	return ADC_Read_Value;
}