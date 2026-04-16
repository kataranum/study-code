#include <iostream>
#include <cstdint>
#include <limits>
#include <string>

bool is_adult(uint8_t age) {
    return age >= 18;
}

bool is_senior(uint8_t age) {
    return age >= 65;
}

int main(void) {
    std::cout << "Please enter your age: " << std::endl;
    
    int age = 0;

    if (!(std::cin >> age)) {
        std::cout << "Invalid input" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }

    std::cout << "You are " << std::to_string(age) << " years old." << std::endl;

    if (is_senior(age)) {
        std::cout << "That means that you are a senior citizen." << std::endl;
    }
    else if (is_adult(age)) {
        std::cout << "That means that you are an adult" << std::endl;
    }
    else {
        std::cout << "That means that you are still a kid or teenager." << std::endl;
    }

    return 0;
}
