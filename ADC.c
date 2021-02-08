#include "adc.h"
#include <pic16f887.h>

/* 
 * Author: mario
 * 
 * 
 * 
 * 
 */
//Iniciar Condiciones para generar la Interrupcion
#define _XTAL_FREQ 8000000



void conversion(int channel){
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.ADIE = 1;
    PIR1bits.ADIF = 0;
    ADCON0=0b01000000;
    ADCON1=0b00000000;
    ADCON0bits.CHS=channel;
    PIR1bits.ADIF = 0;
}
