#include <stdio.h>

void print_column_letters() {
    printf("   ");

    for (int column = 0; column < 8; column++) {
        char letter = 'A' + column;
        printf("%c   ", letter);
    }

    printf("\n");
}

void print_horizontal_line() {
    printf(" ");

    for (int column = 0; column < 8; column++) {
        printf("+---");
    }

    printf("+\n");
}

void print_row(short row) {
    printf("%d ", row);

    for (short column = 0; column < 8; column++) {
        short is_black = (row + column) % 2;

        if (is_black) {
            printf("|   ");
        }
        else {
            printf("|###");
        }
    }

    printf("| %d\n", row);
}

void print_chessboard() {
    print_column_letters();

    for (short row = 8; row >= 1; row--) {
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
