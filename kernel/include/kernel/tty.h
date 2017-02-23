/*  CENIX TTY.H 
 *  The main header file for the terminal (tty) */

#ifndef _KERNEL_TTY_H
#define _KERNEL_TTYP_H

#include <stddef.h>

void tty_init(void);
void tty_put_char(char c);
void tty_write(const char* data, size_t size);
void tty_write_str(const char* data);

#endif
