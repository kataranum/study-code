#include <stdio.h>

#define SPACE_SIZE 10

void simulate_timestep(int* space, int* next, int size) {
    // TODO: Process this
}

void print_space(int *p_space, int size) {
    printf("i: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", i);
    }

    printf("\n%3s", "");
    for (int i = 0; i < size; i++) {
        printf("%d ", p_space[i]);
    }

    printf("\n");
}

int main(void) {
    int space[SPACE_SIZE] = { 0 };

    space[2] = 1;
    space[4] = 1;
    space[6] = 1;

    int *p_space = space;
    int space_next[SPACE_SIZE] = { 0 };

    printf("T = 0\n");
    print_space(space, SPACE_SIZE);

    printf("\nT = 1\n");
    print_space(space_next, SPACE_SIZE);

    return 0;
}
