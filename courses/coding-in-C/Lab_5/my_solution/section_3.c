/*
 * File: section_3.c
 * Description: Lab5 Section III implementation
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SPACE_SIZE 10

/**
 * @brief Must be called at startup to initialize RNG
 */
void init_rng(void) {
    srand(time(NULL));
}

/**
 * @brief Makes sure `value` is inside the given bounds
 *
 * If `value` is within bounds, the value is returned. If it's e.g. lower than
 * `min`, `min` is returned instead. The returned value is never outside these
 * bounds.
 *
 * @param[in] value Given value
 * @param[in] min   Lower bound
 * @param[in] max   Upper bound
 * @return          `value` clamped between the bounds
 */
int clamp(int value, int min, int max) {
    if (value < min) {
        return min;
    }
    if (value > max) {
        return max;
    }
    
    return value;
}

/**
 * @brief Randomly returns either -1 or +1
 *
 * This function can be called multiple times consecutively, the return value
 * will be random every time.
 *
 * @return Randomly -1 or +1
 */
int get_particle_offset(void) {
    if (rand() % 2) {
        return 1;
    }
    else {
        return -1;
    }
}

/**
 * @brief Anihilate all colliding particles
 *
 * If more than one particle is occupying the same space (the value at that
 * space will be higher than 1), set that space to 0 and print a message.
 *
 * @param[in] p_space Given space of particles
 * @param[in] size    Array length of `p_space`
 */
void anihilate_particles(int *p_space, int size) {
    for (int i = 0; i < size; i++) {
        int particle = p_space[i];

        if (particle > 1) {
            printf("Collision at i = %d\n", i);
            p_space[i] = 0;
        }
    }
}

/**
 * @brief Simulate a timestep in `p_space`, writing the result into p_next
 *
 * Particles (denoted by a 1) will randomly move either left or right. In case
 * two particles land on the same spot, they will anihilate each other, leaving
 * only a blank space (denoted by a 0). There will also be a print message on
 * collision.
 *
 * @param[in]  p_space Given space of particles
 * @param[out] p_next  Resulting particle positions
 * @param[in]  size    Array length of `p_space` and `p_next`
 */
void simulate_timestep(const int *p_space, int *p_next, int size) {
    for (int i = 0; i < size; i++) {
        int particle = p_space[i];

        if (!particle) {
            continue;
        }

        int new_position = i + get_particle_offset();

        // ensure particle doesn't go out of bounds
        new_position = clamp(new_position, 0, size-1);

        p_next[new_position] += particle;
    }

    anihilate_particles(p_next, size);
}

/**
 * @brief Get the amount of particles in `p_space`
 *
 * @param[in] p_space Given space of particles
 * @param[in] size    Array length of `p_space`
 */
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

/**
 * @brief Print a formated version of `p_space` including timestep and indices.
 *
 * @param[in] p_space  Given space of particles
 * @param[in] size     Array length of `p_space`
 * @param[in] timestep Current timestep
 */
void print_space(const int *p_space, int size, int timestep) {
    printf("T = %d\n", timestep);
    printf("i: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", i);
    }

    printf("\n%3s", "");
    for (int i = 0; i < size; i++) {
        printf("%d ", p_space[i]);
    }

    printf("\n\n");
}

int main(void) {
    init_rng();

    int space[SPACE_SIZE] = { 0 };
    int *p_space = space;

    space[2] = 1;
    space[4] = 1;
    space[6] = 1;

    int timestep = 0;

    print_space(space, SPACE_SIZE, timestep);

    while (amount_particles(space, SPACE_SIZE) > 1) {
        int space_next[SPACE_SIZE] = { 0 };
        simulate_timestep(p_space, space_next, SPACE_SIZE);
        memcpy(space, space_next, sizeof(space));

        timestep++;

        print_space(space, SPACE_SIZE, timestep);
    }

    printf("finished\n");

    return 0;
}
