#pragma once

int input;
int output;

struct pinAndPort {
    int pin;
    int port;
};

struct pinAndPort pin_parse(int pin) {};
void pin_portMode(int port, int mode) {};
void pin_output(int pin, int val) {};
int  pin_compare(int pin, int requiredValue) {};
void pin_mode() {};