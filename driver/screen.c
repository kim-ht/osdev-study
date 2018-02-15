#include "./screen.h"
#include "../cpu/low_kernel.h"
#include "../kernel/util.h"

void print_char(char character, int col, int row, char attribute_byte);
int get_screen_offset(int col, int row);
int get_cursor();
void set_cursor(int offset);
int handle_scrolling(int cursor_offset);

void print(char *msg) {
    print_at(msg, -1, -1);
}
void print_at(char *msg, int col, int row) {
    if ( col >= 0 && row >= 0 ) {
        set_cursor(get_screen_offset(col, row));
    }
    while ( *msg ) {
        print_char(*msg, col, row, 0);
        ++msg;
    }
}

void print_char(char character, int col, int row, char attribute_byte) {
    unsigned char *vidmem = (unsigned char *)VIDEO_ADDRESS;
    int offset;
    int cur_row;

    if ( !attribute_byte ) {
        attribute_byte = WHITE_ON_BLACK;
    }
    if ( col >= 0 && row >= 0 ) {
        offset = get_screen_offset(col, row);
    } else {
        offset = get_cursor();
    }
    if ( character == '\n' ) {
        cur_row = offset / (MAX_COLS * 2);
        offset = get_screen_offset(0, cur_row + 1); // 79 is MAX_COLS - 1
    /* if the given character is backspace */
    } else if ( character == 0x08 ) {
        vidmem[offset] = 0x00;
        vidmem[offset + 1] = WHITE_ON_BLACK;
    } else {
        vidmem[offset] = character;
        vidmem[offset + 1] = attribute_byte;
        offset += 2;
    }
    offset = handle_scrolling(offset);
    set_cursor(offset);
}

int get_screen_offset(int col, int row) {
    return (row * MAX_COLS + col) * 2;
}

int get_cursor() {
    int offset;

    // 14 for high byte of the cursor's offset
    port_byte_out(REG_SCREEN_CTRL, 14);
    offset = port_byte_in(REG_SCREEN_DATA) << 8;
     // 15 for low byte of the cursor's offset
    port_byte_out(REG_SCREEN_CTRL, 15);
    offset |= port_byte_in(REG_SCREEN_DATA);
    return offset * 2; // * 2 for our indexing
}

void set_cursor(int offset) {
    offset /= 2;
    port_byte_out(REG_SCREEN_CTRL, 14); // high byte
    port_byte_out(REG_SCREEN_DATA, (unsigned char)(offset >> 8));
    port_byte_out(REG_SCREEN_CTRL, 15); // low byte
    port_byte_out(REG_SCREEN_DATA, (unsigned char)offset);
}

int handle_scrolling(int cursor_offset) {
    int i;
    unsigned char *ptr;

    if ( cursor_offset < MAX_ROWS * MAX_COLS * 2 ) {
        return cursor_offset;
    }
    memory_copy((char *)(VIDEO_ADDRESS + get_screen_offset(0, 1)),
                (char *)(VIDEO_ADDRESS + get_screen_offset(0, 0)),
                (MAX_ROWS - 1) * MAX_COLS * 2);
    ptr = (unsigned char *)(VIDEO_ADDRESS + get_screen_offset(0, 24));
    for ( i = 0; i < MAX_COLS; ++i ) {
        ptr[i * 2] = 0x00;
        ptr[i * 2 + 1] = WHITE_ON_BLACK;
    }
    cursor_offset -= MAX_COLS * 2;
    return cursor_offset;
}

void clear_screen() {
    int i;
    unsigned char *vidmem;

    vidmem = (unsigned char *)VIDEO_ADDRESS;
    for ( i = 0; i < MAX_ROWS * MAX_COLS; ++i ) {
        vidmem[i * 2] = 0x00;
        vidmem[i * 2 + 1] = WHITE_ON_BLACK;
    }
    set_cursor(get_screen_offset(0, 0));
}

void print_backspace() {
    int offset;
    int row;
    int col;

    offset = get_cursor() - 2;
    row = offset / (MAX_COLS * 2);
    col = offset / 2 - (row * MAX_COLS);
    print_char(0x08, col, row, WHITE_ON_BLACK);
}

