#include "shape/inc/shape.hpp"

#ifdef CONFIG_CIRCLE
#include "project/cli/circle/inc/circle.hpp"
#endif //CONFIG_CIRCLE

#ifdef CONFIG_RECTANGLE
#include "rectangle/inc/rectangle.hpp"
#endif //CONFIG_RECTANGLE

int main() {
    // Array of Shape pointers
    Shape* shapes[] = {
        new Shape(),             // Base class instance (will use default implementations)
#ifdef CONFIG_CIRCLE
        new Circle(5.0),         // Derived class instance
#endif //CONFIG_CIRCLE
#ifdef CONFIG_RECTANGLE
        new Rectangle(4.0, 6.0)  // Derived class instance
#endif //CONFIG_RECTANGLE
    };

    // Loop through and display their details
    for (Shape* shape : shapes) {
        shape->display();
    }

    // Clean up memory
    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
