/*
 * ADC.h
 *
 * Created: 15/07/2023 06:30:42 م
 *  Author: Alaa Mohamed
 */ 


#ifndef ADC_H_
#define ADC_H_

#define MyADMUX *(volatile unsigned char*) 0x27
#define MyADCSRA *(volatile unsigned char*) 0x26
#define MyADCL *(volatile unsigned char*) 0x24
#define MyADCH *(volatile unsigned char*) 0x25
#define MySFIOR *(volatile unsigned char*) 0x50
#define MyADTS0 5		
#define MyADTS1 6
#define MyADTS2 7
#define MyMUX0 0
#define MyMUX1 1
#define MyMUX2 2
#define MyMUX3 3
#define MyMUX4 4
#define MyADLAR 5
#define MyREFS0 6
#define MyREFS1 7
#define MyADPS0 0
#define MyADPS1 1
#define MyADPS2 2
#define MyADIE 3
#define MyADIF 4
#define MyADATE 5
#define MyADSC 6
#define MyADEN 7

void ADC_Initialize();
unsigned short ADC_read();

#endif /* ADC_H_ */