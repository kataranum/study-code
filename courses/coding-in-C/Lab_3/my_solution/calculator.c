#include <stdio.h>
#include <stdbool.h>

typedef enum {
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,

    OP_UNDEFINED,
} Operation;

bool get_input_values(float* lhs, float* rhs);
bool get_operation(Operation* operation);
bool perform_calculation(float* result, float lhs, float rhs, Operation operation);

Operation char_to_operation(char operation);
char opertaion_to_char(Operation operation);

bool is_valid_operation(char operation);

bool operation_add(float* result, float lhs, float rhs);
bool operation_sub(float* result, float lhs, float rhs);
bool operation_mul(float* result, float lhs, float rhs);
bool operation_div(float* result, float lhs, float rhs);

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

    float result = 0.0;

    if (! perform_calculation(&result, lhs, rhs, operation)) {
        printf("Calculation failed.\n");
        return -1;
    }
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

bool perform_calculation(float* result, float lhs, float rhs, char operation) {
    switch (operation) {
    case '+':
        return operation_add(result, lhs, rhs);
    case '-':
        return operation_sub(result, lhs, rhs);
    case '*':
        return operation_mul(result, lhs, rhs);
    case '/':
        return operation_div(result, lhs, rhs);
    }

    printf("Unknown operation.\n");
    return false;
}

Operation char_to_operation(char operation) {
    switch (operation) {
    case '+':
        return OP_ADD;
    case '-':
        return OP_SUB;
    case '*':
        return OP_MUL;
    case '/':
        return OP_DIV;
    }

    return OP_UNDEFINED;
}
char opertaion_to_char(Operation operation) {
    switch (operation) {
    case OP_ADD:
        return '+';
    case OP_SUB:
        return '-';
    case OP_MUL:
        return '*';
    case OP_DIV:
        return '/';
    }

    return '\0';
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

bool operation_add(float* result, float lhs, float rhs) {
    *result = lhs + rhs;
    return true;
}
bool operation_sub(float* result, float lhs, float rhs) {
    *result = lhs - rhs;
    return true;
}
bool operation_mul(float* result, float lhs, float rhs) {
    *result = lhs * rhs;
    return true;
}
bool operation_div(float* result, float lhs, float rhs) {
    // Checking floats with "==" is fine here because we're checking for
    // division by zero, so only when rhs is exactly zero.
    if (rhs == 0.0) {
        printf("Division by Zero.\n");
        return false;
    }

    *result = lhs / rhs;
    return true;
}
