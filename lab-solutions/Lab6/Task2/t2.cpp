#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Animal base class
class Animal {
protected:
    int legs;

public:
    Animal(int legs) : legs(legs) {
        cout << "Animal created with " << legs << " legs" << endl;
    }
    
    virtual void walk() {
        cout << "Animal is walking on " << legs << " legs" << endl;
    }
    
    virtual void eat() {
        cout << "Animal is eating" << endl;
    }
    
    virtual ~Animal() {
        cout << "Animal destroyed" << endl;
    }
};

// Pet interface
class Pet {
public:
    virtual string getName() = 0;
    virtual void setName(const string& name) = 0;
    virtual void play() = 0;
    virtual ~Pet() {}
};

// Spider class - inherits from Animal only
class Spider : public Animal {
public:
    Spider() : Animal(8) {
        cout << "Spider created" << endl;
    }
    
    void walk() override {
        cout << "Spider is crawling on 8 legs" << endl;
    }
    
    void eat() override {
        cout << "Spider is eating a fly" << endl;
    }
    
    ~Spider() override {
        cout << "Spider destroyed" << endl;
    }
};

// Cat class - inherits from Animal and implements Pet
class Cat : public Animal, public Pet {
private:
    string name;
    
public:
    Cat() : Animal(4) {
        cout << "Cat created" << endl;
    }
    
    Cat(const string& name) : Animal(4), name(name) {
        cout << "Cat created with name " << name << endl;
    }
    
    string getName() override {
        return name;
    }
    
    void setName(const string& name) override {
        this->name = name;
        cout << "Cat's name set to " << name << endl;
    }
    
    void play() override {
        cout << "Cat " << name << " is playing" << endl;
    }
    
    void walk() override {
        cout << "Cat " << name << " is walking on 4 legs" << endl;
    }
    
    void eat() override {
        cout << "Cat " << name << " is eating cat food" << endl;
    }
    
    ~Cat() override {
        cout << "Cat " << name << " destroyed" << endl;
    }
};

// Fish class - inherits from Animal and implements Pet
class Fish : public Animal, public Pet {
private:
    string name;
    
public:
    Fish() : Animal(0) {
        cout << "Fish created" << endl;
    }
    
    string getName() override {
        return name;
    }
    
    void setName(const string& name) override {
        this->name = name;
        cout << "Fish's name set to " << name << endl;
    }
    
    void play() override {
        cout << "Fish " << name << " is swimming around playfully" << endl;
    }
    
    void walk() override {
        cout << "Fish " << name << " cannot walk, it swims" << endl;
    }
    
    void eat() override {
        cout << "Fish " << name << " is eating fish food" << endl;
    }
    
    ~Fish() override {
        cout << "Fish " << name << " destroyed" << endl;
    }
};

int main() {
    cout << "=== Creating collections of Animals and Pets ===" << endl;
    
    // Create collections
    vector<Animal*> animals;
    vector<Pet*> pets;
    
    // Add objects to collections
    animals.push_back(new Spider());
    
    Cat* cat1 = new Cat("Tom");
    animals.push_back(cat1);
    pets.push_back(cat1);
    
    Fish* fish1 = new Fish();
    fish1->setName("Nemo");
    animals.push_back(fish1);
    pets.push_back(fish1);
    
    // Test methods on Animal collection
    cout << "\n=== Testing Animal collection methods ===" << endl;
    for (auto animal : animals) {
        animal->walk();
        animal->eat();
        cout << endl;
    }
    
    // Test methods on Pet collection
    cout << "=== Testing Pet collection methods ===" << endl;
    for (auto pet : pets) {
        cout << "Pet name: " << pet->getName() << endl;
        pet->play();
        cout << endl;
    }
    
    // Clean up
    cout << "=== Cleaning up ===" << endl;
    for (auto animal : animals) {
        delete animal;
    }
    
    cout << "\n=== Program completed ===" << endl;
    
    return 0;
}