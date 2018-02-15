[bits 32]

VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLACK equ 0x0f

; print_string_pm - prints a string in 32-bit protected mode.
;
; ebx - the pointer to the string to print.
print_string_pm:
    pusha
    mov edx, VIDEO_MEMORY
print_string_pm_loop:
    mov al, [ebx]
    cmp al, 0x00
    je print_string_pm_done
    mov ah, WHITE_ON_BLACK
    mov [edx], ax
    add edx, 2
    inc ebx
    jmp print_string_pm_loop
print_string_pm_done:
    popa
    ret
