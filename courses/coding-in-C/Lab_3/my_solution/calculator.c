#include <stdio.h>
#include <stdbool.h>

int get_input_values(float* lhs, float* rhs);
int get_operation(char* operation);
float perform_calculation(float lhs, float rhs, char operation);

bool is_valid_operation(char operation);

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
    printf("The result of %f %c %f = %f\n", lhs, operation, rhs, result);

    return 0;
}

bool get_input_values(float* lhs, float* rhs) {
    printf("Input first number: ");
    if (scanf(" %f", lhs) < 1) {
        printf("Invalid input. Please input a decimal number.\n");
        return false;
    }

    printf("Input second number: ");
    if (scanf(" %f", rhs) < 1) {
        printf("Invalid input. Please input a decimal number.\n");
        return false;
    }

    return true;
}

bool get_operation(char* operation) {
    printf("Select one operation [+, -, *, /]: ");
    if (scanf(" %c", operation) < 1) {
        printf("Invalid input. Please input a valid operation [+, -, *, /].\n");
        return false;
    }

    if (! is_valid_operation(operation)) {
        printf("'%c' is not a valid operation.\n");
        return false;
    }

    return true;
}

float perform_calculation(float lhs, float rhs, char operation) {
    switch (operation) {
    case '+':
        return lhs + rhs;
    case '-':
        return lhs - rhs;
    case '*':
        return lhs * rhs;
    case '/':
        return lhs / rhs;
    }

    // TODO: Print error message if operation is invalid
    return 0.0;
}

bool is_valid_operation(char operation) {
    char valid_operations[] = { '+', '-', '*', '/' };
    int operations_len = sizeof(valid_operations) / sizeof(valid_operations[0]);

    for (int i = 0; i < operations_len; i++) {
        if (operation == valid_operations[i]) {
            return true;
        }
    }

    return false;
}
