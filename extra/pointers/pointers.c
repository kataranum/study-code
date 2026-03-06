#include <stdio.h>

int main() {
    int my_numbers[5] = { 10, 20, 30, 40, 50 };
    int my_numbers_len = sizeof(my_numbers) / sizeof(my_numbers[0]);

    int *first_pointer = my_numbers + 1;
    int *second_pointer = my_numbers + my_numbers_len - 1;

    // Difference expected to be 3, because second and fifth(last) element are
    // three spaces apart.
    int difference = (int)(second_pointer - first_pointer);

    printf("First pointer: %p\n", first_pointer);
    printf("Second pointer: %p\n", second_pointer);
    printf("Difference: %d\n", difference);

    return 0;
}
