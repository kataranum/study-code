#include <stdio.h>

#define INPUT_PATH "input.txt"
#define OUTPUT_PATH "output.txt"

void test_reading(void) {
    FILE *f = fopen(INPUT_PATH);
    if (f == NULL) {
        printf("Failed to open %s\n", INPUT_PATH);
        exit(1);
    }

    printf("first fgetc(): %c\n", fgetc(f));
    printf("second fgetc(): %c\n", fgetc(f));

    printf("fgets(): %s\n", fgets(f));

    printf("fscanf(): %s\n", fscanf(f, "%s"));

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
