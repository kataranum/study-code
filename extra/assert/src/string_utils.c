#include "string_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int custom_len(const char *str) {
    int len = 0;

    while (*str != '\0') {
        str++;
        len++;
    }

    return len;
}

char* read_line_dynamic() {
    char buffer[256];

    char *success = fgets(buffer, sizeof(buffer), stdin);

    if (!success) {
        return NULL;
    }

    // Replace newline with 0
    int len = custom_len(buffer);
    success[len - 1] = '\0';
    len--;

    char *p_str = malloc(sizeof(char) * (len + 1));

    if (!p_str) {
        return NULL;
    }

    memcpy(p_str, success, sizeof(char) * (len + 1));

    return p_str;
}
