#define F_CPU 1200000
#include <avr/io.h>
#include <util/delay.h>

int state = 0; //0 off, 1 on, 2 waiting

int main(void) {
	DDRB = 0b00001010; //set data direction
	PORTB = 0x00; //outputs to 0, pull ups down

	//do this for the eternity
	while(1) {

		PORTB = 0b00001000;
        _delay_ms(1000);
        PORTB = 0b00000000;
        _delay_ms(1000);

	}
}
