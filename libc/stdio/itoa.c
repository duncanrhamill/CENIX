#include <stdint.h>
#include <string.h>

#define MAX_INT 0x7FFFFFFF

char* itoa(int value, char* str, int base) {
    int i = 0;
    int isNeg = 0;
    
    if (value > MAX_INT) {
        return "ERR:INT > MAX_INT";
    }


    if (value == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    if (value < 0 && base == 10) {
        isNeg = 1;
        value = -value;
    }

    while (value != 0) {
        int rem = value % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        value /= base;
    }

    if (isNeg) {
        str[i++] = '-';
    }

    str[i] = '\0';

    strrev(str);

    return str;
}
