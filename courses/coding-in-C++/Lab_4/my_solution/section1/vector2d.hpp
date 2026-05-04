#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <ostream>

class Vector2D {
public:
    double x;
    double y;

public:
    Vector2D();
    Vector2D(double x, double y);

    void print() const;

    double magnitude() const;
    double magnitude(int precision) const;

    Vector2D operator+(const Vector2D& other) const;
    void operator+=(const Vector2D& other);

    // be careful with double equality. floating point numbers are approximated
    // values and may not be equal in certain situations even though we'd expect
    // them to be.
    bool operator==(const Vector2D& other) const;
    bool operator!=(const Vector2D& other) const;
};

Vector2D operator*(const Vector2D& vec, double scalar);
Vector2D operator*(double scalar, const Vector2D& vec);

std::ostream& operator<<(std::ostream& out, const Vector2D& vec);

#endif
