#include "../headers/DynamicArray.h"
#include <iostream>
using namespace std;

DynamicArray::DynamicArray(int size) : size(size) {
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = 0;  // Initialize array elements to zero
    }
}

// Deep Copy Constructor
DynamicArray::DynamicArray(const DynamicArray& other) : size(other.size) {
    arr = new int[size];  // Allocate new memory for deep copy
    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];  // Copy each element individually
    }
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
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

DynamicArray::~DynamicArray() {
    delete[] arr;  // Free allocated memory
}

void DynamicArray::set(int index, int value) {
    if (index >= 0 && index < size) {
        arr[index] = value;
    }
}

int DynamicArray::get(int index) const {
    return (index >= 0 && index < size) ? arr[index] : -1;
}

void DynamicArray::display() const {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
