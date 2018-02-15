#!/usr/bin/python

form = '''isr%d:
    cli
    push 0
    push %d
    jmp isr_common_stub'''
form = 'print("this is hell world %s\\n");'
form = '        "int $%d  \\n\\t"'

for i in range(2, 32):
    print form % (i)
