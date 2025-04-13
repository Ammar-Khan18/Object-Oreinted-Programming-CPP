// Generic Prgrame

#include <iostream>
#include <stdexcept>
using namespace std;
template <typename T>
class Complex {
private:
    T real, imag;

public:
    Complex(T r = 0, T i = 0) : real(r), imag(i) {}

    // Getters
    T getReal() const { return real; }
    T getImag() const { return imag; }

    // Addition
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Subtraction
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Multiplication
    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    // Division
    Complex operator/(const Complex& other) const {
        if (other.real == 0 && other.imag == 0)
            throw std::runtime_error("Division by zero");

        T denominator = other.real * other.real + other.imag * other.imag;
        T realPart = (real * other.real + imag * other.imag) / denominator;
        T imagPart = (imag * other.real - real * other.imag) / denominator;
        return Complex(realPart, imagPart);
    }

    // Print
    void display() const {
        std::cout << real << (imag >= 0 ? " + " : " - ") 
                  << std::abs(imag) << "i\n";
    }
};

// Specialized for int

template <>
class Complex<int> {
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    Complex operator/(const Complex& other) const {
        if (other.real == 0 && other.imag == 0)
            throw std::runtime_error("Division by zero");

        double denominator = other.real * other.real + other.imag * other.imag;
        double realPart = (real * other.real + imag * other.imag) / denominator;
        double imagPart = (imag * other.real - real * other.imag) / denominator;

        // Round results to nearest int
        return Complex(static_cast<int>(realPart + 0.5), static_cast<int>(imagPart + 0.5));
    }

    void display() const {
        std::cout << real << (imag >= 0 ? " + " : " - ") << std::abs(imag) << "i (int)\n";
    }
};

// Specialized for float

#include <iostream>
#include <cmath>

template <>
class Complex<float> {
private:
    float real, imag;

public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    Complex operator/(const Complex& other) const {
        float denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0.0f)
            throw std::runtime_error("Division by zero");

        float realPart = (real * other.real + imag * other.imag) / denominator;
        float imagPart = (imag * other.real - real * other.imag) / denominator;
        return Complex(realPart, imagPart);
    }

    void display() const {
        std::cout << real << (imag >= 0 ? " + " : " - ")
                  << std::fabs(imag) << "i (float)\n";
    }
};

int main() {
    // Integer complex numbers
    Complex<int> a(4, 3), b(2, -1);
    std::cout << "Integer Complex Numbers:\n";
    (a + b).display();
    (a - b).display();
    (a * b).display();
    (a / b).display();

    std::cout << "\nDouble Complex Numbers:\n";
    Complex<double> x(2.5, 3.2), y(1.1, -4.8);
    (x + y).display();
    (x - y).display();
    (x * y).display();
    (x / y).display();

    std::cout << "\nFloat Complex Numbers:\n";
    Complex<float> p(1.0f, 2.0f), q(3.0f, 4.0f);
    (p + q).display();
    (p - q).display();
    (p * q).display();
    (p / q).display();

    return 0;
}
