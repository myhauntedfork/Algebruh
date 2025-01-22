#include <iostream>
#include <cstdlib>
#include "../include/Math/area.h"
#include "../include/Math/quadratic.h"
#include "../include/Chemistry/stoichiometry.h"
#include "../include/Physics/physics.h"

void clearTerminal();
void backToHome();
void homeDisplay();
void mathOptions();
void chemOptions();
void physicsOptions();
void startupDisplay();

int main() {
    startupDisplay();
    while (1) {
        int choice;
        clearTerminal();
        homeDisplay();
        std::cout << ">> ";
        std::cin >> choice;
        switch (choice) {            
            case 1:
                clearTerminal();
                mathOptions();
                backToHome();
                break;
            case 2:
                clearTerminal();
                chemOptions();
                backToHome();
                break;
            case 3:
                clearTerminal();
                physicsOptions();
                backToHome();
                break;
            case 0:
                clearTerminal();
                return 0;
            default:
                clearTerminal();
                std::cout << choice << " is an invalid option.\n";
                backToHome();
                break;
        }
    }
    return 1;
}

void startupDisplay() {
    int choice;
    std::cout << "          _            _                _\n";
    std::cout << "    /\\   | |          | |              | |\n";
    std::cout << "   /  \\  | | __ _  ___| |__  _ __ _   _| |__\n";
    std::cout << "  / /\\ \\ | |/ _` |/ _ \\ '_ \\| '__| | | | '_ \\\n";
    std::cout << " / ____ \\| | (_| |  __/ |_) | |  | |_| | | | |\n";
    std::cout << "/_/    \\_\\_|\\__, |\\___|_.__/|_|   \\__,_|_| |_|\n";
    std::cout << "             __/ |\n";
    std::cout << "            |___/\n";
    std::cout << "\n[1] Start\n";
    std::cout << "[0] Quit\n>> ";
    std::cin >> choice;
    if (choice == 1) {
        homeDisplay();
    } else {
        exit(0);
    }                                                          
}

void homeDisplay() {
    std::cout << "[1] MATH\n";
    std::cout << "[2] CHEMISTRY\n";
    std::cout << "[3] PHYSICS\n";
    std::cout << "[0] Quit\n\n";
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

void mathOptions() {
    int choice;
    std::cout << "[1] Geometry\n";
    std::cout << "[2] Quardratic Equasion\n>> ";
    std::cin >> choice;
    switch (choice) {
        case 1:
            clearTerminal();
            chooseAreaType();
            backToHome();
            break;
        case 2:
            clearTerminal();
            solveQuadraticEquation();
            backToHome();
            break;
        default:
            clearTerminal();
            std::cout << choice << " is an invalid option.\n";
            backToHome();
            break;
    }
}

void chemOptions() {
    int choice;
    std::cout << "[1] Stoichiometry\n>> ";
    std::cin >> choice;
    switch (choice) {
        case 1:
            clearTerminal();
            performStoichiometryInteractive();
            backToHome();
            break;
        default:
            clearTerminal();
            std::cout << choice << " is an invalid option.\n";
            backToHome();
            break;
    }
}

void physicsOptions() {
    int choice;
    std::cout << " [1] Kinematic Equasion\n";
    std::cout << " [2] Gravitational Force\n>> ";
    std::cin >> choice;
    switch (choice) {
        case 1:
            clearTerminal();
            solveKinematicEquasion();
            backToHome();
            break;
        case 2:
            clearTerminal();
            calculateGravitationalForce();
            backToHome();
            break;
        default:
            clearTerminal();
            std::cout << choice << " is an invalid option.\n";
            backToHome();
            break;
    }
}
