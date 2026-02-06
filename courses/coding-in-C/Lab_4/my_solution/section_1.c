#include <stdio.h>

void modify_string(char* str) {
    str[1] = 'c';
}

int main() {
    // Error
    // Segfaults because the string literal is not stored in a variable, but in
    // a read-only data section. Trying to modify const data results in a crash.
    //modify_string("AAtions speak louder than words");

    char str[] = "AAtions speak louder than words";
    modify_string(str);

    printf("%s\n", str);

    return 0;
}
