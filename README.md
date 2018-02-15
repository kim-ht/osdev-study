This is my first simple os developed on linux.
It just performs shell feature in which "END" command works only.

if you want test:
$ make clean; make
$ qemu-system-i386 -boot a -fda kernel_img #boot with floppy disk

To study and make this, I did refer to a lot of resources below:

Writing a Simple Oerating System from Scratch
    --> https://www.cs.bham.ac.uk/~exr/lectures/opsys/10.../os-dev.pdf
GitHub - cfenollosa/os-tutorial: How to create an OS from scratch
    --> https://github.com/cfenollosa/os-tutorial
OSDev Wiki
    --> https://wiki.osdev.org
Bran's Kernel Development Tutorial
    --> http://www.osdever.net/bkerndev/Docs/pit.htm

