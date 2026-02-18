/*
 * File: section_2.c
 * Description: Lab 5 Section II implementation
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Please input at least one parameter.\n");
        return 1;
    }

    printf("Using array indexing:\n");
    for (int i = 1; i < argc; i++) {
        printf("Index: %d\n", i);
        printf("Address: %p\n", argv[i]);
        printf("Content: %s\n", argv[i]);
        printf("Length: %ld\n\n", strlen(argv[i]));
    }

    printf("Using pointer indexing:\n");
    for (int i = 1; i < argc; i++) {
        printf("Index: %d\n", i);
        printf("Address: %p\n", *(argv + i));
        printf("Content: %s\n", *(argv + i));
        printf("Length: %ld\n\n", strlen(*(argv + i)));
    }

    // The array index operator `pointer[index]` is equivalent to writing
    // `*(pointer + index)`.

    // Arrays are treated like pointers to their first element under most
    // circumstances. Only exception is using `sizeof`, for pointers that gives
    // the size of the pointer type, for arrays it gives the size of the whole
    // array.

    return 0;
}
