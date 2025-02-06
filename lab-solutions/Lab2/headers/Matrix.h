#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

class Matrix {
private:
    int data[2][2]; // 2x2 matrix

public:
    // Constructor
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0);

    // Overload + for matrix addition
    Matrix operator+(const Matrix& other) const;

    // Overload - for matrix subtraction
    Matrix operator-(const Matrix& other) const;

    // Overload * for matrix multiplication
    Matrix operator*(const Matrix& other) const;

    // Overload << for output
    friend ostream& operator<<(ostream& os, const Matrix& mat);
};

#endif