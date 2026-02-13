#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool read_word(char* str, int max_len) {
    bool result = fgets(str, max_len, stdin);

    int last_char_index = strlen(str) - 1;
    str[last_char_index] = '\0';

    return result;
}

bool is_palindrome_case_sensitive(const char* str) {
    int str_len = strlen(str);

    for (int i = 0; i < str_len / 2; i++) {
        char c_front = str[i];
        char c_back = str[str_len - i - 1];

        if (c_front != c_back) {
            return false;
        }
    }

    return true;
}

bool is_palindrome_case_insensitive(const char* str) {
    int str_len = strlen(str);

    for (int i = 0; i < str_len / 2; i++) {
        char c_front = str[i];
        char c_back = str[str_len - i - 1];

        if ( tolower(c_front) != tolower(c_back) ) {
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

    if (is_palindrome_case_insensitive(buffer)) {
        printf("Your word \"%s\" IS a palindrome!\n", buffer);
    }
    else {
        printf("Your word \"%s\" IS NOT a palindrome!\n", buffer);
    }

    return 0;
}
