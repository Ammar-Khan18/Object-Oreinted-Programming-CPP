#include "../headers/DynamicArray2.h"

DynamicArray2::DynamicArray2(int size) : size(size) {
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = 0;  // Initialize array elements to zero
    }
}

// Deep Copy Constructor
DynamicArray2::DynamicArray2(const DynamicArray2& other) : size(other.size) {
    arr = new int[size];  // Allocate new memory for deep copy
    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];  // Copy each element individually
    }
}

// Overloaded Assignment Operator (Deep Copy)
DynamicArray2& DynamicArray2::operator=(const DynamicArray2& other) {
    if (this != &other) {  // Prevent self-assignment
        delete[] arr;  // Free existing memory

        size = other.size;
        arr = new int[size];  // Allocate new memory
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];  // Copy each element
        }
    }
    return *this;
}

DynamicArray2::~DynamicArray2() {
    delete[] arr;  // Free allocated memory
}

void DynamicArray2::set(int index, int value) {
    if (index >= 0 && index < size) {
        arr[index] = value;
    }
}

int DynamicArray2::get(int index) const {
    return (index >= 0 && index < size) ? arr[index] : -1;
}

void DynamicArray2::display() const {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
