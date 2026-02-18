#include <stdio.h>

#define INPUT_PATH "input.txt"
#define OUTPUT_PATH "output.txt"

void test_reading(void) {
    FILE *f = fopen(INPUT_PATH);

    fclose(f);
}

void test_writing(void) {
    FILE *f = fopen(OUTPUT_PATH);

    fclose(f);
}

int main(void) {
    test_reading();
    test_writing();

    return 0;
}
