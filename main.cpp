#include <iostream>
#include <cstdlib>
#include "include/area.h"
#include "include/quadratic.h"

void clearTerminal();
void backToHome();
void homeDisplay();

int main() {
    while (1) {
        int choice;
        clearTerminal();
        homeDisplay();
        std::cout << ">> ";
        std::cin >> choice;
        switch (choice) {            
            case 1:
                clearTerminal();
                AreaGeom::calculateRectangleArea();
                backToHome();
                break;
            case 2:
                clearTerminal();
                Quadratic::solveQuadraticEquation();
                backToHome();
                break;
            case 0:
                clearTerminal();
                return 0;
        }
    }
    return 1;
}

void homeDisplay() {
    std::cout << "--- Math Tools ---\n";
    std::cout << "[1] - Geometrey\n";
    std::cout << "[2] - Quadratic\n";
    std::cout << "\n[0] - Quit\n";
}

void backToHome() {
    std::cout << "\n\nPress Enter to go back to home...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    clearTerminal();
    homeDisplay();
}

void clearTerminal() {
    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif
}