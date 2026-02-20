#include <stdio.h>
#include <stdlib.h>

#define INPUT_PATH "section_1/input.txt"
#define OUTPUT_PATH "section_1/output.txt"

void test_reading(void) {
    FILE *f = fopen(INPUT_PATH, "r");
    if (f == NULL) {
        printf("Failed to open %s\n", INPUT_PATH);
        exit(1);
    }

    printf("first fgetc(): %c\n", fgetc(f));
    printf("second fgetc(): %c\n", fgetc(f));

    char buffer[256];
    fgets(buffer, sizeof(buffer), f);
    printf("fgets(): %s\n", buffer);

    char buffer_2[256];
    char buffer_3[256];
    fscanf(f, "%s %s %s", buffer, buffer_2, buffer_3);
    printf("fscanf(): %s %s %s\n", buffer, buffer_2, buffer_3);

    fclose(f);
}

void test_writing(void) {
    FILE *f = fopen(OUTPUT_PATH, "w");
    if (f == NULL) {
        printf("Failed to open %s\n", OUTPUT_PATH);
        exit(1);
    }

    fputc('a', f);
    fputc('b', f);

    fputs("\nhello I am computer\n", f);

    fprintf(f, "The number is %d and the other numer is %d\n", -5, 7);

    fclose(f);
}

int main(void) {
    test_reading();
    test_writing();

    return 0;
}
