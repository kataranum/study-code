#include <stdio.h>

void print_chessboard() {
    for (int file = 8; file >= 1; file--) {
        for (int rank = 0; rank < 8; rank++) {
            char letter = 'A' + rank;
            printf("%c%d ", letter, file);
        }

        printf("\n");
    }
}

int main() {
    print_chessboard();

    return 0;
}
