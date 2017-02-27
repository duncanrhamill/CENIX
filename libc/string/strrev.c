#include <string.h>
#include <stdint.h>

void strrev(char* str) {
    int i;
    int j;
    unsigned char a;
    unsigned int len = strlen((const char*) str);

    for (i = 0, j = len - 1; i < j; i++, j--) {
        a = str[i];
        str[i] = str[j];
        str[j] = a;
    }
}
