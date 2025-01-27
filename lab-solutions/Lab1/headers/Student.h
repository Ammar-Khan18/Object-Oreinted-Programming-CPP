#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
using namespace std;

class Student {
private:
    int id;      
    string name; 
    float cgpa;  

public:
    vector<string> courses; // Public field to store course names

    Student();

    Student(int id, const string& name, float cgpa);

    void displayPrivateAttributes() const;

    int getId() const;
    string getName() const;
    float getCgpa() const;
};

#endif // STUDENT_H