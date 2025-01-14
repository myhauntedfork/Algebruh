#ifndef STOICHIOMETRY_H
#define STOICHIOMETRY_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <stdexcept>

struct Substance {
    std::string formula;
    double molarMass; // in grams per mole
};

double calculateMoles(double mass, double molarMass);
double calculateMass(double moles, double molarMass);
std::unordered_map<std::string, double> parseEquation(const std::string& equation);
double performStoichiometry(const std::string& equation, const std::string& knownSubstance, 
                            double knownMass, const std::string& targetSubstance, 
                            const std::unordered_map<std::string, Substance>& substances);
void performStoichiometryInteractive();

#endif