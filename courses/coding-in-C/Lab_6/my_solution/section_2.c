#include <stdio.h>
#include <string.h>

typedef struct {
    float fuel_level;
    float max_fuel_level;
    char model[256];
} Car;

int refuel(Car *p_car, float amount) {
    if (p_car->fuel_level + amount > p_car->max_fuel_level) {
        printf("Refueling too much\n");
        return 0;
    }

    p_car->fuel_level += amount;
    return 1;
}

Car init_car(float fuel_level, float max_fuel_level, const char *str_model) {
    Car car;

    car.fuel_level = fuel_level;
    car.max_fuel_level = max_fuel_level;
    strncpy(car.model, str_model, sizeof(car.model));

    return car;
}

int main(void) {
    Car car = init_car(10.0, 50.0, "Hyundai i10");

    printf("Initial fuel level: %f\n", car.fuel_level);

    printf("Filling 30 litres\n");
    refuel(&car, 30.0);
    printf("Fuel level is now %f\n", car.fuel_level);

    printf("Filling 50 litres\n");
    refuel(&car, 50.0);
    printf("Fuel level is now %f\n", car.fuel_level);

    return 0;
}
