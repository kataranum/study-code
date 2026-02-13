#include <stdio.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Please input at least one parameter.\n");
        return 1;
    }

    printf("argc: %d\n", argc);

    return 0;
}
