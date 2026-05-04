#include "vector2d.hpp"
#include <iostream>

Vector2D::Vector2D()
    : Vector2D(0, 0)
{ }

Vector2D::Vector2D(double x, double y)
    : x(x), y(y)
{ }

void Vector2D::print()
{
    std::cout << "Vector2D(" << this->x << ", " << this->y << ")" << std::endl;
}
