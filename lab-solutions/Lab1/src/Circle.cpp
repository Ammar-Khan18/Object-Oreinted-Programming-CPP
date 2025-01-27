#include "Circle.h"
using namespace std;

// Set the radius
void Circle::setRadius(float r) {
    if (r > 0) {  // Ensure the radius is positive
        radius = r;
    } else {
        radius = 0;  // Default to 0 if the radius is invalid
    }
}

// Get the radius
float Circle::getRadius() const {
    return radius;
}

// Calculate and return the circumference
float Circle::circumference() const {
    return 2 * 3.14159 * radius;  // Circumference formula: 2 * π * radius
}