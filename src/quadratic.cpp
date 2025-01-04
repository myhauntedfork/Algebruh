#include <iostream>
#include <cmath>
#include <limits>
#include "../include/quadratic.h"

void Quadratic::solveQuadraticEquation() {
    double a, b, c;
    std::cout << "Enter coefficients a, b, and c (separated by spaces): ";
    std::cin >> a >> b >> c;

    if (a == 0) {
        if (b != 0) {
            double root = -c / b;
            std::cout << "This is a linear equation. Root: " << root << '\n';
        } else {
            std::cout << "Invalid equation. Both a and b cannot be zero.\n";
        }
        return;
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
        double root2 = (-b - std::sqrt(discriminant)) / (2 * a);
        std::cout << "Two distinct real roots:\n";
        std::cout << "Root 1: " << root1 << '\n';
        std::cout << "Root 2: " << root2 << '\n';
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        std::cout << "One real root (double root): " << root << '\n';
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = std::sqrt(-discriminant) / (2 * a);
        std::cout << "Two complex roots:\n";
        std::cout << "Root 1: " << realPart << " + " << imaginaryPart << "i\n";
        std::cout << "Root 2: " << realPart << " - " << imaginaryPart << "i\n";
    }
}
