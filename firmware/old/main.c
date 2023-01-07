#ifndef F_CPU
#define F_CPU 16000000UL;
#endif

#include <avr/io.h>
#include <util/delay.h>

#include "include/io.h"
#include "include/led.h"


void bios_painc() {
    DDRB |= (1 << PB0);
    DDRB |= (1 << PB1);
    DDRB |= (1 << PB2);

    while(0x01) {
        PORTB = 0b00000001;
        _delay_ms(255);
        PORTB = 0b00000111;
        _delay_ms(255);
    }
};

int main() {
    pin_portMode(0x00, output);
    pin_portMode(0x01, output);
    pin_portMode(0x02, output);

    led_setColor(0x02);
};