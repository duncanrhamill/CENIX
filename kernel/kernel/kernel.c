#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/gdt.h>

void kernel_main(void) {
    tty_init();
    printf("Hello, world!\n");
    printf("Creating gdt...\n");
    gdt_descriptor_t gdt_desc;


    gdt_desc.entry[0] = create_gdt_desc_entry(0, 0, 0, 0); // the null entry
    gdt_desc.entry[1] = create_gdt_desc_entry(0, 0xFFFFFFFF, 0x9A, 0xC); // code
    gdt_desc.entry[2] = create_gdt_desc_entry(0, 0xFFFFFFFF, 0x92, 0xC); // data
    gdt_desc.entry[3] = create_gdt_desc_entry(0, 0xFFFFFFFF, 0x9A, 0xC); // tss

    gdt_desc.offset = &gdt_desc.entry;
    gdt_desc.size = 4 * 64;

    char* buff = "                    ";
    
    printf("Created gdt:\n");
    itoa(gdt_desc.size, buff, 16);
    printf("    Addr = 0x%s\n");
    

}
