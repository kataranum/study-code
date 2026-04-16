#ifndef H_GRADES
#define H_GRADES

#include <string>

void read_student_data(
    std::string& name,
    float& homework,
    float& midterm,
    float& final_exam
);

void calculate_grade(
    float homework,
    float midterm,
    float final_exam,
    float& final_grade,
    std::string& letter_grade
);

void print_report(
    const std::string& name,
    float homework,
    float midterm,
    float final_exam,
    float final_grade,
    const std::string& letter_grade
);

#endif
