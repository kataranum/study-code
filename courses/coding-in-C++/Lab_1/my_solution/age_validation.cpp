#include <iostream>
#include <cstdint>
#include <string>

bool is_adult(uint8_t age) {
    return age >= 18;
}

bool is_senior(uint8_t age) {
    return age >= 65;
}

int main(void) {
    std::cout << "Please enter your age: " << std::endl;
    
    std::string age_string = "";
    std::getline(std::cin, age_string);

    uint8_t age = std::stoi(age_string);

    std::cout << "You are " << age_string << " years old." << std::endl;

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
