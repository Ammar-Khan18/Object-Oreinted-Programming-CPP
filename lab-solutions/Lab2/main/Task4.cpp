#include "../headers/Matrix.h"
#include <iostream>

int main() {
    // Create two 2x2 matrices
    Matrix mat1(1, 2, 3, 4); // Matrix 1: [1 2]
                            //            [3 4]
    Matrix mat2(5, 6, 7, 8); // Matrix 2: [5 6]
                            //            [7 8]

    // Display matrices
    cout << "Matrix 1:\n" << mat1;
    cout << "Matrix 2:\n" << mat2;
    // Perform addition
    Matrix sum = mat1 + mat2;
    cout << "Sum of Matrix 1 and Matrix 2:\n" << sum;

    // Perform subtraction
    Matrix diff = mat1 - mat2;
    cout << "Difference of Matrix 1 and Matrix 2:\n" << diff;

    // Perform multiplication
    Matrix product = mat1 * mat2;
    cout << "Product of Matrix 1 and Matrix 2:\n" << product;

    return 0;
}