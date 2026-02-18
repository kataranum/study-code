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
        // reading from file
        float time, probability;

        int res = fscanf(f, "%f %f\n", &time, &probability);

        if (res < 2) {
            break;
        }

        p_sensor->data[i].time = time;
        p_sensor->data[i].probability = probability;

        // binary detection
        p_sensor->object_detection[i] = probability > p_sensor->threshold;
    }

    fclose(f);
    return true;
}

void print_detection_interval(const Sensor *p_sensor) {
    for (int i = 1; i < DATA_SIZE; i++) {
        int current_detection = p_sensor->object_detection[i];
        int last_detection    = p_sensor->object_detection[i - 1];
        float time = p_sensor->data[i].time;

        // trigger on rising edge
        if (!last_detection && current_detection) {
            printf("Start: %.2f s ", time);
        }
        // trigger on falling edge
        else if (last_detection && !current_detection) {
            printf("End: %.2f s ", time);
        }
    }
}

void print_results(const Sensor *p_sensor_1, const Sensor *p_sensor_2) {
    // sensor 1 detections
    printf("Sensor 1 detections: ");
    print_detection_interval(p_sensor_1);
    printf("\n\n");

    // sensor 2 detections
    printf("Sensor 2 detections: ");
    print_detection_interval(p_sensor_2);
    printf("\n\n");
}

int main(void) {
    Sensor sensor_1 = init_sensor(1, 0.8);
    Sensor sensor_2 = init_sensor(2, 0.7);

    read_sensor(&sensor_1, "../sensor1.txt");
    read_sensor(&sensor_2, "../sensor2.txt");

    print_results(&sensor_1, &sensor_2);
    
    return 0;
}
