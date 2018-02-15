#!/usr/bin/python

form = '''isr%d:
    cli
    push 0
    push %d
    jmp isr_common_stub'''
form = 'print("this is hell world %s\\n");'

for i in range(32):
    print form % (str(i) * 8)
