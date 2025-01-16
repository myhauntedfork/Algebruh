#include <iostream>
#include <cstdlib>
#include "../include/Math/area.h"
#include "../include/Math/quadratic.h"
#include "../include/Chemistry/stoichiometry.h"

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
                calculateRectangleArea();
                backToHome();
                break;
            case 2:
                clearTerminal();
                Quadratic::solveQuadraticEquation();
                backToHome();
                break;
            case 3:
                clearTerminal();
                performStoichiometryInteractive();
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
    std::cout << "========================\n";
    std::cout << "        Algebruh\n";
    std::cout << "========================\n";
    std::cout << "\n";
    std::cout << " MATH\n";
    std::cout << "------------------------\n";
    std::cout << " [1] Geometrey\n";
    std::cout << " [2] Quadratic\n";
    std::cout << "\n";
    std::cout << " CHEMISTRY\n";
    std::cout << "------------------------\n";
    std::cout << " [3] Stoichiometry\n";
    std::cout << "\n";
    std::cout << " OTHER\n";
    std::cout << "------------------------\n";
    std::cout << " [0] - Quit\n\n";
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