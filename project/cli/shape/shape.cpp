#include "inc/shape.hpp"

double Shape::area() const {
    return 0.0; // Default implementation
}

void Shape::display() const {
    std::cout << "This is a generic shape with no specific properties." << std::endl;
}
