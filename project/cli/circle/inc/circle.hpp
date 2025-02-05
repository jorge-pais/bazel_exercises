#ifndef CIRCLE_H
#define CIRCLE_H

#include "project/cli/shape/inc/shape.hpp"

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r);

    double area() const override;
    void display() const override;
};

#endif // CIRCLE_H
