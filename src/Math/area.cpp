#include <iostream>
#include <cmath>
#include "../include/Math/area.h"

void AreaGeom::calculateRectangleArea() {
    double side1, side2;
    std::cout << "Enter length of sides 1 and 2 (separated by space): ";
    std::cin >> side1 >> side2;
    std::cout << "Answer: " << side1 * side2 << '\n';
}

void AreaGeom::calculateCircleArea() {
    double radius;
    std::cout << "Enter length of diameter: ";
    std::cin >> radius;
    std::cout << "Answer: " << pow(radius, 2) * 3.14159 << '\n';
}

void AreaGeom::calculateTriangleArea() {
    double base, height;
    std::cout << "Enter length of base and height (separated by space): ";
    std::cin >> base >> height;
    std::cout << "Answer: " << (base * height) / 2 << '\n';
}

void AreaGeom::calculateRectangularPrismArea() {
    double length, width, height;
    std::cout << "Enter width, length, and height (separated by spaces): ";
    std::cin >> width >> length >> height;
    std::cout << "Answer: " << 2 * (width * length + length * height + width * height) << '\n';
}

