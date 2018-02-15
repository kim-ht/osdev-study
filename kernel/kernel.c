#include "./util.h"
#include "../driver/screen.h"
#include "../cpu/idt.h"
#include "../cpu/isr.h"
#include "../cpu/timer.h"
#include "../libc/string.h"

int main(void) {
    clear_screen();
    print("+***+***+***+***+***+***+***+***+***+***+***+\n");
    print("| m y   f i r s t   s i m p l e   s h e l l |\n");
    print("+***+***+***+***+***+***+***+***+***+***+***+\n");
    isr_install();
    irq_install();
//    __asm__ __volatile__(
//        "int $2  \n\t"
//        "int $3  \n\t"
//        "int $4  \n\t"
//    );
    return 0;
}

void user_input(char *input) {
    if ( strcmp(input, "END") == 0 ) {
        print("stop.!\n");
        __asm__ __volatile__(
            "hlt"
        );
    }
    print("you typed: ");
    print(input);
    print("\n> ");
}
