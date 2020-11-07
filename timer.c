 #include <avr/io.h>

#include "timer.h"

void timer_init() {
	//Set Timer0 to fast PWM as second lab
	TCCR0A |= (1 << WGM01) | (1 << WGM00) | (1 << COM0A1);

	TCCR0B |= (1 << CS01) | (1 << CS00); //Set prescaler to 64

	OCR0A = 255; //The value to count

	///////Down below is Timer2 CTC mode

	TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);

	TCCR2A |= (1 << WGM21);

	TCNT2 = 0; //Counts up

	TIMSK2 |= (1 << OCIE2A); // compair match A and enable interrups


}

