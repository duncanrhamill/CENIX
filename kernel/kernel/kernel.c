#include <stdio.h>

#include <kernel/tty.h>

void kernel_main(void) {
    tty_init();
    printf("Hello, world!\n");
    printf("Testing hex printing, 0xCAFEBABE = 0x%x\n", 0xCAFEBABE);
}
