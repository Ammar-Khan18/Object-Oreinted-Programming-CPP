#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor (takes input from the user)
Student::Student() {
    cout << "Enter student ID: ";
    cin >> id;
    cin.ignore(); // Clear the input buffer
    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter student CGPA: ";
    cin >> cgpa;
}

// Parameterized constructor
Student::Student(int id, const string& name, float cgpa)
    : id(id), name(name), cgpa(cgpa) {}

// Method to display private attributes
void Student::displayPrivateAttributes() const {
    cout << "ID: " << id << ", Name: " << name << ", CGPA: " << cgpa << endl;
}

// Getter for ID
int Student::getId() const {
    return id;
}

// Getter for name
string Student::getName() const {
    return name;
}

// Getter for CGPA
float Student::getCgpa() const {
    return cgpa;
}