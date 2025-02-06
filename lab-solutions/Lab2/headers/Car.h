// Car.h
#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string make;
    string model;
    int year;
    double* repairCosts; // Dynamically allocated array for repair costs
    int repairCount;     // Number of repairs

public:
    // Constructor
    Car(string make, string model, int year, double* repairCosts = nullptr, int repairCount = 0);

    // Destructor
    ~Car();

    // Copy Constructor
    Car(const Car& other);

    // Assignment Operator
    Car& operator=(const Car& other);

    // Friend function to calculate total repair cost
    friend double calculateTotalRepairCost(const Car& car);

    // Overload + operator to merge repair costs
    Car operator+(const Car& other) const;

    // Overload << operator to display car details
    friend ostream& operator<<(ostream& os, const Car& car);
};

#endif