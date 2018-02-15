#!/usr/bin/python

form = 'extern void isr%d(void);'

for i in range(32):
    print form % (i)
