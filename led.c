#include <avr/io.h>
#include "led.h"


void LED_init() {
	DDRD |= (1 << 6); // This is because expansionport is 6
}



uint8_t simple_ramp() {

}

void TOGGLE_led() {
	PORTB ^= (1 << PD6);
}
