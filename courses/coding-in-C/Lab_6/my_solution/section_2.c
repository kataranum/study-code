#include <stdio.h>

typedef struct {
    float fuel_level,
    float max_fuel_level,
    char model[256],
} Car;

int refuel(Car *p_car, float amount) {
    if (p_car->fuel_level + amount > p_car->max_fuel_level) {
        return 0;
    }

    p_car->fuel_level += amount;
    return 1;
}

int main(void) {
    return 0;
}
