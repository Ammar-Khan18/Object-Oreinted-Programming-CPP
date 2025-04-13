#include <iostream>

// Variadic template to sum all arguments
template<typename T>
T sumAll(T first) {
    return first;
}

// Variadic template to handle multiple arguments
template<typename T, typename... Args>
T sumAll(T first, Args... args) {
    T sum = first;  // Start with the first argument
    sum += sumAll(args...);  // Add the sum of the remaining arguments
    return sum;
}

int main() {
    std::cout << "Sum of 1, 2, 3: " << sumAll(1, 2, 3) << "\n";                    // int
    std::cout << "Sum of 1.5, 2.5, 3.5: " << sumAll(1.5, 2.5, 3.5) << "\n";        // double
    std::cout << "Sum of 1, 2.5, 3L: " << sumAll(1, 2.5, 3L) << "\n";              // mixed types
    std::cout << "Sum of 100: " << sumAll(100) << "\n";                            // single value
    std::cout << "Sum of 1.1f, 2, 3.3: " << sumAll(1.1f, 2, 3.3) << "\n";          // float, int, double

    return 0;
}