#include <stdio.h>

void kernel_log(char* format, int level) {
    char* level_str;

    switch (level) {
        case 1:
            // error
            level_str = " [E] ";
        case 0:
        default:
            // normal
            level_str = " [ ] ";
    }

    printf("%s %s\n", level_str, message);
}
