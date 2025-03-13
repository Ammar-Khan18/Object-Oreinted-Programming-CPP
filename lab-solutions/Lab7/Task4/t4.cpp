#include <iostream>
#include <typeinfo>
#include <exception>
#include <memory>

// Base class with virtual function and virtual destructor
class Shape {
public:
    virtual void draw() const {
        std::cout << "Drawing a generic shape" << std::endl;
    }
    
    virtual ~Shape() {
        std::cout << "Shape destructor called" << std::endl;
    }
};

// Derived class
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a circle" << std::endl;
    }
    
    void calculateArea(double radius) const {
        std::cout << "Circle area: " << 3.14159 * radius * radius << std::endl;
    }
    
    ~Circle() override {
        std::cout << "Circle destructor called" << std::endl;
    }
};

// Another derived class (not a Circle)
class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a rectangle" << std::endl;
    }
    
    ~Rectangle() override {
        std::cout << "Rectangle destructor called" << std::endl;
    }
};

int main() {
    // Example 1: Failed cast with reference types
    try {
        std::cout << "Example 1: Failed dynamic_cast with references" << std::endl;
        
        // Create a Rectangle object
        Shape* shapePtr = new Rectangle();
        shapePtr->draw();  // Will call Rectangle::draw()
        
        // Attempt to cast to Circle& - this will fail
        std::cout << "Attempting to cast Rectangle to Circle&..." << std::endl;
        Circle& circleRef = dynamic_cast<Circle&>(*shapePtr);  // This will throw std::bad_cast
        
        // This code will not be reached if the cast fails
        circleRef.calculateArea(5.0);
        
        delete shapePtr;
    }
    catch (const std::bad_cast& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
        std::cout << "Cast failed: Cannot convert to Circle&" << std::endl;
    }
    
    std::cout << "\n------------------------------\n" << std::endl;
    
    // Example 2: Safer approach with pointer types
    std::cout << "Example 2: Safe dynamic_cast with pointers" << std::endl;
    
    // Create objects for demonstration
    std::unique_ptr<Shape> circle = std::make_unique<Circle>();
    std::unique_ptr<Shape> rectangle = std::make_unique<Rectangle>();
    
    // Successful cast
    Circle* circlePtr = dynamic_cast<Circle*>(circle.get());
    if (circlePtr) {
        std::cout << "Cast successful: Shape is a Circle" << std::endl;
        circlePtr->calculateArea(5.0);
    }
    else {
        std::cout << "Cast failed: Shape is not a Circle" << std::endl;
    }
    
    // Failed cast
    Circle* rectangleAsCircle = dynamic_cast<Circle*>(rectangle.get());
    if (rectangleAsCircle) {
        std::cout << "Cast successful: Shape is a Circle" << std::endl;
        rectangleAsCircle->calculateArea(5.0);
    }
    else {
        std::cout << "Cast failed: Shape is not a Circle" << std::endl;
    }
    
    return 0;
}