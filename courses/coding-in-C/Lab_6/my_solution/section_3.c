#include <stdio.h>
#include <stdbool.h>

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

bool read_sensor(Sensor *p_sensor, const char *path) {
    FILE *f = fopen(path, "r");

    for (int i = 0; i < DATA_SIZE; i++) {
        float seconds, measurement;

        int res = fscanf(f, "%f %f\n", &seconds, &measurement);

        if (res < 2) {
            break;
        }

        p_sensor->data[i].time = seconds;
        p_sensor->data[i].probability = measurement;
    }

    fclose(f);
    return true;
}

int main(void) {
    Sensor sensor_1 = init_sensor(1, 0.8);
    Sensor sensor_2 = init_sensor(2, 0.7);

    read_sensor(&sensor_1, "../sensor1.txt");
    read_sensor(&sensor_2, "../sensor2.txt");

    // debug print first 10 elements
    for (int i = 0; i < 10; i++) {
        printf("Sensor 1 data[%d] = %f; %f\n", i, sensor_1.data[i].time, sensor_1.data[i].probability);
        printf("Sensor 2 data[%d] = %f; %f\n", i, sensor_2.data[i].time, sensor_2.data[i].probability);
        printf("\n");
    }
    
    return 0;
}
