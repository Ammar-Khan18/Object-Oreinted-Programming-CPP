#ifndef DYNAMICARRAY2_H
#define DYNAMICARRAY2_H

#include <iostream>

class DynamicArray2 {
private:
    int* arr;
    int size;

public:
    DynamicArray2(int size);
    DynamicArray2(const DynamicArray2& other);  // Deep Copy Constructor
    DynamicArray2& operator=(const DynamicArray2& other);  // Overloaded Assignment Operator
    ~DynamicArray2();
    
    void set(int index, int value);
    int get(int index) const;
    void display() const;
};

#endif
