import os
import sys
import argparse
from pathlib import Path

def generate_header_file(header_filename):
    with open(header_filename, "w") as file:
        file.write("#ifndef CIRCLE_H\n")
        file.write("#define CIRCLE_H\n\n")
        file.write("#include \"project/cli/shape/inc/shape.hpp\"\n\n")
        file.write("// Derived class: Circle\n")
        file.write("class Circle : public Shape {\n")
        file.write("private:\n")
        file.write("    double radius;\n\n")
        file.write("public:\n")
        file.write("    Circle(double r);\n\n")
        file.write("    double area() const override;\n")
        file.write("    void display() const override;\n")
        file.write("};\n\n")
        file.write("#endif // CIRCLE_H\n")
    print(f"Generated {header_filename}")


def generate_cpp_file(cpp_filename):
    with open(cpp_filename, "w") as file:
        file.write("#include \"inc/circle.hpp\"\n\n")
        file.write("Circle::Circle(double r) : radius(r) {}\n\n")
        file.write("double Circle::area() const {\n")
        file.write("    return 3.14159 * radius * radius;\n")
        file.write("}\n\n")
        file.write("void Circle::display() const {\n")
        file.write("    std::cout << \"Circle with radius \" << radius\n")
        file.write("              << \" has an area of \" << area() << std::endl;\n")
        file.write("}\n")
    print(f"Generated {cpp_filename}")


def parse_arguments(argv):
    parser = argparse.ArgumentParser()

    parser.add_argument(
        "-s",
        "--source-file",
        type=Path,
        required=True,
        help="Path to the source file",
    )

    parser.add_argument(
        "-i",
        "--header-file",
        type=Path,
        required=True,
        help="Path to the header file",
    )

    return parser.parse_args(argv)


def main(argv=None):
    args = parse_arguments(argv if argv is not None else sys.argv[1:])
    generate_header_file(args.header_file)
    generate_cpp_file(args.source_file)
    print("C++ files for Circle class generated successfully.")


if __name__ == "__main__":
    main(sys.argv[1:])
