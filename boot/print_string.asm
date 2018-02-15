; print_string - prints string that is pointed by bx.
;
; @bx - the address of string that you wanna print on the screen.
[bits 16]
print_string:
    pusha
    mov ah, 0x0e ; intrrupt vector number in BIOS
loop_by_null:
    mov al, [bx]
    cmp al, 0x00
    je null_terminated
    int 0x10
    inc bx
    jmp loop_by_null
null_terminated:
    popa
    ret
