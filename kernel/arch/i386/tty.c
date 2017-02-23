#include <stdbool.h>    // no bools in C by default
#include <stddef.h> 
#include <stdint.h>
#include <string.h>

#include <kernel/tty.h>
#include "vga.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xb8000;

size_t tty_row;
size_t tty_col;
uint8_t tty_colour;
uint16_t* tty_buff;

void tty_init(void) {
    tty_row = 0;
    tty_col = 0;
    tty_colour = vga_cell_colour(VGA_COLOUR_LIGHT_GREY, VGA_COLOUR_BLACK);
    tty_buff = (uint16_t*) 0xB8000;

    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = (const size_t)tty_get_buff_index_from_xy(x, y);
            tty_buff[index] = vga_cell(' ', tty_colour);
        }
    }
}

size_t tty_get_buff_index_from_xy(const size_t x, const size_t y) {
    return y * VGA_WIDTH + x;
}

void tty_set_colour(uint8_t colour) {
    tty_colour = colour;
}

void tty_put_cell_at(char c, uint8_t colour, size_t x, size_t y) {
    const size_t index = tty_get_buff_index_from_xy(x, y);
    tty_buff[index] = vga_cell(c, colour);
}

void tty_scroll() {
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            if (y == VGA_HEIGHT - 1) {
                tty_put_cell_at(' ', tty_colour, x, y);
            } else {
                const size_t index_below = (const size_t)tty_get_buff_index_from_xy(x, y + 1);
                const uint16_t cell_below = tty_buff[index_below];
                const size_t index_here = (const size_t)tty_get_buff_index_from_xy(x, y);
                tty_buff[index_here] = cell_below;
            }
        }
    }
    
}

void tty_put_char(char c) {
    if (c != '\n') {
        tty_put_cell_at(c, tty_colour, tty_col, tty_row);
        if (++tty_col == VGA_WIDTH) {
            tty_col = 0;
            if (++tty_row == VGA_HEIGHT) {
                tty_scroll();
            }
        }
    } else {
        tty_col = 0;
        tty_row++;
    }
}

void tty_write(const char* data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        tty_put_char(data[i]);
    }
}

void tty_write_str(const char* data) {
    tty_write(data, strlen(data));
}

