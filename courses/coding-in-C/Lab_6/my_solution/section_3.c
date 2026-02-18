#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

float abs_f(float val) {
    // evil bit manipulation trick
    // set the leftmost (sign) bit to 0 to make any float positive
    int bits = *(int*)(&val);
    bits &= 0x7FFF;
    return *(float*)(&bits);
}

bool float_eq(float lhs, float rhs) {
    const float EPSILON = 0.0001;
    float delta = lhs - rhs;

    return abs_f(delta) < EPSILON;
}

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

        float current_time = p_sensor->data[i].time;
        float last_time = p_sensor->data[i - 1].time;

        // Edge case: When the last measurement is still above threshold, we
        // still need to print an "End" message as we do on falling edge.
        int is_last_and_active = i == DATA_SIZE-1 && current_detection;

        // trigger on rising edge
        if (!last_detection && current_detection) {
            printf("Start: %.2f s ", current_time);
        }
        // trigger on falling edge
        else if (last_detection && !current_detection) {
            printf("End: %.2f s ", last_time);
        }
        else if (is_last_and_active) {
            printf("End: %.2f s ", current_time);
        }
    }
}

void print_fused_intervals(const Sensor *p_sensor_1, const Sensor *p_sensor_2) {
    for (int i = 1; i < DATA_SIZE; i++) {
        int current_detection_1 = p_sensor_1->object_detection[i];
        int current_detection_2 = p_sensor_2-> object_detection[i];
        int last_detection_1 = p_sensor_1->object_detection[i - 1];
        int last_detection_2 = p_sensor_2->object_detection[i - 1];

        float current_time = p_sensor_1->data[i].time;
        float last_time = p_sensor_1->data[i - 1].time;

        if (!float_eq(current_time, p_sensor_2->data[i].time)) {
            printf("Sensor 1 and Sensor 2 times don't line up.\n");
            printf("Unsupported operation\n");
            exit(1);
        }

        int current_detection = current_detection_1 && current_detection_2;
        int last_detection = last_detection_1 && last_detection_2;

        // Edge case: When the last measurement is still above threshold, we
        // still need to print an "End" message as we do on falling edge.
        int is_last_and_active = i == DATA_SIZE-1 && current_detection;

        // trigger on rising edge
        if (!last_detection && current_detection) {
            printf("Start: %.2f s ", current_time);
        }
        // trigger on falling edge
        else if (last_detection && !current_detection) {
            printf("End: %.2f s ", last_time);
        }
        else if (is_last_and_active) {
            printf("End: %.2f s ", current_time);
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

    printf("Fused sensor detections: ");
    print_fused_intervals(p_sensor_1, p_sensor_2);
    printf("\n");
}

int main(void) {
    Sensor sensor_1 = init_sensor(1, 0.8);
    Sensor sensor_2 = init_sensor(2, 0.7);

    read_sensor(&sensor_1, "../sensor1.txt");
    read_sensor(&sensor_2, "../sensor2.txt");

    print_results(&sensor_1, &sensor_2);
    
    return 0;
}
