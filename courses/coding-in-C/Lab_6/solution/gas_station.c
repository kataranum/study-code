#include <stdio.h>

typedef struct Car
{
    float max_fuel_level; // in liters
    float fuel_level;     // in liters
    const char *model;

} Car;

void refuel(Car *car, float fuel)
{
    if ((car->fuel_level + fuel) > car->max_fuel_level)
    {
        printf("Error: The maximum amount of fuel is succeded.");
        return;
    }
    car->fuel_level = car->fuel_level + fuel;
}

int main()
{

    Car myCar = {60.0, 11.1, "C-Class"};
    refuel(&myCar, 40);

    printf("Fuel level is %f", myCar.fuel_level);
    return 0;
}
