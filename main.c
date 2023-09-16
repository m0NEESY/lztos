#include <stdint.h>

uint8_t* framebuffer = (uint8_t*)0xA0000;

void set_pixel(int x, int y, uint8_t color) {
    int offset = y * 320 + x;
    framebuffer[offset] = color;
}

void fill_screen(uint8_t color) {
    for (int y = 0; y < 200; y++) {
        for (int x = 0; x < 320; x++) {
            set_pixel(x, y, color);
        }
    }
}

void draw_circle(int x0, int y0, int radius, uint8_t color) {
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        set_pixel(x0 + x, y0 + y, color);
        set_pixel(x0 + y, y0 + x, color);
        set_pixel(x0 - y, y0 + x, color);
        set_pixel(x0 - x, y0 + y, color);
        set_pixel(x0 - x, y0 - y, color);
        set_pixel(x0 - y, y0 - x, color);
        set_pixel(x0 + y, y0 - x, color);
        set_pixel(x0 + x, y0 - y, color);

        if (err <= 0) {
            y += 1;
            err += 2 * y + 1;
        }

        if (err > 0) {
            x -= 1;
            err -= 2 * x + 1;
        }
    }
}

void kernel_main(){
    //draw_circle(160, 100, 50, (uint8_t)2);
    fill_screen((uint8_t)2);
    while (1) {}
}
