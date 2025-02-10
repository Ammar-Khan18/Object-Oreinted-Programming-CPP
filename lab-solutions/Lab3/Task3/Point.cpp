#include <iostream>
#include <cmath> // For sqrt()

class Point {
private:
    int x, y;

public:
    // Constructor
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Overload '+' operator
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    // Overload '-' operator
    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    // Overload '==' operator
    bool operator==(const Point& other) const {
        return (x == other.x) && (y == other.y);
    }

    // Overload '=' operator
    Point& operator=(const Point& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    // Member function for scalar multiplication (Point * int)
    Point operator*(int scalar) const {
        return Point(x * scalar, y * scalar);
    }

    // Friend function for length calculation (only friend)
    friend double calculateLength(const Point& p);

    // Friend function for output formatting
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

// Calculate Euclidean length from origin (0,0)
double calculateLength(const Point& p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

// Overload << for printing
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "Point(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    // Create initial points
    Point p1(3, 4);
    Point p2(1, 2);
    Point p3(5, 5);

    // 1. Addition (+)
    Point sum = p1 + p2;
    std::cout << "p1 + p2 = " << sum << std::endl; // Point(4, 6)

    // 2. Subtraction (-)
    Point diff = p1 - p2;
    std::cout << "p1 - p2 = " << diff << std::endl; // Point(2, 2)

    // 3. Scalar multiplication (*)
    Point scaled = p1 * 3; // Point * int
    std::cout << "p1 * 3 = " << scaled << std::endl; // Point(9, 12)

    // 4. Equality check (==)
    std::cout << "Is p1 == p2? " << (p1 == p2 ? "Yes" : "No") << std::endl; // No

    // 5. Assignment (=)
    Point p4;
    p4 = p1; // Uses overloaded assignment
    std::cout << "After assignment, p4 = " << p4 << std::endl; // Point(3, 4)
    std::cout << "Is p4 == p1? " << (p4 == p1 ? "Yes" : "No") << std::endl; // Yes

    // 6. Modify p1 and show p4 remains unchanged
    p1 = Point(0, 0); // Reassign p1
    std::cout << "Modified p1 = " << p1 << std::endl; // Point(0, 0)
    std::cout << "p4 (unchanged) = " << p4 << std::endl; // Point(3, 4)

    // 7. Check inequality after modification
    std::cout << "Is p4 == p1? " << (p4 == p1 ? "Yes" : "No") << std::endl; // No

    // 8. Calculate lengths of points
    std::cout << "Length of p1: " << calculateLength(p1) << std::endl; // 0.0
    std::cout << "Length of p2: " << calculateLength(p2) << std::endl; // ~2.236
    std::cout << "Length of p3: " << calculateLength(p3) << std::endl; // ~7.071

    // 9. Chaining operations: (p3 - p1) + p2
    Point result = (p3 - p1) + p2;
    std::cout << "(p3 - p1) + p2 = " << result << std::endl; // Point(5-0 +1, 5-0 +2) = (6,7)

    return 0;
}