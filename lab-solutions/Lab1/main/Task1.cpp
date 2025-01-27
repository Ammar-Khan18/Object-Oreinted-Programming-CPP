#include "../headers/Student.h"
#include <iostream>
using namespace std;

int main() {
    // Create a student object using the parameterized constructor
    Student student1(15976, "Ali", 3.2);

    // Add courses to the student's course list
    student1.courses.push_back("Mathematics");
    student1.courses.push_back("Physics");
    student1.courses.push_back("Computer Science");

    // Display private attributes using the displayPrivateAttributes method
    cout << "\nStudent details:" << endl;
    student1.displayPrivateAttributes();

    return 0;
}