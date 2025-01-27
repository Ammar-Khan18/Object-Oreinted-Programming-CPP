#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
using namespace std;

class Student {
private:
    int id;      // Student ID
    string name; // Student name
    float cgpa;  // Student CGPA

public:
    vector<string> courses; // Public field to store course names

    // Default constructor (takes input from the user)
    Student();

    // Parameterized constructor
    Student(int id, const string& name, float cgpa);

    // Method to display private attributes
    void displayPrivateAttributes() const;

    // Getters for private attributes
    int getId() const;
    string getName() const;
    float getCgpa() const;
};

#endif // STUDENT_H