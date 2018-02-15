#!/usr/bin/python

form = '''isr%d:
    cli
    push 0
    push %d
    jmp isr_common_stub'''
form = 'print("this is hell world %s\\n");'
form = '        "int $%d  \\n\\t"'
form = 'extern void irq%d(void);'

for i in range(0, 16):
    print form % (i)
