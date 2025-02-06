#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray {
private:
    int* arr;
    int size;

public:
    DynamicArray(int size);
    DynamicArray(const DynamicArray& other);  // Deep Copy Constructor
    DynamicArray& operator=(const DynamicArray& other);  // Overloaded Assignment Operator

    ~DynamicArray();
    
    void set(int index, int value);
    int get(int index) const;
    void display() const;
};

#endif
