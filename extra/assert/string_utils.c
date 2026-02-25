#include "string_utils.h"

int custom_len(const char *str) {
    int len = 0;

    while (*str != '\0') {
        str++;
        len++;
    }

    return len;
}
