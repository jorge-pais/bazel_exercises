#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape {
public:
    virtual ~Shape() = default; // Virtual destructor

    // Virtual function with a default implementation
    virtual double area() const;

    // Virtual function with a default implementation
    virtual void display() const;
};

#endif // SHAPE_H
