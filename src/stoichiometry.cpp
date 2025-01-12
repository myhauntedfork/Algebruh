#include "../include/stoichiometry.h"

const std::unordered_map<std::string, double> predefinedMolarMasses = {
    {"H2", 2.02}, {"O2", 32.00}, {"H2O", 18.02}, {"CO2", 44.01}, 
    {"CH4", 16.04}, {"N2", 28.02}, {"NH3", 17.03}, {"C6H12O6", 180.16},
    {"NaCl", 58.44}, {"KCl", 74.55}, {"HCl", 36.46},
    {"C2H6", 30.07}, {"C3H8", 44.10}, {"C4H10", 58.12}, // Add more as needed
};

double calculateMoles(double mass, double molarMass) {
    return mass / molarMass;
}

double calculateMass(double moles, double molarMass) {
    return moles * molarMass;
}

std::unordered_map<std::string, double> parseEquation(const std::string& equation) {
    std::unordered_map<std::string, double> molarRatios;
    std::istringstream stream(equation);
    std::string token;
    bool isProduct = false;

    while (stream >> token) {
        if (token == "->") {
            isProduct = true;
            continue;
        }

        double coefficient = 1.0;
        std::string formula;

        size_t pos = token.find_first_not_of("0123456789.");
        if (pos != 0) {
            coefficient = std::stod(token.substr(0, pos));
        }
        formula = token.substr(pos);

        molarRatios[formula] = isProduct ? coefficient : -coefficient;
    }

    return molarRatios;
}

double performStoichiometry(const std::string& equation, const std::string& knownSubstance, 
                            double knownMass, const std::string& targetSubstance, 
                            const std::unordered_map<std::string, Substance>& substances) {
    auto molarRatios = parseEquation(equation);

    if (molarRatios.find(knownSubstance) == molarRatios.end() ||
        molarRatios.find(targetSubstance) == molarRatios.end()) {
        throw std::invalid_argument("Substance not found in equation!");
    }

    double knownMoles = calculateMoles(knownMass, substances.at(knownSubstance).molarMass);
    double ratio = molarRatios[targetSubstance] / std::abs(molarRatios[knownSubstance]);
    double targetMoles = knownMoles * ratio;

    return calculateMass(targetMoles, substances.at(targetSubstance).molarMass);
}

void performStoichiometryInteractive() {
    std::unordered_map<std::string, Substance> substances;
    std::string equation, knownSubstance, targetSubstance;
    double knownMass;

    // Step 1: Input chemical equation
    std::cout << "Welcome to the Stoichiometry Calculator!\n";
    std::cout << "Step 1: Enter the balanced chemical equation.\n";
    std::cout << "Format: 'reactants -> products' (e.g., '2H2 + O2 -> 2H2O')\n";
    std::cout << "Equation: ";
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, equation);

    // Step 2: Automatically populate substances and their molar masses
    for (const auto& [formula, molarMass] : predefinedMolarMasses) {
        substances[formula] = {formula, molarMass};
    }

    // Step 3: Input known substance and its mass
    std::cout << "\nStep 2: Enter the known substance and its mass.\n";
    std::cout << "Known substance: ";
    std::cin >> knownSubstance;

    std::cout << "Mass of " << knownSubstance << " (grams): ";
    std::cin >> knownMass;

    // Step 4: Input target substance
    std::cout << "\nStep 3: Enter the target substance you want to calculate the mass for.\n";
    std::cout << "Target substance: ";
    std::cin >> targetSubstance;

    // Perform the calculation
    try {
        double targetMass = performStoichiometry(equation, knownSubstance, knownMass, targetSubstance, substances);
        std::cout << "\nResult:\n";
        std::cout << "Mass of " << targetSubstance << " produced: " << targetMass << " grams\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}
