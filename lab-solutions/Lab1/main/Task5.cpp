#include <iostream>
#include "../headers/InstanceCounter.h"
using namespace std;

int main() {
    cout << "Initial count: " << InstanceCounter::getCount() << endl;

    InstanceCounter obj1;
    cout << "Count after creating obj1: " << InstanceCounter::getCount() << endl;

    InstanceCounter obj2;
    cout << "Count after creating obj2: " << InstanceCounter::getCount() << endl;

    InstanceCounter obj3;
    cout << "Count after creating obj3: " << InstanceCounter::getCount() << endl;

    return 0;
}