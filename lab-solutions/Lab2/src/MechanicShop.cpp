// MechanicShop.cpp
#include "../headers/MechanicShop.h"

// Add a car to the shop
void MechanicShop::addCar(const Car& car) {
    cars.push_back(car);
}

// Display all cars and their repair costs
void MechanicShop::displayCars() const {
    for (const Car& car : cars) {
        cout << car << endl;
    }
}