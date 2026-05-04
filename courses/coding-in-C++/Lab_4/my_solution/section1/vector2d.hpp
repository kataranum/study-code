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

    void print();

    double magnitude();
    double magnitude(int precision);

    Vector2D operator+(const Vector2D& other);
    void operator+=(const Vector2D& other);

    bool operator==(const Vector2D& other);
    bool operator!=(const Vector2D& other);
};

Vector2D operator*(const Vector2D& vec, double scalar);
Vector2D operator*(double scalar, const Vector2D& vec);

std::ostream& operator<<(std::ostream& out, const Vector2D& vec);

#endif
