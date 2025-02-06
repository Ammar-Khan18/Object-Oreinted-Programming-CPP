#include "../headers/DynamicArray.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Creating Array 1" << endl;
    DynamicArray arr1(5);
    arr1.set(0, 10);
    arr1.set(1, 20);
    arr1.set(2, 30);
    arr1.set(3, 40);
    arr1.set(4, 50);
    arr1.display();
    cout << "Copying Array 1 to Array 2..." << endl;
    DynamicArray arr2 = arr1;
    arr2.display();
    cout << "Modifying Array 1..." << endl;
    arr1.set(0, 11);
    arr1.set(1, 22);
    arr1.set(2, 33);
    arr1.set(3, 44);
    arr1.set(4, 55);
    arr1.display();
    cout<<"Copying Array 1 to Array 3..." << endl;
    DynamicArray arr3(5);
    arr3 = arr1;
    cout << "Array 2 after the modifying Array 1:" << endl;
    arr2.display();
    cout << "Modifying Array 1..." << endl;
    arr1.set(0, 66);
    arr1.set(1, 77);
    arr1.set(2, 88);
    arr1.set(3, 99);
    arr1.set(4, 00);
    arr1.display();
    cout << "Array 3 after the modifying Array 1:" << endl;
    arr3.display();
    return 0;
}
