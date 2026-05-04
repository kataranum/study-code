#include "vector2d.hpp"
#include <iostream>
#include <cmath>

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

double Vector2D::magnitude()
{
    return sqrt(this->x*this->x + this->y*this->y);
}

int Vector2D::magnitude(int precision)
{
    double factor = std::pow(10.0, precision);
    return std::round(this->magnitude() * factor) / factor;
}
