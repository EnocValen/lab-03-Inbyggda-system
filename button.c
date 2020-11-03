#include <avr/pgmspace.h>
#include <stdio.h>

#include "button.h"

char buttonPressed[] = { "pushed\r\n" };
char buttonNotPressed[] = { "released\r\n" };

uint8_t stateOfButton = 0;
uint8_t previousButtonState = 0;

void button_init() {
	DDRD &= ~(1 << PD2); //Input for PD2
}

void isButtonPressed() { 

	if (PIND & (1 << PD2)) { //Check if PIN2D is high
		stateOfButton = 1;
	}
	else if (!(PIND & (1 << PD2))) { //Check if PIN2D is low
		stateOfButton = 0;
	}

	if (stateOfButton == 0 & previousButtonState == 0) {
		printf_P(PSTR("%s"), buttonPressed);
	}
	else if (stateOfButton == 0 && previousButtonState == 1) {
		printf_P(PSTR("%s"), buttonNotPressed);
	}
	previousButtonState = stateOfButton;
}


