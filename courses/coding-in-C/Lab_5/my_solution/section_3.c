#include <stdio.h>
#include <string.h>

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

int amount_particles(const int *p_space, int size) {
    int amount_particles = 0;

    for (int i = 0; i < size; i++) {
        int particle = p_space[i];

        if (particle) {
            amount_particles++;
        }
    }

    return amount_particles;
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
    int *p_space = space;

    space[2] = 1;
    space[4] = 1;
    space[6] = 1;

    int timestep = 0;

    while (true) {
        printf("T = %d\n", timestep++);
        print_space(space, SPACE_SIZE);

        int space_next[SPACE_SIZE] = { 0 };
        simulate_timestep(p_space, space_next, SPACE_SIZE);

        memcpy(space, space_next, sizeof(space));

        if (amount_particles(space, SPACE_SIZE) < 2) {
            break;
        }
    }

    printf("finished\n");

    return 0;
}
