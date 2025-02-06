// Car.cpp
#include "../headers/Car.h"

// Constructor
Car::Car(string make, string model, int year, double* repairCosts, int repairCount)
    : make(make), model(model), year(year), repairCount(repairCount) {
    this->repairCosts = new double[repairCount];
    for (int i = 0; i < repairCount; i++) {
        this->repairCosts[i] = repairCosts[i];
    }
}

// Destructor
Car::~Car() {
    delete[] repairCosts;
}

// Copy Constructor
Car::Car(const Car& other)
    : make(other.make), model(other.model), year(other.year), repairCount(other.repairCount) {
    repairCosts = new double[repairCount];
    for (int i = 0; i < repairCount; i++) {
        repairCosts[i] = other.repairCosts[i];
    }
}

// Assignment Operator
Car& Car::operator=(const Car& other) {
    if (this != &other) {
        make = other.make;
        model = other.model;
        year = other.year;
        repairCount = other.repairCount;

        delete[] repairCosts; // Free existing memory
        repairCosts = new double[repairCount];
        for (int i = 0; i < repairCount; i++) {
            repairCosts[i] = other.repairCosts[i];
        }
    }
    return *this;
}

// Friend function to calculate total repair cost
double calculateTotalRepairCost(const Car& car) {
    double total = 0.0;
    for (int i = 0; i < car.repairCount; i++) {
        total += car.repairCosts[i];
    }
    return total;
}

// Overload + operator to merge repair costs
Car Car::operator+(const Car& other) const {
    int newRepairCount = repairCount + other.repairCount;
    double* newRepairCosts = new double[newRepairCount];

    for (int i = 0; i < repairCount; i++) {
        newRepairCosts[i] = repairCosts[i];
    }
    for (int i = 0; i < other.repairCount; i++) {
        newRepairCosts[repairCount + i] = other.repairCosts[i];
    }

    Car result(make, model, year, newRepairCosts, newRepairCount);
    delete[] newRepairCosts;
    return result;
}

// Overload << operator to display car details
ostream& operator<<(ostream& os, const Car& car) {
    os << "Car: " << car.make << " " << car.model << " (" << car.year << ")\n";
    os << "Repair Costs: ";
    for (int i = 0; i < car.repairCount; i++) {
        os << car.repairCosts[i] << " ";
    }
    os << "\nTotal Repair Cost: " << calculateTotalRepairCost(car) << endl;
    return os;
}