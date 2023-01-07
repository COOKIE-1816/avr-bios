#include "led.h"
#include "io.h"

void led_setColor(int color) {
    if(color == 0x00) {
        pin_output(0x00, 0x00);
        pin_output(0x00, 0x00);
        pin_output(0x00, 0x00);
    }

    if(color == 0x01) {
        pin_output(0x00, 0x01);
        pin_output(0x00, 0x00);
        pin_output(0x00, 0x00);
    }

    if(color == 0x02) {
        pin_output(0x00, 0x00);
        pin_output(0x00, 0x01);
        pin_output(0x00, 0x00);
    }
};
