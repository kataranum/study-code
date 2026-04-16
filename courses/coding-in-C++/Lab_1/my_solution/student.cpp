#include <ios>
#include <iostream>
#include <string>
#include <cstdint>
#include <limits>

std::string user_input_string(const std::string& prompt) {
    while (true) {
        std::cout << prompt << std::endl;

        std::string input = "";
        if (!std::getline(std::cin, input)) {
            std::cout << "Invalid input" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        };

        return input;
    }
}

int user_input_num(const std::string& prompt, int lower, int upper) {
    while (true) {
        std::cout << prompt << std::endl;

        int input = 0;

        if (!(std::cin >> input)) {
            std::cout << "Invalid input" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }
        std::cin.ignore(); // ignore trailing return char

        if (input < lower || input > upper) {
            std::cout << "Value is outside valid range (" << lower << ", " << upper << ")" << std::endl;

            continue;
        }

        return input;
    }
}

void read_student_data(
    std::string& name,
    uint8_t& homework,
    uint8_t& midterm,
    uint8_t& final_exam
) {
    name = user_input_string("Enter student name: ");
    homework = static_cast<uint8_t>(
        user_input_num("Homework score: ", 0, 100)
    );
    midterm = static_cast<uint8_t>(
        user_input_num("Midterm score: ", 0, 100)
    );
    final_exam = static_cast<uint8_t>(
        user_input_num("Final exam score: ", 0, 100)
    );
}

void calculate_grade(
    uint8_t homework,
    uint8_t midterm,
    uint8_t final_exam,
    uint8_t& final_grade,
    std::string& letter_grade
) {
    uint16_t w_homework = (uint16_t)homework * 40;
    uint16_t w_midterm = (uint16_t)midterm * 25;
    uint16_t w_final_exam = (uint16_t)final_exam * 35;

    final_grade = static_cast<uint8_t>(
        (w_homework + w_midterm + w_final_exam) / 100
    );

    if (final_grade >= 90) {
        letter_grade = 'A';
    }
    else if (final_grade >= 80) {
        letter_grade = 'B';
    }
    else if (final_grade >= 70) {
        letter_grade = 'C';
    }
    else if (final_grade >= 60) {
        letter_grade = 'D';
    }
    else if (final_grade >= 50) {
        letter_grade = 'E';
    }
    else {
        letter_grade = 'F';
    }
}

int main(void) {
    return 0;
}
