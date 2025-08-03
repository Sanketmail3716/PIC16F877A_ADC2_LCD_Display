/*
 * File:   8 BIT LCD.c
 * Author: pallavi
 *
 * Created on June 13, 2023, 4:44 PM
 */
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection

#include <xc.h>
#include<PIC16F877A.h>
#define _XTAL_FREQ 20000000
#define en RC1
#define rs RC0
#define lcd_port PORTD
#define adc RA1

void LCD_Command(unsigned char cmd);
void LCD_Init(void);
void LCD_Char(unsigned char char_data);
void LCD_string(unsigned char *dat);
void display(unsigned int adc_value);

void main(void)
{
    unsigned int adc_value;
    TRISC1=0;//EN   configured as output
    TRISC0=0;//RS   configured as output
    TRISD=0x00;//LCD_PORT PORTD   configured as output
    
    TRISA1=1;   //configured as input
    ADCON0=0x84;     //connected to pot
    ADCON1=0x8D;
    
    LCD_Init();
    LCD_Command(0x80);
    LCD_string("ADC VALUE= ");
    while(1)
    {
        GO_nDONE=1;  //start A/D Conversion
        while(GO_nDONE==1);//check condition Go_done=1
        adc_value=((ADRESH<<8)|ADRESL);
        display(adc_value);
        //adc=((ADRESH>>6)|(ADRESH<<2));  
    }
}

void LCD_Init()
{
    __delay_ms(20);
    LCD_Command(0x38);
    LCD_Command(0x0C);
    LCD_Command(0x06);
    LCD_Command(0x01);

}
	
void LCD_string(unsigned char *dat)
{
    while(*dat!='\0')
    {
        LCD_Char(*dat);
        dat++;
    }
}
 
void LCD_Command(unsigned char cmd)
	{
		lcd_port=cmd;
		rs=0;
		en=1;
		__delay_ms(20);
		en=0;
		__delay_ms(20);
	}
	
void LCD_Char(unsigned char char_data)
{
    lcd_port=char_data;
    rs=1;
    en=1;
    __delay_ms(20);
    en=0;
    __delay_ms(20);
}
 
void display(unsigned int adc_value)
{		
	   LCD_Command(0x8b);
       LCD_Char((adc_value/1000)+'0');
	   LCD_Char(((adc_value/100)%10)+'0');
	   LCD_Char((adc_value/10)%10+'0');
	   LCD_Char((adc_value%10)+'0');
      
}
