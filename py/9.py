#!/usr/bin/python

form = '''isr%d:
    cli
    push 0
    push %d
    jmp isr_common_stub'''
form = 'print("this is hell world %s\\n");'
form = '        "int $%d  \\n\\t"'
form = 'extern void irq%d(void);'
form = '''irq%d:
    cli
    push byte %d
    push byte %s
    jmp irq_common_stub'''

irq_handler_no = 0
irq_no = 0x20
for i in range(0, 16):
    print form % (irq_handler_no, irq_handler_no, hex(irq_no))
    print ''
    irq_handler_no += 1
    irq_no += 1
