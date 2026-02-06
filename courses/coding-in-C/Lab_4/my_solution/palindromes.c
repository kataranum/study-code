#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool read_word(char* str, int max_len) {
    bool result = fgets(str, max_len, stdin);

    int last_char_index = strlen(str) - 1;
    str[last_char_index] = '\0';

    return result;
}

bool is_palindrome_case_sensitive(char* str) {
    int str_len = strlen(str);

    for (int i = 0; i < str_len; i++) {
        char* p_front = str + i;
        char* p_back = str + (str_len - i - 1);

        if (*p_front != *p_back) {
            return false;
        }
    }

    return true;
}

int main() {
    printf("Enter a word: ");

    char buffer[100];
    if (! read_word(buffer, sizeof(buffer))) {
        printf("Failed to read word.\n");
    }

    if (is_palindrome_case_sensitive(buffer)) {
        printf("Your word \"%s\" IS a palindrome!\n", buffer);
    }
    else {
        printf("Your word \"%s\" IS NOT a palindrome!\n", buffer);
    }

    return 0;
}
