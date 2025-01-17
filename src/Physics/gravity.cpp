#include <iostream>
#include "../include/Physics/physics.h"
#include "../include/Utils/constants.h"

void calculateGravitationalForce() {
    double m1, m2, r, F;

    std::cout << "Enter mass of object 1 (m1) in kg: ";
    std::cin >> m1;
    std::cout << "Enter mass of object 2 (m2) in kg: ";
    std::cin >> m2;
    std::cout << "Enter distance (r) between the objects in meters: ";
    std::cin >> r;

    F = G * m1 * m2 / (r * r);

    std::cout << "Gravitational Force (F) = " << F << " N\n";
}