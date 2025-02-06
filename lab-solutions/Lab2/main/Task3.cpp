#include "../headers/Fraction.h"

int main() {
    // Create two Fraction objects
    Fraction f1(1, 2);  // 1/2
    Fraction f2(3, 4);  // 3/4

    // Display the original fractions
    std::cout << "Fraction 1: ";
    f1.display();
    std::cout << "Fraction 2: ";
    f2.display();

    // Add the fractions using the friend function
    Fraction sum = addFractions(f1, f2);
    std::cout << "Sum of the fractions: ";
    sum.display();

    // Multiply the fractions using the friend function
    Fraction product = multiplyFractions(f1, f2);
    std::cout << "Product of the fractions: ";
    product.display();

    return 0;
}
