#include <iostream>
#include "../include/Physics/physics.h"

void solveKinematicEquasion() {
    double u, a, t, v;

    std::cout << "v = u + at\n\n";
    std::cout << "Enter initial velocity (u) in m/s: ";
    std::cin >> u;
    std::cout << "Enter acceleration (a) in m/s^2: ";
    std::cin >> a;
    std::cout << "Enter time (t) in seconds: ";
    std::cin >> t;

    v = u + a * t;

    std::cout << "Final velocity (v) = " << v << " m/s\n";
}
