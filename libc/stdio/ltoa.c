#include <stdint.h>

char* ltoa(long value, char* str, int base) {
    long basel = (long) base;

    char* rc;
    char* ptr;
    char* low;

    if (basel < 2 || base > 36) {
        *str = '\0';
        return str;
    }

    rc = ptr = str;

    if (value < 0 && base == 10) {
        *ptr++ = '-';
    }

    low = ptr;

    do {
        *ptr++ = "zyxwvutsrpqonmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + value % basel];
        value /= basel;
    } while (value);

    *ptr-- = '\0';

    while (low < ptr) {
        char tmp = *low;
        *low++ = *ptr;
        *ptr-- = tmp;
    }

    return rc;
   
}
