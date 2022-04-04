#define F_CPU 1200000
#include <avr/io.h>
#include <util/delay.h>

int state = 0; //0 off, 1 on, 2 waiting

int main(void) {
	DDRB = 0b00001010; //set data direction
	PORTB = 0x00; //outputs to 0, pull ups down

	//do this for the eternity
	while(1) {

		//state off and button pressed
		if( (PINB & (1<<PB0)) && state == 0) {
			PORTB |= (1<<PB3); 
			_delay_ms(1000);
			state = 1;
		}

		//state on and button pressed and program running
		if((PINB & (1<<PB0)) && state == 1) {
			//signal the software
			PORTB |= (1<<PB1); 
			_delay_ms(400);
			PORTB &= ~(1<<PB1); 
		}

		//on and signaled
		if(state == 1 && (PINB & (1<<PB2))) {
			_delay_ms(1000);
			state = 0;
			PORTB &= ~(1<<PB3); 
		}

	}
}
