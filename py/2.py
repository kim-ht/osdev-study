#!/usr/bin/python

form = 'set_idt_gate(%d, (u32)isr%d());'

for i in range(32):
    print form % (i, i)
