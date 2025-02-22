#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

class Animal {
protected:
    std::string name;
    int age;

public:
    Animal(const std::string& n, int a) : name(n), age(a) {
        if (a < 0) {
            throw std::invalid_argument("Age cannot be negative");
        }
    }

    virtual void makeSound() const {
        std::cout << name << " makes a generic animal sound!\n";
    }

    virtual void displayInfo() const {
        std::cout << name << " (Age: " << age << ")\n";
    }

    virtual ~Animal() {}
};

class Lion : public Animal {
public:
    Lion(const std::string& n, int a) : Animal(n, a) {}

    void makeSound() const override {
        std::cout << name << " roars loudly!\n";
    }

    void displayInfo() const override {
        std::cout << "Lion ";
        Animal::displayInfo();
    }
};

class Snake : public Animal {
    bool venomous;

public:
    Snake(const std::string& n, int a, bool v) : Animal(n, a), venomous(v) {}

    void makeSound() const override {
        std::cout << name << " hisses softly!\n";
    }

    void displayInfo() const override {
        std::cout << "Snake ";
        Animal::displayInfo();
        std::cout << "Venomous: " << (venomous ? "Yes" : "No") << "\n";
    }
};

class Monkey : public Animal {
public:
    Monkey(const std::string& n, int a) : Animal(n, a) {}

    void makeSound() const override {
        std::cout << name << " chatters excitedly!\n";
    }

    void displayInfo() const override {
        std::cout << "Monkey ";
        Animal::displayInfo();
    }
};

int main() {
    std::vector<Animal*> animals;

    try {
        animals.push_back(new Lion("Simba", 5));
        animals.push_back(new Snake("Viper", 3, true));
        animals.push_back(new Monkey("George", 4));
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error creating animal: " << e.what() << "\n";
        return 1;
    }

    for (Animal* animal : animals) {
        animal->makeSound();
        animal->displayInfo();
        delete animal;
    }

    return 0;
}