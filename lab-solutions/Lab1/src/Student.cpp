#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student() {
    cout << "Enter student ID: ";
    cin >> id;
    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter student CGPA: ";
    cin >> cgpa;
}

// Parameterized constructor
Student::Student(int id, const string& name, float cgpa)
    : id(id), name(name), cgpa(cgpa) {}

void Student::displayPrivateAttributes() const {
    cout << "ID: " << id << ", Name: " << name << ", CGPA: " << cgpa << endl;
}

int Student::getId() const {
    return id;
}

string Student::getName() const {
    return name;
}

float Student::getCgpa() const {
    return cgpa;
}