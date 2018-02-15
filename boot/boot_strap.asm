;
; loads code from disk into memory, let inturrupts be disabled, sets gdt,
; switches to protected mode, jumps to the code loaded.
;
[org 0x7c00]
[bits 16]
KERNEL_OFFSET equ 0x1000
    mov [BOOT_DRIVE], dl
    mov bp, 0x9000
    mov sp, bp
    mov bx, REAL_MODE_MSG
    call print_string
    mov bx, KERNEL_OFFSET
    mov dh, 32
    mov dl, [BOOT_DRIVE]
    call disk_load
    call switch_to_pm
    jmp $

[bits 32]    
BEGIN_PM:
    mov bx, PROTECTED_MODE_MSG
    call print_string_pm
    call KERNEL_OFFSET
    jmp $

%include "./boot/print_string.asm"
%include "./boot/disk_load.asm"
%include "./boot/switch_to_pm.asm"
%include "./boot/print_string_pm.asm"
%include "./boot/gdt.asm"

BOOT_DRIVE db 0
REAL_MODE_MSG db 'this is real mode.', 0
PROTECTED_MODE_MSG db 'this is protected mode.', 0

times 510-($-$$) db 0
dw 0xaa55

