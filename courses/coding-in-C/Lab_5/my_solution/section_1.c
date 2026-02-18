/*
 * File: section_1.c
 * Description: Lab 5 Section I implementation
 */

#include <stdio.h>

int main(void) {
    int x = 10;
    int *p = &x;
    int **pp = &p;

    printf("x = %d\n", x);
    printf("x via p = %d\n", *p);
    printf("x via pp = %d\n", **pp);

    **pp = 42;
    printf("x = %d\n", x);

    return 0;
}
