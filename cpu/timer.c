#include "./timer.h"
#include "./isr.h"
#include "../kernel/util.h"
#include "./low_kernel.h"
#include "../driver/screen.h"

u32 tick = 0;

void timer_callback(registers_t r) {
//    ++tick;
//    char str[256];
//
//    int_to_ascii(tick, str);
//    print("tick: ");
//    print(str);
//    print("\n");
}

void init_timer(u32 freq) {
    u32 divisor;

    registers_interrupt_handler(IRQ0, timer_callback);
    divisor = 1193182 / freq;
    port_byte_out(TIMER_MODE_COMMAND, 0x36);
    /* sets low byte of divisor */
    port_byte_out(TIMER_CHANNEL0_DATA, (u8)divisor);
    /* sets high byte of divisor */
    port_byte_out(TIMER_CHANNEL0_DATA, (u8)(divisor >> 8));
}
