#include "vector2d.hpp"
#include <iostream>

int main(void) {
    Vector2D vec = Vector2D(1.0, 1.0);
    vec.print();

    double m = vec.magnitude();
    double m_rounded = vec.magnitude(2);

    std::cout << "Magnitude: " << m << std::endl;
    std::cout << "Rounded: " << m_rounded << std::endl;

    Vector2D vec2 = Vector2D(2.0, 0.0);

    std::cout << (vec + vec2) * 3.0 << std::endl;

    return 0;
}
