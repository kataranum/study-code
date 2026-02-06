#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool read_word(char* str, int max_len) {
    bool result = fgets(str, max_len, stdin);

    int last_char_index = strlen(str) - 1;
    str[last_char_index] = '\0';

    return result;
}

int main() {
    printf("Enter a word: ");

    char buffer[100];
    if (! read_word(buffer, sizeof(buffer))) {
        printf("Failed to read word.\n");
    }

    return 0;
}
