#include <stdio.h>

void check_status(unsigned char status) {
    // check Error
    if (status & (0x01 << 7)) {
        printf("General error.\n");
    }

    // check overtemperature
    if (status & (0x01 << 6)) {
        printf("Overtemperature.\n");
    }

    // check undervoltage
    if (status & (0x01 << 5)) {
        printf("Undervoltage.\n");
    }

    unsigned char measurement = status & 0x0F;
    printf("Measurement: %d\n", measurement);
}

int main() {
    unsigned char status = 0xA7;
    check_status(status);

    return 0;
}
