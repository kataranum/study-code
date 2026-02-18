/*
 * File: section_3.c
 * Description: Lab_6 Section III implementation
 */

#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE 3000

/**
 * @brief A data sample used in Sensor
 */
typedef struct {
    /** Time in seconds */
    float time;
    /** Measurement value between 0 and 1 */
    double probability;
} SensorData;

/**
 * @brief A collection of sensor sample points and related values
 */
typedef struct {
    /** (Unique) Sensor identification */
    int id;
    /** Threshold for triggering object detection */
    double threshold;
    /** All sample points */
    SensorData data[DATA_SIZE];
    /** All object detections mapped to sample points */
    int object_detection[DATA_SIZE];
} Sensor;

/**
 * @brief Mathematical absolute for a float value
 *
 * @param[in] val Given input value
 * @return        `val` but positive
 */
float abs_f(float val) {
    // evil bit manipulation trick
    // set the leftmost (sign) bit to 0 to make any float positive
    int bits = *(int*)(&val);
    bits &= 0x7FFF;
    return *(float*)(&bits);
}

/**
 * @brief Rough comparison of two floats
 *
 * Doesn't actually check for precise equality (as you shouldn't with floats).
 * This will return true if both floats are very close to each other.
 *
 * @param[in] lhs Left hand side
 * @param[in] rhs Right hand side
 * @return        `lhs` and `rhs` are close enough to be considered equal
 */
int float_eq(float lhs, float rhs) {
    const float EPSILON = 0.0001;
    float delta = lhs - rhs;

    return abs_f(delta) < EPSILON;
}

/**
 * @brief Initialize a `Sensor` with the given values and set samples to 0
 *
 * @param[in] id        Given sensor id
 * @param[in] threshold Given sensor threshold
 * @return              Fully initialized `Sensor`
 */
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

/**
 * @brief Read a sensor file into `p_sensor` and compute object detection
 *
 * Sensor data is set to the appropate values, and Sensor.object_detection will
 * be `true` if sensor probability is above sensor threshold.
 *
 * Will leave part of sensor data untouched if the sensor file has less than
 * `DATA_LEN` lines.
 *
 * @param[out] p_sensor Sensor to write values into
 * @param[in]  path     Path to sensor file
 */
void read_sensor(Sensor *p_sensor, const char *path) {
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
}

/**
 * @brief Common code between print_detection_intervals() and print_fused_intervals()
 *
 * Will print a start message for rising edge, and an end message for falling
 * edge. Also print an end message for the last sample if it still has active
 * object detection
 *
 * @param[in] current_detection `object_detection` for current index
 * @param[in] last_detection    `object_detection` for last index
 * @param[in] current_time      `time` for current index
 * @param[in] last_time         `time` for last index
 * @param[in] i                 current index
 */
void print_edge_detections(
    int current_detection,
    int last_detection,
    float current_time,
    float last_time,
    int i
) {
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

/**
 * @brief Print object detection intervals for the given sensor
 *
 * @param[in] p_sensor Given sensor
 */
void print_detection_intervals(const Sensor *p_sensor) {
    printf("Sensor %d detections: ", p_sensor->id);

    for (int i = 1; i < DATA_SIZE; i++) {
        int current_detection = p_sensor->object_detection[i];
        int last_detection    = p_sensor->object_detection[i - 1];

        float current_time = p_sensor->data[i].time;
        float last_time = p_sensor->data[i - 1].time;

        print_edge_detections(
            current_detection,
            last_detection,
            current_time,
            last_time,
            i
        );
    }

    printf("\n");
}

/**
 * @brief Print fused detection intervals for two sensors
 *
 * Fusing two object detection intervals results in another object detection
 * interval which is only 1 if both sensor object detections are also 1.
 *
 * @param[in] p_sensor_1 First sensor
 * @param[in] p_sensor_2 Second sensor
 */
void print_fused_intervals(const Sensor *p_sensor_1, const Sensor *p_sensor_2) {
    printf("Fused sensor detections: ");
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

        print_edge_detections(
            current_detection,
            last_detection,
            current_time,
            last_time,
            i
        );
    }

    printf("\n");
}

/**
 * @brief Print all sensor detection intervals for Sensor 1 and Sensor 2
 *
 * @param[in] p_sensor_1 Sensor 1
 * @param[in] p_sensor_2 Sensor 2
 */
void print_results(const Sensor *p_sensor_1, const Sensor *p_sensor_2) {
    print_detection_intervals(p_sensor_1);
    printf("\n");

    print_detection_intervals(p_sensor_2);
    printf("\n");

    print_fused_intervals(p_sensor_1, p_sensor_2);
}

int main(void) {
    Sensor sensor_1 = init_sensor(1, 0.8);
    Sensor sensor_2 = init_sensor(2, 0.7);

    read_sensor(&sensor_1, "../sensor1.txt");
    read_sensor(&sensor_2, "../sensor2.txt");

    print_results(&sensor_1, &sensor_2);
    
    return 0;
}
