#include "../headers/Fraction.h"

// Constructor
Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    if (denominator == 0) {
        std::cerr << "Error: Denominator cannot be zero!" << std::endl;
        denominator = 1;  // Set default value if denominator is 0
    }
}

// Friend function to add two fractions
Fraction addFractions(const Fraction& f1, const Fraction& f2) {
    int num = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    int den = f1.denominator * f2.denominator;
    return Fraction(num, den);  // Return the result as a new Fraction object
}

// Friend function to multiply two fractions
Fraction multiplyFractions(const Fraction& f1, const Fraction& f2) {
    int num = f1.numerator * f2.numerator;
    int den = f1.denominator * f2.denominator;
    return Fraction(num, den);  // Return the result as a new Fraction object
}

// Display method
void Fraction::display() const {
    std::cout << numerator << "/" << denominator << std::endl;
}
