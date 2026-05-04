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

double Vector2D::magnitude(int precision)
{
    double factor = std::pow(10.0, precision);
    return std::round(this->magnitude() * factor) / factor;
}

Vector2D Vector2D::operator+(const Vector2D& other)
{
    *this += other;
    return *this;
}

void Vector2D::operator+=(const Vector2D& other)
{
    this->x += other.x;
    this->y += other.y;
}

std::ostream& operator<<(std::ostream& out, const Vector2D& vec)
{
    return out << "(" << vec.x << ", " << vec.y << ")";
}

Vector2D operator*(const Vector2D& vec, double scalar)
{
    return Vector2D(vec.x * scalar, vec.y * scalar);
}

Vector2D operator*(double scalar, const Vector2D& vec)
{
    return vec * scalar;
}
