;
; several GDTs
;
gdt_start:
gdt_null:
    dd 0x00000000 ; all are set
    dd 0x00000000 ; with null
gdt_code:
    dw 0xffff ; segment limit 15:0
    dw 0x0000 ; base address 15:0
    db 0x00 ; base address 23:16
    db 10011010b ; P(=1), DPL(=00b), S(=1b), type(=1010b)
    db 11001111b ; G(=1b), D/B(=1b), L(=0b), AVL(=0b),
                 ; seg limit 19:16(=0xf)
    db 0x00 ; base 31:24
gdt_data:
    dw 0xffff ; segment limit 15:0
    dw 0x0000 ; base address 15:0
    db 0x00 ; base address 23:16
    db 10010010b ; P(=1), DPL(=00b), S(=1b), type(=0010b)
    db 11001111b ; G(=1b), D/B(=1b), L(=0b), AVL(=0b),
                 ; seg limit 19:16(=0xf)
    db 0x00 ; base 31:24
gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1 ; size of GDT
    dd gdt_start ; pointer to start of GDT

CODE_SEGMENT_OFFSET equ gdt_code - gdt_start
DATA_SEGMENT_OFFSET equ gdt_data - gdt_start
