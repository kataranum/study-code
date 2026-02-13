#include <stdio.h>

#define SPACE_SIZE 10

void simulate_timestep(const int *p_space, int *p_next, int size) {

    // particles always move right
    // TODO: Make them move randomly
    for (int i = 0; i < size; i++) {
        int particle = p_space[i];

        if (particle) {
            p_next[i + 1] = particle;
        }
    }
}

void print_space(const int *p_space, int size) {
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

    simulate_timestep(p_space, space_next, SPACE_SIZE);

    printf("T = 0\n");
    print_space(space, SPACE_SIZE);

    printf("\nT = 1\n");
    print_space(space_next, SPACE_SIZE);

    return 0;
}
