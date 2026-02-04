#include <stdio.h>

int get_input_values(float* lhs, float* rhs);
int get_operation(char* operation);
float perform_calculation(float lhs, float rhs, char operation);

int main() {
    printf("Calculator program (will run only once :P)\n");

    float lhs = 0.0;
    float rhs = 0.0;
    if (! get_input_values(&lhs, &rhs)) {
        printf("Could not read input values.\n");
        return -1;
    }

    char operation = '\0';
    if (! get_operation(&operation)) {
        printf("Could not read operation.\n");
        return -1;
    }

    float result = perform_calculation(lhs, rhs, operation);
    printf("Result: %f\n", result);

    return 0;
}

int get_input_values(float* lhs, float* rhs) {
    float input_lhs = 0.0;
    float input_rhs = 0.0;

    printf("Input first number: ");
    scanf("%f", &input_lhs);

    // TODO: Check validity

    printf("Input second number: ");
    scanf("%f", &input_rhs);

    // TODO: Check validity

    *lhs = input_lhs;
    *rhs = input_rhs;

    return 0;
}

int get_operation(char* operation) {
    return -1;
}

float perform_calculation(float lhs, float rhs, char operation) {
    // TODO
    return 0.0;
}
