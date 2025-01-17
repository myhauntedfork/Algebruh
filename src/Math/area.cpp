#include <iostream>
#include <cmath>
#include "../include/Math/area.h"
#include "../include/Utils/constants.h"

void calculateRectangleArea() {
    double side1, side2;
    std::cout << "Enter length of sides 1 and 2 (separated by space): ";
    std::cin >> side1 >> side2;
    std::cout << "Answer: " << side1 * side2 << '\n';
}

void calculateCircleArea() {
    double radius;
    std::cout << "Enter length of diameter: ";
    std::cin >> radius;
    std::cout << "Answer: " << pow(radius, 2) * PI << '\n';
}

void calculateTriangleArea() {
    double base, height;
    std::cout << "Enter length of base and height (separated by space): ";
    std::cin >> base >> height;
    std::cout << "Answer: " << (base * height) / 2 << '\n';
}

void calculateRectangularPrismArea() {
    double length, width, height;
    std::cout << "Enter width, length, and height (separated by spaces): ";
    std::cin >> width >> length >> height;
    std::cout << "Answer: " << 2 * (width * length + length * height + width * height) << '\n';
}

void chooseAreaType() {
    int choice;
    std::cout << "Choose area type:\n";
    std::cout << "[1] Rectangle\n";
    std::cout << "[2] Circle\n";
    std::cout << "[3] Triangle\n";
    std::cout << "[4] Rectangular Prism\n";
    std::cout << ">> ";
    std::cin >> choice;
    switch (choice) {
        case 1:
            calculateRectangleArea();
            break;
        case 2:
            calculateCircleArea();
            break;
        case 3:
            calculateTriangleArea();
            break;
        case 4:
            calculateRectangularPrismArea();
            break;
        default:
            std::cout << "Invalid choice.\n";
    }
}