#include <iostream>
#include <string>
using namespace std;

// Person class
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
};

// Student class (publicly inherits from Person)
class Student : public Person {
private:
    int studentID;  

public:
    Student(string n, int a, int id) : Person(n, a), studentID(id) {}
    
    void display() {
        cout << "Name: " << name << ", Age: " << age << ", ID: " << studentID << endl;
    }
};

int main() {
    Student student("Ammar", 20, 44810);
    Student student1("Afnan", 12, 15480);
    Student student2("Adam", 30, 48125);
    student.display();
    student1.display();
    student2.display();
    return 0;
}

/*
1.  Why protected instead of private?
    Protected members can be directly accessed by derived classes like Student. If they were private, Student could not access name and 
    age in its display() method.

2.  Effect of private attributes in Person
    If name and age were private, the Student class would get a compilation error in display() because it tries to access inaccessible members.

3.  Private inheritance consequence
    If Student used : private Person, the Person members would become private in Student. While the code would still compile 
    (since display() is part of Student), external code could no longer treat Student objects as Person objects 
    (e.g., Person* ptr = &student; would fail).
*/