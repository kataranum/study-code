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

    // If std::cin writes into a uint8_t we get some weird values
    int age_input = 0;
    
    while (true) {
        std::cout << "Please enter your age: " << std::endl;

        if (!(std::cin >> age_input)) {
            std::cout << "Invalid input" << std::endl;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }

        if (age_input < 0) {
            std::cout << "Age cannot be negative" << std::endl;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }

        if (age_input > 255) {
            std::cout << "Age is way too high" << std::endl;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }

        break;
    }

    // alternative data type: uint_fast8_t if we care more about speed than
    // memory consumption
    uint8_t age = static_cast<uint8_t>(age_input);

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
