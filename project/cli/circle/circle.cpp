#include "project/cli/circle/inc/circle.hpp"
#include <cmath>

Circle::Circle(double r) : radius(r) {}

double Circle::area() const {
    return M_PI * radius * radius;
}

void Circle::display() const {
    std::cout << "Circle with radius " << radius
              << " has an area of " << area() << std::endl;
}
