#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "project/cli/shape/inc/shape.hpp"

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h);

    double area() const override;
    void display() const override;
};

#endif // RECTANGLE_H
