// MechanicShop.h
#ifndef MECHANICSHOP_H
#define MECHANICSHOP_H

#include "Car.h"
#include <vector>

class MechanicShop {
private:
    vector<Car> cars; // List of cars in the shop

public:
    // Add a car to the shop
    void addCar(const Car& car);

    // Display all cars and their repair costs
    void displayCars() const;
};

#endif