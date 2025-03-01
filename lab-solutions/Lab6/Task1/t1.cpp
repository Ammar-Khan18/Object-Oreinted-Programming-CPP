#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    double salary;
public:
    Employee(const string& n, double s) : name(n), salary(s) {}
    virtual double calculateBonus() = 0;
    virtual ~Employee() {}
};

class IPromotable {
public:
    virtual void promote(double newSalary) = 0;
    virtual ~IPromotable() {}
};

class Manager : public Employee, public IPromotable {
public:
    Manager(const string& n, double s) : Employee(n, s) {}
    
    double calculateBonus() override {
        // Managers receive a bonus of 20% of their salary
        return 0.2 * salary;
    }
    
    void promote(double newSalary) override {
        cout << "Manager " << name << " promoted from $" << salary << " to $" << newSalary << endl;
        salary = newSalary;
    }
};

class Programmer : public Employee, public IPromotable {
public:
    Programmer(const string& n, double s) : Employee(n, s) {}
    
    double calculateBonus() override {
        // Programmers receive a bonus of 15% of their salary
        return 0.15 * salary;
    }
    
    void promote(double newSalary) override {
        cout << "Programmer " << name << " promoted from $" << salary << " to $" << newSalary << endl;
        salary = newSalary;
    }
};

// Example usage
int main() {
    Manager manager("Aaron", 10000);
    Programmer programmer("Jonas", 5000);
    
    // Calculate and display bonuses
    cout << "Manager " << manager.calculateBonus() << endl;
    cout << "Programmer " << programmer.calculateBonus() << endl;
    
    // Promote employees
    manager.promote(20000);
    programmer.promote(10000);
    
    // Calculate and display new bonuses after promotion
    cout << "Manager's new bonus: $" << manager.calculateBonus() << endl;
    cout << "Programmer's new bonus: $" << programmer.calculateBonus() << endl;
    
    return 0;
}