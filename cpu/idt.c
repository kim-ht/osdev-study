#include "./idt.h"
#include "./types.h"

/* set_idt_gate - sets nth index's ISR to given handler address.
 *
 * @n - the entry of ISR
 * @handler - the address of handler
 */
void set_idt_gate(int n, u32 handler) {
    idt[n].low_offset = low_16(handler);
    idt[n].seg_sel = KERNEL_CS;
    idt[n].zero = 0x00;
    /* flags are set to P=1 | DPL=00 | 0 D=1(for 32 bits size) 1 1 0 */
    idt[n].flags = 0b10001110;
    idt[n].high_offset = high_16(handler);
}

/* set_idt - performs lidt instruction.
 */
void set_idt() {
    idtr.base = (u32)(&idt);
    idtr.limit = IDT_ENTRIES * sizeof(idt_gate_t) - 1;
    __asm__ __volatile__(
        "lidtl (%0)"
        : // no output
        : "r" (&idtr) // an input exists, pointer to IDTR.
    );
}
