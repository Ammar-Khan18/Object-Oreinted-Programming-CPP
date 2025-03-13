#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base Constructor\n"; }
    ~Base() { cout << "Base Destructor\n"; }
    // virtual ~Base() { cout << "Base Destructor\n"; } // Change this to virtual ~Base() and observe
};

class Derived : public Base {
public:
    Derived() { cout << "Derived Constructor\n"; }
    ~Derived() { cout << "Derived Destructor\n"; }
};

int main() {
    Base* obj = new Derived();
    delete obj;  // Observe what happens when Base's destructor is non-virtual
    return 0;
}