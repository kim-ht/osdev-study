; disk_load - reads disk into memory.
;
; @bx - the address that content of sectors be written.
; @dh - the number of sectors.
; @dl - which drive let be read.
[bits 16]
disk_load:
    push dx
    mov ah, 0x02
    mov al, dh
    mov ch, 0x00
    mov dh, 0x00
    mov cl, 0x02
    int 0x13 
    jc disk_error
    pop dx
    cmp dh, al ; al is sectors read and dh is sectors to read.
    jne disk_error
    ret
disk_error:
    mov bx, DISK_ERROR_MSG
    call print_string

; data
DISK_ERROR_MSG:
    db "disk read error!", 0

