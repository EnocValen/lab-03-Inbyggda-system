#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"
#include "button.h"

volatile int globalADCValue;

ISR(TIMER2_COMPA_vect) {  
    ADCSRA |= (1 << ADSC);
    OCR0A = adc_val;
}

ISR(ADC_vect) {
    globalADCValue = readAdc();
}



int main (void) {

	LED_init();
	uart_init();
	timer_init();
    button_init();
    adc_init();


    while (1)
    {
    }
    return 0;
}


