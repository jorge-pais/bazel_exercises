import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class CppRectangleGenerator {
    public static void main(String[] args) {
        try {
            generateHeaderFile();
            System.out.println("Generated: rectangle.hpp");
            generateCppFile();
            System.out.println("Generated: rectangle.cpp");
            System.out.println("C++ files for Rectangle class generated successfully.");
        } catch (IOException e) {
            System.err.println("Error while generating files: " + e.getMessage());
        }
    }

    private static void generateHeaderFile() throws IOException {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("rectangle.hpp"))) {
            writer.write("#ifndef RECTANGLE_H\n");
            writer.write("#define RECTANGLE_H\n\n");
            writer.write("#include \"project/cli/shape/inc/shape.hpp\"\n\n");
            writer.write("// Derived class: Rectangle\n");
            writer.write("class Rectangle : public Shape {\n");
            writer.write("private:\n");
            writer.write("    double width, height;\n\n");
            writer.write("public:\n");
            writer.write("    Rectangle(double w, double h);\n\n");
            writer.write("    double area() const override;\n");
            writer.write("    void display() const override;\n");
            writer.write("};\n\n");
            writer.write("#endif // RECTANGLE_H\n");
        }
    }

    private static void generateCppFile() throws IOException {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("rectangle.cpp"))) {
            writer.write("#include \"rectangle.hpp\"\n\n");
            writer.write("Rectangle::Rectangle(double w, double h) : width(w), height(h) {}\n\n");
            writer.write("double Rectangle::area() const {\n");
            writer.write("    return width * height;\n");
            writer.write("}\n\n");
            writer.write("void Rectangle::display() const {\n");
            writer.write("    std::cout << \"Rectangle with width \" << width\n");
            writer.write("              << \" and height \" << height\n");
            writer.write("              << \" has an area of \" << area() << std::endl;\n");
            writer.write("}\n");
        }
    }
}
