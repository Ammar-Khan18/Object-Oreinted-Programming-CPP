#include <iostream>
#include "../headers/Circle.h"
using namespace std;

int main() {
    Circle circle;

    circle.setRadius(5.0);

    cout << "Radius: " << circle.getRadius() << endl;
    cout << "Circumference: " << circle.circumference() << endl;

    return 0;
}