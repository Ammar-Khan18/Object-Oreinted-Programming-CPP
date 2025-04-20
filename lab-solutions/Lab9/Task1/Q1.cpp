#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

// Structure to hold element data
struct Element {
    std::string name;
    std::string symbol;
    int atomicNumber;
};

// Functor for sorting
class ElementSorter {
public:
    bool operator()(const Element& a, const Element& b) const {
        if (a.atomicNumber != b.atomicNumber)
            return a.atomicNumber < b.atomicNumber;
        return a.name < b.name;
    }
};

// Functor for filtering long names
class LongNameFilter {
public:
    bool operator()(const Element& e) const {
        return e.name.length() > 5;
    }
};

int main() {
    // Step 1: Initialize element data
    std::vector<Element> elements = {
        {"Hydrogen", "H", 1},
        {"Helium", "He", 2},
        {"Carbon", "C", 6},
        {"Oxygen", "O", 8},
        {"Neon", "Ne", 10},
        {"Calcium", "Ca", 20},
        {"Sodium", "Na", 11},
        {"Aluminum", "Al", 13}
    };

    // Step 2: Get minimum atomic number from user
    int minAtomicNumber;
    std::cout << "Enter minimum atomic number to filter: ";
    std::cin >> minAtomicNumber;

    // Filter elements based on min atomic number
    std::vector<Element> filteredElements;
    std::copy_if(elements.begin(), elements.end(), std::back_inserter(filteredElements),
                 [minAtomicNumber](const Element& e) {
                     return e.atomicNumber >= minAtomicNumber;
                 });

    // Step 3: Sort using functor
    std::sort(filteredElements.begin(), filteredElements.end(), ElementSorter());

    // Step 4: Count names longer than 5 characters
    int longNameCount = std::count_if(filteredElements.begin(), filteredElements.end(), LongNameFilter());

    // Step 5: Transform symbols to uppercase using lambda
    std::vector<std::string> uppercaseSymbols;
    std::transform(filteredElements.begin(), filteredElements.end(), std::back_inserter(uppercaseSymbols),
                   [](const Element& e) {
                       std::string upper = e.symbol;
                       std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
                       return upper;
                   });

    // Output results
    std::cout << "\nFiltered and Sorted Elements:\n";
    for (const auto& e : filteredElements) {
        std::cout << e.name << " (" << e.symbol << "), Atomic Number: " << e.atomicNumber << '\n';
    }

    std::cout << "\nNumber of elements with names longer than 5 characters: " << longNameCount << "\n";

    std::cout << "\nUppercase Symbols:\n";
    for (const auto& sym : uppercaseSymbols) {
        std::cout << sym << ' ';
    }
    std::cout << std::endl;

    return 0;
}