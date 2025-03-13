#include <iostream>
#include <string>
using namespace std;

// Base class Employee
class Employee {
protected:
    string name;
    string code;
    
public:
    Employee(string n, string c) : name(n), code(c) {}
};

// Derived class Consultant
class Consultant : virtual public Employee {
protected:
    int yearsOfExperience;
    
public:
    Consultant(string n, string c, int years) 
        : Employee(n, c), yearsOfExperience(years) {}
};

// Derived class Manager
class Manager : virtual public Employee {
protected:
    int noOfTeams;
    
public:
    Manager(string n, string c, int teams) 
        : Employee(n, c), noOfTeams(teams) {}
};

// Derived class ConsultantManager - inherits from both Consultant and Manager
class ConsultantManager : public Consultant, public Manager {
public:
    ConsultantManager(string n, string c, int years, int teams)
        : Employee(n, c), Consultant(n, c, years), Manager(n, c, teams) {}
    
    void Display() const {
        cout << "Name: " << name << endl;
        cout << "Code: " << code << endl;
        cout << "Years of Experience: " << yearsOfExperience << endl;
        cout << "Number of Teams: " << noOfTeams << endl;
    }
};

int main() {
    ConsultantManager obj("Ali", "S-123", 17, 5);
    obj.Display();
    return 0;
}