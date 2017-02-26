#ifndef _GDT_H
#define _GDT_H 1

#include <stdio.h>
#include <stdint.h>

extern void load_gdt(void* gdt_desc);

typedef struct {
    unsigned int limit_low : 16;
    unsigned int base_low  : 24;
    unsigned int access    :  8;
    unsigned int limit_high:  4;
    unsigned int flags     :  4;
    unsigned int base_high :  8;
} __attribute((packed)) gdt_entry_t;

typedef struct {
    unsigned int size: 16;
    void*        offset;
    gdt_entry_t  entry[4];
} __attribute((packed)) gdt_descriptor_t;

gdt_entry_t create_gdt_desc_entry(unsigned int, unsigned int, unsigned char, unsigned char);

#endif
