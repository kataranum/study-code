#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,

    OP_UNDEFINED,
} Operation;

bool get_input_values(float* lhs, float* rhs);
Operation get_operation();
bool perform_calculation(float* result, float lhs, float rhs, Operation operation);

bool read_float(float* value);
bool read_char(char* c);

Operation char_to_operation(char operation);
char opertaion_to_char(Operation operation);

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

    Operation operation = get_operation();
    if (operation == OP_UNDEFINED) {
        printf("Operation is invalid.\n");
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
    if (! read_float(lhs)) {
        printf("Invalid input. Please input a decimal number.\n");
        return false;
    }

    printf("Input second number: ");
    if (! read_float(rhs)) {
        printf("Invalid input. Please input a decimal number.\n");
        return false;
    }

    return true;
}

Operation get_operation() {
    char op_char = '\0';
    printf("Select one operation [+, -, *, /]: ");
    if (! read_char(&op_char)) {
        printf("Invalid input. Please input a valid operation [+, -, *, /].\n");
        return OP_UNDEFINED;
    }

    return char_to_operation(op_char);
}

bool perform_calculation(float* result, float lhs, float rhs, Operation operation) {
    switch (operation) {
    case OP_ADD:
        return operation_add(result, lhs, rhs);
    case OP_SUB:
        return operation_sub(result, lhs, rhs);
    case OP_MUL:
        return operation_mul(result, lhs, rhs);
    case OP_DIV:
        return operation_div(result, lhs, rhs);
    default:
        printf("Undefined operation.\n");
        return false;
    }
}

bool read_float(float* value) {
    // read from stdin
    char buffer[64];
    if (! fgets(buffer, sizeof(buffer), stdin)) {
        return false;
    }

    // parse as float
    char* end;
    *value = strtof(buffer, &end);
    if (end == buffer) {
        return false;
    }

    return true;
}
bool read_char(char* c) {
    char buffer[2] = { '\0' };
    if (! fgets(buffer, sizeof(buffer), stdin)) {
        return false;
    }

    *c = buffer[0];
    return true;
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
    default:
        return OP_UNDEFINED;
    }
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
    default:
        return '\0';
    }
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
