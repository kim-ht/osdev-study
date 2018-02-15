#ifndef _CPU_IDT_H_
#define _CPU_IDT_H_

#include "./types.h"

#define IDT_ENTRIES 0x100
#define KERNEL_CS 0x8 // 0x0 for null desc, 0x16 for data desc

typedef struct {
    u16 low_offset;
    u16 seg_sel;
    u8 zero;
    u8 flags; // P(1bits) | DPL(2 bits) | 0 D(1 bits) 1 1 0
    u16 high_offset;
} __attribute__((packed)) idt_gate_t;

typedef struct {
    u16 limit;
    u32 base;
} __attribute__((packed)) idtr_t;

idt_gate_t idt[IDT_ENTRIES];
idtr_t idtr;

void set_idt_gate(int n, u32 handler);
void set_idt();

#endif

