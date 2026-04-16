#include "grades.hpp"

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

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

void print_line(int line_width) {
    for (int i = 0; i < line_width; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

std::string get_pass_status(char letter_grade) {
    switch (letter_grade) {
    case 'A':
    case 'B':
    case 'C':
        return "PASS";
    case 'D':
    case 'E':
        return "CONDITIONAL PASS";
    case 'F':
        return "FAIL";
    
    default:
        exit(1);
    }
}

void print_report(
    const std::string& name,
    uint8_t homework,
    uint8_t midterm,
    uint8_t final_exam,
    uint8_t final_grade,
    const std::string& letter_grade
) {
    const int LINE_WIDTH = 25;
    const int LEFT_WIDTH = 15;

    print_line(LINE_WIDTH);
    std::cout << "Student Report" << std::endl;
    print_line(LINE_WIDTH);

    std::cout << "Name: " << name << "\n" << std::endl;

    std::cout << "Scores" << std::endl;
    print_line(LINE_WIDTH);

    std::cout << std::left << std::setw(LEFT_WIDTH) << "Homework";
    std::cout << ": " << std::to_string(homework) << std::setprecision(2) << std::endl;;

    std::cout << std::left << std::setw(LEFT_WIDTH) << "Midterm";
    std::cout << ": " << std::to_string(midterm) << std::endl;

    std::cout << std::left << std::setw(LEFT_WIDTH) << "Final Exam";
    std::cout << ": " << std::to_string(final_exam) << std::endl;

    std::cout << std::endl;

    std::cout << std::left << std::setw(LEFT_WIDTH) << "Final Grade";
    std::cout << ": " << std::to_string(final_grade) << std::endl;
    
    std::cout << std::left << std::setw(LEFT_WIDTH) << "Letter Grade";
    std::cout << ": " << letter_grade << std::endl;

    std::string pass_status = get_pass_status(letter_grade[0]);
    std::cout << std::left << std::setw(LEFT_WIDTH) << "Status";
    std::cout << ": " << pass_status << std::endl;

    print_line(LINE_WIDTH);
}
