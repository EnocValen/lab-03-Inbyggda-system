#include <avr/io.h>

#include <stdio.h>

#include "serial.h"

static FILE uart_stdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);

void uart_init(void) {
	UBRR0H = (unsigned char)(UBRR >> 8);
	UBRR0L = (unsigned char)(UBRR);
	UCSR0A = 0;
	UCSR0B = (1 << TXEN0 | 1 << RXEN0);
	UCSR0C = (1 << UCSZ01 | 1 << UCSZ00);

	stdout = &uart_stdout;
}

int uart_putchar(char chr, FILE *stream) {
	if (chr == '\n') {
		uart_putchar('\r', NULL);
	}
	while (!(UCSR0A & (1 << UDRE0)))
		;
	UDR0 = chr;
	return 0;
}

char uart_getchar(void) {
	while (!(UCSR0A & (1 << RXC0)))
		;
	return UDR0;
}

void adc_init() {
	ADMUX |= (1 << ADLAR); // vänsterjusterad 8bit data
	ADMUX |= (1 << REFS0); // referensspänning vcc
	ADCSRA |= (1 << ADEN); // Writing this bit to one enables the ADC. By writing it to zero, the ADC is turned off.
						   // Turning the ADC off while a conversion is in progress, will terminate this conversion.
	ADCSRA |= (1 << ADIE); //Writing this bit to one enables the interrupt
	ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | (0 << ADPS0); // this sets the prescaler to 8

}

int readAdc() {

	int adcValue;
	
	ADCSRA |= (1 << ADSC); // This will start each conversion on single mode
	
	adcValue = ADCH;

	return adcValue;
}

