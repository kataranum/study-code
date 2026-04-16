#ifndef H_GRADES
#define H_GRADES

#include <cstdint>
#include <string>

void read_student_data(
    std::string& name,
    uint8_t& homework,
    uint8_t& midterm,
    uint8_t& final_exam
);

void calculate_grade(
    uint8_t homework,
    uint8_t midterm,
    uint8_t final_exam,
    uint8_t& final_grade,
    std::string& letter_grade
);

void print_report(
    const std::string& name,
    uint8_t homework,
    uint8_t midterm,
    uint8_t final_exam,
    uint8_t final_grade,
    const std::string& letter_grade
);

#endif
