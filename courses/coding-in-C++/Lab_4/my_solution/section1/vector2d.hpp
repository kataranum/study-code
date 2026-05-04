#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D {
public:
    double x;
    double y;

public:
    Vector2D();
    Vector2D(double x, double y);

    void print();

    double magnitude();
    int magnitude(int precision);
};

#endif
