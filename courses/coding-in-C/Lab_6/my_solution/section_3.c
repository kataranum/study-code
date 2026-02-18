#include <stdio.h>

#define DATA_SIZE 3000

typedef struct {
    float time;
    double probability;
} SensorData;

typedef struct {
    int id;
    double threshold;
    SensorData data[DATA_SIZE];
    int object_detection[DATA_SIZE];
} Sensor;

int main(void) {
    return 0;
}
