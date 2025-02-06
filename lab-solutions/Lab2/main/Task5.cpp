#include "../headers/MechanicShop.h"
#include <iostream>
int main() {
    // Create some cars with repair costs
    double repairs1[] = { 500.0, 405.99 };
    double repairs2[] = { 458.78, 259.99, 300.20 };

    Car car1("Suzuki", "Mehran", 2000, repairs1, 2);
    Car car2("Suzuki", "Alto", 1979, repairs2, 3);

    // Add cars to the mechanic shop
    MechanicShop shop;
    shop.addCar(car1);
    shop.addCar(car2);

    // Display all cars and their repair costs
    cout << "Cars in the shop:\n";
    shop.displayCars();

    // Merge repair costs of two cars
    Car mergedCar = car1 + car2;
    cout << "Merged Car Repair History:\n";
    cout << mergedCar << endl;

    return 0;
}