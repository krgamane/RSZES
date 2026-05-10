#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

void ledInit();
void ledBlink(int16_t,int16_t);

int16_t main()
{
	ledInit();
	while(1){
		ledBlink(1000,1000);
	}

	return 0;
}

void ledInit(){
	DDRB |= 1 << 5;
}

void ledBlink(int16_t high_time, int16_t low_time){
	PORTB |= 1 << 5;
	_delay_ms(high_time);
	PORTB &= ~(1 << 5);
	_delay_ms(low_time);
}
