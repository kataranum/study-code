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

int* calculate_squares(int amount) {
    int *p_squares = calloc(sizeof(int), amount);

    for (int i = 0; i < amount; i++) {
        p_squares[i] = i*i;
    }

    return p_squares;
}

int* expand_squares(int *p_squares, int old_size, int extend_amount) {
    int new_size = old_size + extend_amount;
    int *p_new = realloc(p_squares, new_size);
    if (p_new == NULL) {
        return NULL;
    }

    for (int i = old_size; i < new_size; i++) {
        p_squares[i] = i*i;
    }

    return p_new;
}

int main(void) {
    printf("Please input n: ");
    int n = user_input_n();

    int *p_n = malloc(sizeof(int));
    *p_n = n;

    int *p_squares = calculate_squares(n);
    int *p_tmp = expand_squares(p_squares, n, 2*n);

    if (p_tmp == NULL) {
        printf("Realloc failure.\n");
        return 3;
    }

    p_squares = p_tmp;

    free(p_squares);
    free(p_n);
    return 0;
}
