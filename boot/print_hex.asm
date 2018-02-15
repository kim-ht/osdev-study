; print_hex - it prints given hex value as text to screen.
;
; @dx - the 2 byte hex value to print.
[bits 16]
print_hex:
    pusha
    call print_hex_one_byte
    mov dl, dh
    call print_hex_one_byte
    popa
    ret

; print_hex_one_byte - it prints one byte hex value to text to screen.
;                      this is used in print_hex.
;
; @dl - the 1 byte hex value to print.
[bits 16]
print_hex_one_byte:
    pusha

    mov al, dl
    and al, 0x0f
    mov bx, TEMP
    inc bx
    add [bx], al
    cmp al, 0x0a
    jl NEXT1
    add byte [bx], 0x27
    NEXT1:

    mov al, dl
    shr al, 4
    mov bx, TEMP
    add [bx], al
    cmp al, 0x0a
    jl NEXT2
    add byte [bx], 0x27
    NEXT2:

    mov bx, TEMP
    call print_string

    mov word [bx], '00'
    popa
    ret

; template variable
TEMP:
    db '00 ', 0

