#include "grades.hpp"

int main(void) {
    std::string name = "";
    uint8_t homework = 0;
    uint8_t midterm = 0;
    uint8_t final_exam = 0;
    uint8_t final_grade = 0;
    std::string letter_grade = "";

    read_student_data(name, homework, midterm, final_exam);
    calculate_grade(
        homework,
        midterm,
        final_exam,
        final_grade,
        letter_grade
    );
    print_report(
        name,
        homework,
        midterm,
        final_exam,
        final_grade,
        letter_grade
    );

    return 0;
}
