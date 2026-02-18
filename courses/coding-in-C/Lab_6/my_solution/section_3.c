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

Sensor init_sensor(int id, double threshold) {
    Sensor sensor;

    sensor.id = id;
    sensor.threshold = threshold;

    for (int i = 0; i < DATA_SIZE; i++) {
        sensor.data[i].time = 0.0;
        sensor.data[i].probability = 0.0;
        
        sensor.object_detection[i] = 0;
    }

    return sensor;
}

int main(void) {
    Sensor sensor_1 = init_sensor(1, 0.8);
    Sensor sensor_2 = init_sensor(2, 0.7);
    
    return 0;
}
