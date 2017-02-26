#include <kernel/gdt.h>

gdt_entry_t create_gdt_desc_entry(unsigned int base, unsigned int limit, unsigned char access, unsigned char flags) {
    gdt_entry_t entry;

    entry.limit_low = limit & 0xFFFF;
    entry.base_low = base & 0xFFFFFF;
    entry.access = access;
    entry.flags = flags & 0xFF;
    entry.limit_high = limit >> 16;
    entry.base_high = base >> 24;

    return entry;
}
