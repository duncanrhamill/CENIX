#ifndef _MALLOC_H
#define _MALLOC_H

void* DIV_LAST_USED = 0x100000;

void* malloc(size_t);
bool div_is_free(void*);
void* div_get_next_free(void*);

#endif
