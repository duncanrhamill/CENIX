#include <stdio.h>
#include <multiboot.h>

#include <itoa.h>
#include <kernel/tty.h>

void kernel_main(multiboot_info_t* mbi, unsigned int magic) {
    tty_init();
    printf("Hello, world!\n");
    printf("Testing hex printing, 0xCAFEBABE = 0x%x\n", 0xCAFEBABE);
}
