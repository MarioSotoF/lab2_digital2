// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)



// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include "oscilador.h"

/*
 * File:   main.c
 * Author: Mario Soto
 *
 * Created on 6 de febrero de 2021, 07:30 PM
 */
void setup(void);
void InitTimer0(void);

#include <xc.h>

void main(void) {
    setup();
    
    while(1){
        
        
        
    
    
    }
    
    
    
    return;
}

void setup(void){
    
    initosc(7);
    OSCCONbits.OSTS = 0;
    OSCCONbits.HTS = 0;
    OSCCONbits.LTS = 0;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.RBIE = 1;
    INTCONbits.T0IE = 1;
    INTCONbits.INTE = 1;
    PIE1bits.ADIE = 1;
    INTCONbits.T0IF = 0; //Bandera de Timer 0
    INTCONbits.RBIF = 0; //Bandera de IOC
    PIR1bits.ADIF = 0; //Bandera del ADC
    IOCBbits.IOCB0 = 1;
    IOCBbits.IOCB1 = 1;
    IOCBbits.IOCB2 = 1;
    ANSEL = 0;
    ANSELH = 0b00000001;
    TRISA = 0;
    PORTA = 0;
    TRISB = 0b00000111;
    PORTB = 0;
    TRISC = 0;
    PORTC = 0;
    TRISD = 0;
    PORTD = 0;
    TRISE = 0;
    PORTE = 0;


}

void InitTimer0(){
    OPTION_REG  = 0x87;
    TMR0        = 59;
    INTCON      = 0xA0;
    
}


void __interrupt() isr(void) {
    if (INTCONbits.RBIF == 1) {
        if (PORTBbits.RB0 == 0) { 
            PORTC = PORTC - 1;
            INTCONbits.RBIF = 0;
        } 
        else if (PORTBbits.RB1 == 0) {
            PORTC = PORTC + 1;
            INTCONbits.RBIF = 0;
        }
         
    }
}
