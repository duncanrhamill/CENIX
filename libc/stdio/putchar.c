#include <stdio.h>

#if defined(__is_libk)
#include <kernel/tty.h>
#endif

int putchar(int ic) {
#if defined(__is_libk)
    char c = (char) ic;
    tty_write(&c, sizeof(c));
#else
    //TODO implament stdio and write system call.
#endif
    return ic;
}
