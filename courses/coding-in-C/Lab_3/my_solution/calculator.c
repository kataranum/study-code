#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef enum {
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,

    OP_UNDEFINED,
} Operation;

Operation get_operation();
float perform_calculation(float lhs, float rhs, Operation operation);

float read_float();
char read_char();

Operation char_to_operation(char operation);
char opertaion_to_char(Operation operation);

float operation_add(float lhs, float rhs);
float operation_sub(float lhs, float rhs);
float operation_mul(float lhs, float rhs);
float operation_div(float lhs, float rhs);

int main() {
    printf("Calculator program\n");

    printf("Enter first number: ");
    float lhs = read_float();

    if (isnanf(lhs)) {
        printf("Invalid number. Please enter a decimal number.\n");
        exit(1);
    }

    printf("Enter second number: ");
    float rhs = read_float();

    if (isnanf(lhs)) {
        printf("Invalid number. Please enter a decimal number.\n");
        exit(1);
    }

    Operation operation = get_operation();
    if (operation == OP_UNDEFINED) {
        printf("Invalid input. Please input a valid operation [+, -, *, /].\n");
        exit(1);
    }

    char op_char = opertaion_to_char(operation);

    float result = perform_calculation(lhs, rhs, operation);

    printf("The result of %f %c %f = %f\n", lhs, op_char, rhs, result);

    return 0;
}

Operation get_operation() {
    printf("Select one operation [+, -, *, /]: ");
    char op_char = read_char();

    return char_to_operation(op_char);
}

float perform_calculation(float lhs, float rhs, Operation operation) {
    switch (operation) {
    case OP_ADD:
        return operation_add(lhs, rhs);
    case OP_SUB:
        return operation_sub(lhs, rhs);
    case OP_MUL:
        return operation_mul(lhs, rhs);
    case OP_DIV:
        return operation_div(lhs, rhs);
    default:
        printf("Unhandled operation enum.\n");
        exit(1);
    }
}

float read_float() {
    // read from stdin
    char buffer[64];
    if (! fgets(buffer, sizeof(buffer), stdin)) {
        printf("Input failed.\n");
        return NAN;
    }

    // parse as float
    char* end;
    float value = strtof(buffer, &end);
    if (end == buffer) {
        printf("Could not parse '%s' as float.\n", buffer);
        return NAN;
    }

    return value;
}
char read_char() {
    char buffer[2] = { '\0' };
    if (! fgets(buffer, sizeof(buffer), stdin)) {
        return '\0';
    }

    return buffer[0];
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
        printf("Unhandled operation enum.\n");
        exit(1);
    }
}

float operation_add(float lhs, float rhs) {
    return lhs + rhs;
}
float operation_sub(float lhs, float rhs) {
    return lhs - rhs;
}
float operation_mul(float lhs, float rhs) {
    return lhs * rhs;
}
float operation_div(float lhs, float rhs) {
    // Checking floats with "==" is fine here because we're checking for
    // division by zero, so only when rhs is exactly zero.
    if (rhs == 0.0) {
        return NAN;
    }

    return lhs / rhs;
}
