#include "inc/rectangle.hpp"

Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

double Rectangle::area() const {
    return width * height;
}

void Rectangle::display() const {
    std::cout << "Rectangle with width " << width
              << " and height " << height
              << " has an area of " << area() << std::endl;
}
