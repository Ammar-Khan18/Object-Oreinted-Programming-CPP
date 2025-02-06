#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Constructor
    Fraction(int num = 0, int den = 1);
    
    // Friend functions
    friend Fraction addFractions(const Fraction& f1, const Fraction& f2);
    friend Fraction multiplyFractions(const Fraction& f1, const Fraction& f2);
    
    // Display method
    void display() const;
};

#endif
