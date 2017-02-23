# multiboot constants header
.set ALIGN,     1<<0
.set MEMINFO,   1<<1
.set FLAGS,     ALIGN | MEMINFO
.set MAGIC,     0x1BADB002
.set CHECKSUM,  -(MAGIC + FLAGS)

# Declare the mutliboot header, so GRUB know's we're a kernel
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Create the stack, multiboot won't do this for us
.section .bss
.align 16
stack_bottom:
.skip 16384     # stack is 16 KiB long
stack_top:

# Linker will look for _start in order to enter the kernel
.section .text
.global _start
.type _start, @function
_start:
    # Bootloader has now dumped us into 32-bit mode

    # Setup the stack so we can actually do some stuff with c
    mov $stack_top, %esp

    # call the init
    call _init

    #TODO Load GDT
    #TODO enable paging

    # Enter the kernel
    call kernel_main

    # Nothing left to do, enter an infinite loop
    cli
1:  hlt
    jmp 1b

# Set the size of the _start symbol
.size _start, . - _start
