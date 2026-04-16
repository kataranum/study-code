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
    uint8_t& finalExam
) {

}

int main(void) {
    return 0;
}
