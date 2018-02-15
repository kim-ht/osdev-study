#!/usr/bin/python

form = '''isr%d:
    cli
    push 0
    push %d
    jmp isr_common_stub'''

for i in range(32):
    print form % (i, i)
    print ''
