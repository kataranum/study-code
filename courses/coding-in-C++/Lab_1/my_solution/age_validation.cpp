#include <iostream>
#include <cstdint>

bool is_adult(uint32_t age) {
    return age >= 18;
}

bool is_senior(uint32_t age) {
    return age >= 65;
}

int main(void) {
    std::cout << "Hello world" << std::endl;

    return 0;
}
