C_SOURCES = $(wildcard ./cpu/*.c ./driver/*.c ./kernel/*.c ./libc/*.c)
HEADERS = $(wildcard ./cpu/*.h ./driver/*.h ./kernel/*.h ./libc/*.h)
ASMS = $(wildcard ./cpu/*.asm ./driver/*.asm ./kernel/*.asm ./libc/*.asm)
OBJS = $(C_SOURCES:.c=.o ./cpu/interrupt.o)

#merges bootstrap and kernel code
kernel_img: ./boot/boot_strap.bin kernel.bin
	cat $^ > $@
	#cp kernel_img ~/MacHome/study/ #copying to my host OSX

#builds kernel code
kernel.bin: ./boot/kernel_entry.o $(OBJS)
	ld -Ttext 0x1000 --oformat binary -m elf_i386 -o $@ $^

%.bin: %.asm
	nasm -f bin -o $@ $<

#creates objects from .c
%.o: %.c
	gcc -c -m32 -ffreestanding -o $@ $<

#creates objects from .asm
%.o: %.asm
	nasm -f elf -o $@ $<

#copy to host OSX
copy:
	cp kernel_img ~/MacHome/study/

#cleans up
clean:
	rm -rf ./cpu/*.o ./driver/*.o ./kernel/*.o
	rm -rf *.o *.bin
