/* Bootloader looks for the _start point */
ENTRY(_start);

/* Where the various sections of the object files will be put in the final image */
SECTIONS
{
    /* start at 1 MiB */
    . = 1M;


    /* multiboot before the code */
    .text BLOCK(4K) : ALIGN(4K)
    {
        *(.multiboot)
        *(.text)
    }

    /* read only data */
    .rodata BLOCK(4K) : ALIGN(4K)
    {
        *(.rodata)
    }

    /* read-write data */
    .data BLOCK(4K) : ALIGN(4K)
    {
        *(.data)
    }

    /* read-write data uninit and the stack */
    .bss BLOCK(4K) : ALIGN(4K)
    {
        *(COMMON)
        *(.bss)
    }
}
