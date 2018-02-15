#!/usr/bin/python

form = '''isr%d:
    cli
    push 0
    push %d
    jmp isr_common_stub'''
form = 'print("this is hell world %s\\n");'
form = '        "int $%d  \\n\\t"'
form = 'set_idt_gate(%s, (u32)irq%d);'

isr = 0x20
irq = 0
while ( irq < 0x10 ):
    print form % (hex(isr), irq)
    isr += 1
    irq += 1
