#include <stdio.h>
#include <stdint.h>

void print_column_letters() {
    printf("%4s", "");

    for (uint8_t column = 0; column < 8; column++) {
        char letter = 'A' + column;
        printf("%-4c", letter);
    }

    printf("\n");
}

void print_horizontal_line() {
    printf("%2s", "");

    for (uint8_t column = 0; column < 8; column++) {
        printf("+---");
    }

    printf("+\n");
}

void print_row(uint8_t row) {
    printf("%-2d", row);

    for (uint8_t column = 0; column < 8; column++) {
        uint8_t is_black = (row + column) % 2;

        if (is_black) {
            printf("%-4s", "|");
        }
        else {
            printf("%-4s", "|###");
        }
    }

    printf("|%2d\n", row);
}

void print_chessboard() {
    print_column_letters();

    for (uint8_t row = 8; row >= 1; row--) {
        print_horizontal_line();
        print_row(row);
    }

    print_horizontal_line();
    print_column_letters();
}

int main() {
    print_chessboard();

    return 0;
}
