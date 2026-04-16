#include "grades.hpp"

int main(void) {
    std::string name = "";
    float homework = 0.0;
    float midterm = 0.0;
    float final_exam = 0.0;
    float final_grade = 0.0;
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
