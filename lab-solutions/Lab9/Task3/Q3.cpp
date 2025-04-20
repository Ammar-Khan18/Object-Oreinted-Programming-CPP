#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <functional>

// Employee class
class Employee {
    public:
        int id;
        std::string name;
        std::string department;
        double salary;
    
        // ✅ Default constructor
        Employee() : id(0), name(""), department(""), salary(0.0) {}
    
        // ✅ Param constructor
        Employee(int id, const std::string& name, const std::string& dept, double sal)
            : id(id), name(name), department(dept), salary(sal) {}
    };
    

// EmployeeManager class
class EmployeeManager {
private:
    std::map<int, Employee> employees;

public:
    // 1. Add employee
    void addEmployee(const Employee& emp) {
        employees[emp.id] = emp;
    }

    // 2. Delete employee by ID
    void deleteEmployee(int id) {
        if (employees.erase(id))
            std::cout << "Employee with ID " << id << " deleted.\n";
        else
            std::cout << "Employee with ID " << id << " not found.\n";
    }

    // 3. Display employees (with optional custom display)
    void displayEmployees(void (*displayFn)(const Employee&) = defaultDisplay) const {
        for (const auto& [id, emp] : employees) {
            displayFn(emp);
        }
    }

    // 4. Sort employees based on criteria using functor/lambda/fn pointer
    void sortEmployees(std::function<bool(const Employee&, const Employee&)> comparator) const {
        std::vector<Employee> empList;
        for (const auto& [id, emp] : employees)
            empList.push_back(emp);

        std::sort(empList.begin(), empList.end(), comparator);

        for (const auto& emp : empList) {
            defaultDisplay(emp);
        }
    }

    // 5. Find employees with salary above threshold (lambda)
    void findHighSalary(double threshold) const {
        std::cout << "\nEmployees with salary above " << threshold << ":\n";
        std::for_each(employees.begin(), employees.end(), [threshold](const auto& pair) {
            if (pair.second.salary > threshold)
                defaultDisplay(pair.second);
        });
    }

    // 6. Calculate average salary
    double averageSalary() const {
        if (employees.empty()) return 0.0;
        double total = std::accumulate(employees.begin(), employees.end(), 0.0,
            [](double sum, const auto& pair) {
                return sum + pair.second.salary;
            });
        return total / employees.size();
    }

    // 7. Static default display function
    static void defaultDisplay(const Employee& emp) {
        std::cout << "ID: " << emp.id
                  << ", Name: " << emp.name
                  << ", Department: " << emp.department
                  << ", Salary: " << emp.salary << '\n';
    }

    // Alternative display (name only)
    static void nameOnlyDisplay(const Employee& emp) {
        std::cout << "Employee Name: " << emp.name << '\n';
    }

    // Alternative display (department and salary)
    static void deptSalaryDisplay(const Employee& emp) {
        std::cout << "Dept: " << emp.department << ", Salary: " << emp.salary << '\n';
    }
};

int main() {
    EmployeeManager manager;

    // Add employees
    manager.addEmployee(Employee(101, "Alice", "HR", 55000));
    manager.addEmployee(Employee(102, "Bob", "Finance", 72000));
    manager.addEmployee(Employee(103, "Charlie", "IT", 67000));
    manager.addEmployee(Employee(104, "Diana", "IT", 90000));

    // Display all
    std::cout << "All Employees:\n";
    manager.displayEmployees();

    // Delete employee
    manager.deleteEmployee(102);

    // Display with custom function pointer
    std::cout << "\nDisplay (Name only):\n";
    manager.displayEmployees(EmployeeManager::nameOnlyDisplay);

    // Display (Dept + Salary only):
    std::cout << "\nDisplay (Department and Salary):\n";
    manager.displayEmployees(EmployeeManager::deptSalaryDisplay);

    // Sort by salary using lambda
    std::cout << "\nEmployees sorted by salary (descending):\n";
    manager.sortEmployees([](const Employee& a, const Employee& b) {
        return a.salary > b.salary;
    });

    // Sort by name using functor
    struct NameSorter {
        bool operator()(const Employee& a, const Employee& b) const {
            return a.name < b.name;
        }
    };

    std::cout << "\nEmployees sorted by name (ascending):\n";
    manager.sortEmployees(NameSorter());

    // Find high salary employees
    manager.findHighSalary(60000);

    // Average salary
    std::cout << "\nAverage Salary: " << manager.averageSalary() << '\n';

    return 0;
}