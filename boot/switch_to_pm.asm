[bits 16]
switch_to_pm:
    cli
    lgdt [gdt_descriptor]
    mov eax, cr0
    or eax, 0x00000001
    mov cr0, eax
    jmp CODE_SEGMENT_OFFSET:init_pm

[bits 32]
init_pm:
    mov ax, DATA_SEGMENT_OFFSET
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ebp, 0x90000
    mov esp, ebp
    call BEGIN_PM
