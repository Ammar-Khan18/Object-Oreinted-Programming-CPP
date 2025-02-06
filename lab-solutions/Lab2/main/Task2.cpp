#include "../headers/DynamicArray2.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Creating Array 1" << endl;
    DynamicArray2 arr1(5);
    arr1.set(0, 10);
    arr1.set(1, 20);
    arr1.set(2, 30);
    arr1.set(3, 40);
    arr1.set(4, 50);
    arr1.display();
    cout << "Copying Array..." << endl;
    DynamicArray2 arr2(5);
    arr2 = arr1;
    arr2.display();
    cout << "Modifying Array 1..." << endl;
    arr1.set(0, 11);
    arr1.set(1, 22);
    arr1.set(2, 33);
    arr1.set(3, 44);
    arr1.set(4, 55);
    arr1.display();
    cout << "Array 2 after the modifying Array 1:" << endl;
    arr2.display();
    return 0;
}