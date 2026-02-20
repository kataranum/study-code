#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int user_input_n(void) {
    printf("Please input n: ");

    // read from stdin
    char buffer[64];
    char *result = fgets(buffer, sizeof(buffer), stdin);

    if (!result) {
        printf("Invalid input.\n");
        exit(1);
    }

    // Replace newline at end with null
    buffer[strlen(buffer) - 1] = '\0';

    // parse as float
    char *p_end;
    float value = strtof(buffer, &p_end);
    if (p_end == buffer) {
        printf("Could not parse '%s' as float.\n", buffer);
        exit(2);
    }

    return value;
}

int main(void) {
    printf("Please input n: ");

    return 0;
}
