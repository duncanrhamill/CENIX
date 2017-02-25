#include <stdio.h>
#include <multiboot.h>

#include <itoa.h>
#include <kernel/tty.h>

void kernel_main(multiboot_info_t* mbi, unsigned int magic) {
    tty_init();
    printf("Loaded the CENIX kernel.\nBegining kernel log...\n");

    char* data = "                            "; //TODO actually allocate this propperly

    itoa(magic, data, 16);
    printf("loaded with magic number: 0x%s\n", data);
    
    ltoa(mbi->flags, data, 16);
    printf("mbi->flags: 0x%s\n", data);

    if (!mbi->flags & 0x1) {
        kernel_log("No valid multiboot info struct!", 1);
    }
    
    kernel_log("Test of log", 0);

    ltoa(mbi->mmap_addr, data, 16);
    printf("mmap addr: 0x%s\n", data);

    memory_map_t* mmap = (memory_map_t*) mbi->mmap_addr;

    while((long)mmap < mbi->mmap_addr + mbi->mmap_length) {
        mmap = (memory_map_t*) (unsigned int)mmap + 
                mmap->size + sizeof(mmap->size);
    }
    

    printf("mmap structure: \n");
    
    ltoa(mmap->size, data, 16);
    printf("    size: 0x%s\n", data);

    itoa(mmap->base_addr_low, data, 16);
    printf("    base address low: 0x%s\n", data);

    itoa(mmap->base_addr_high, data, 16);
    printf("    base address high: 0x%s\n", data);

    itoa(mmap->length_low, data, 16);
    printf("    length low: 0x%s\n", data);

    itoa(mmap->length_high, data, 16);
    printf("    length high: 0x%s\n", data);

    itoa(mmap->type, data, 16);
    printf("    type: 0x%s\n", data);



    
}
