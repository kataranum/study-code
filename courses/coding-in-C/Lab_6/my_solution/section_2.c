#include <stdio.h>
#include <string.h>

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

Car init_car(float fuel_level, float max_fuel_level, const char *str_model) {
    Car car;

    car.fuel_level = fuel_level;
    car.max_fuel_level = max_fuel_level;
    strncpy(str_model, car.model, sizeof(car.model));

    return car;
}

int main(void) {
    Car car = init_car(10.0, 50.0, "Hyundai i10");

    refuel(&car, 30.0);
    refuel(&car, 50.0);

    return 0;
}
