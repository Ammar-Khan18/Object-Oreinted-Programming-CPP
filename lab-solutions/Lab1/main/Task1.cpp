#include "Student.h"
#include <iostream>
using namespace std;

int main() {
    // Create a student object using the parameterized constructor
    Student student1(101, "John Doe", 3.8);

    // Add courses to the student's course list
    student1.courses.push_back("Mathematics");
    student1.courses.push_back("Physics");
    student1.courses.push_back("Computer Science");

    // Display the courses directly using the public field
    cout << "Courses enrolled by " << student1.getName() << ":" << endl;
    for (const auto& course : student1.courses) {
        cout << course << endl;
    }

    // Display private attributes using the displayPrivateAttributes method
    cout << "\nStudent details:" << endl;
    student1.displayPrivateAttributes();

    return 0;
}