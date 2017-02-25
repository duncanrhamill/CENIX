#include <string.h>
#include <stdbool.h>

void* malloc(size_t divs) {
    // Allocate #divs divisions to the process, mark as used and set the last used
    // div to the returned address
    bool found_free_divs = false;
    bool found_on_first = false;

    void* next_free = div_get_next_free(div_last_used);
    
    while (!found_free_divs) {

        for (size_t i = 0; i < divs; i++) {
            if (!div_is_free(next_free + (i * DIV_SIZE))) {
                next_free = div_get_next_free(next_free + (i * DIV_SIZE));
            }
        }

        found_free_divs = true;
    }

    return next_free;
}

bool div_is_free(void* div_start_ptr) {
    unsigned char* div_start = (unsigned char*) div_start_ptr;
    return div_start[0];
}

void* div_get_next_free(void * div_start_ptr) {
    const void* next;
    memcpy(div_start_ptr, next, 4);
    next = next >> 2;
    return next;
}
