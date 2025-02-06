#include "../headers/Matrix.h"

Matrix::Matrix(int a, int b, int c, int d) {
    data[0][0] = a;
    data[0][1] = b;
    data[1][0] = c;
    data[1][1] = d;
}

Matrix Matrix::operator+(const Matrix& other) const {
    return Matrix(
        data[0][0] + other.data[0][0],
        data[0][1] + other.data[0][1],
        data[1][0] + other.data[1][0],
        data[1][1] + other.data[1][1]
    );
}

Matrix Matrix::operator-(const Matrix& other) const {
    return Matrix(
        data[0][0] - other.data[0][0],
        data[0][1] - other.data[0][1],
        data[1][0] - other.data[1][0],
        data[1][1] - other.data[1][1]
    );
}

Matrix Matrix::operator*(const Matrix& other) const {
    return Matrix(
        data[0][0] * other.data[0][0] + data[0][1] * other.data[1][0],
        data[0][0] * other.data[0][1] + data[0][1] * other.data[1][1],
        data[1][0] * other.data[0][0] + data[1][1] * other.data[1][0],
        data[1][0] * other.data[0][1] + data[1][1] * other.data[1][1]
    );
}

ostream& operator<<(ostream& os, const Matrix& mat) {
    os << mat.data[0][0] << " " << mat.data[0][1] << endl;
    os << mat.data[1][0] << " " << mat.data[1][1] << endl;
    return os;
}