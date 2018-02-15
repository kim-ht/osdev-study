#include "./screen.h"
#include "./keyboard.h"
#include "../cpu/low_kernel.h"
#include "../cpu/isr.h"
#include "../kernel/kernel.h"
#include "../kernel/util.h"
#include "../libc/function.h"
#include "../libc/string.h"

#define MAX_SCANCODE 58
#define SCANCODE_BACKSPACE 0x0e
#define SCANCODE_ENTER 0x1c

static char key_buffer[256];

const char *sc_name[] = { "ERROR", "Esc", "1", "2", "3", "4", "5", "6", 
    "7", "8", "9", "0", "-", "=", "Backspace", "Tab", "Q", "W", "E", 
        "R", "T", "Y", "U", "I", "O", "P", "[", "]", "Enter", "Lctrl", 
        "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'", "`", 
        "LShift", "\\", "Z", "X", "C", "V", "B", "N", "M", ",", ".", 
        "/", "RShift", "Keypad *", "LAlt", "Spacebar"};

const char sc_ascii[] = { '?', '?', '1', '2', '3', '4', '5', '6',     
    '7', '8', '9', '0', '-', '=', '?', '?', 'Q', 'W', 'E', 'R', 'T', 'Y', 
        'U', 'I', 'O', 'P', '[', ']', '?', '?', 'A', 'S', 'D', 'F', 'G', 
        'H', 'J', 'K', 'L', ';', '\'', '`', '?', '\\', 'Z', 'X', 'C', 'V', 
        'B', 'N', 'M', ',', '.', '/', '?', '?', '?', ' '};

void keyboard_callback(registers_t r) {
    u8 scancode;
    char letter;
    char str[2];

    scancode = port_byte_in(0x60);
    if ( scancode >= MAX_SCANCODE ) {
        return;
    }
    if ( scancode == SCANCODE_BACKSPACE ) {
        print_backspace();
        backspace(key_buffer);
    } else if ( scancode == SCANCODE_ENTER ) {
        print("\n");
        user_input(key_buffer);
        /* a kind of reset key_buffer */
        key_buffer[0] = 0x00;
    } else {
        letter = sc_ascii[(int)scancode];
        str[0] = letter;
        str[1] = 0x00;
        append(key_buffer, letter);
        print(str);
    }
    UNUSED(r);
}

void init_keyboard() {
    /* IRQ1 is reserved for keyboard device. */
    registers_interrupt_handler(IRQ1, keyboard_callback);
}
