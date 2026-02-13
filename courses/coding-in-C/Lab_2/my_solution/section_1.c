#include <stdio.h>

void print_chessboard() {
    for (int row = 8; row >= 1; row--) {
        for (int column = 0; column < 8; column++) {
            char letter = 'A' + column;
            printf("%c%d ", letter, row);
        }

        printf("\n");
    }
}

int main() {
    print_chessboard();

    return 0;
}
