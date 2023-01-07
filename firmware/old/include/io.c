#include <avr/io.h>
#include "io.h"

int input = 0x02;
int output = 0x03;

struct pinAndPort {
    int pin = 0x00;
    int port = 0x03;
};

struct pinAndPort pin_parse(int pin) {
    struct pinAndPort a;

    if(pin < 0x07 || pin == 0x07) {
        a.pin = pin;
        a.port = 0x00;

        return a;
    }

    if(pin > 0x07 && (pin == 0x0e || pin < 0x0e)) {
        a.pin = pin - 7;
        a.port = 0x01;

        return a;
    }

    if(pin > 0x0e && (pin == 0x15 || pin < 0x15)) {
        a.pin = pin - (7 * 2);
        a.port = 0x02;

        return a;
    }

    a.pin = 0x00;
    a.port = 0x03;

    return a;
};


void pin_portMode(int port, int mode) {
    switch(port) {
        case 0x00: //port B 8 pins
            if(mode == input) {
                DDRB = 0b11111111;
            } else {
                DDRB = 0b00000000;
            }

            return;
        
        case 0x01: // port C 7 pins
            if(mode == input) {
                DDRC = 0b1111111;
            } else {
                DDRC = 0b0000000;
            }

            return;

        case 0x02: // port D 8 pins
            if(mode == input) {
                DDRD = 0b1111111;
            } else {
                DDRD = 0b0000000;
            }

            return;
    }
};

void pin_output(int pin, int val) {};
int  pin_compare(int pin, int requiredValue) {};
void pin_mode() {};