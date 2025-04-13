#include <iostream>
#include <vector>

template <typename T>
class NumberStats {
private:
    std::vector<T> numbers;

public:
    // Add number to the collection
    void addNumber(const T& num) {
        numbers.push_back(num);
    }

    // Get minimum value
    T getMin() const {
        if (numbers.empty()) {
            throw std::runtime_error("No numbers to calculate minimum.");
        }
        T minVal = numbers[0];
        for (const T& num : numbers) {
            if (num < minVal) {
                minVal = num;
            }
        }
        return minVal;
    }

    // Get maximum value
    T getMax() const {
        if (numbers.empty()) {
            throw std::runtime_error("No numbers to calculate maximum.");
        }
        T maxVal = numbers[0];
        for (const T& num : numbers) {
            if (num > maxVal) {
                maxVal = num;
            }
        }
        return maxVal;
    }

    // Get average value
    double getAverage() const {
        if (numbers.empty()) {
            throw std::runtime_error("No numbers to calculate average.");
        }
        double sum = 0.0;
        for (const T& num : numbers) {
            sum += static_cast<double>(num);
        }
        return sum / numbers.size();
    }
};

int main() {
    // Testing with int
    NumberStats<int> intStats;
    intStats.addNumber(10);
    intStats.addNumber(20);
    intStats.addNumber(5);
    intStats.addNumber(15);

    std::cout << "Integer Stats:\n";
    std::cout << "Min: " << intStats.getMin() << "\n";
    std::cout << "Max: " << intStats.getMax() << "\n";
    std::cout << "Avg: " << intStats.getAverage() << "\n";

    // Testing with double
    NumberStats<double> doubleStats;
    doubleStats.addNumber(10.5);
    doubleStats.addNumber(20.3);
    doubleStats.addNumber(5.2);
    doubleStats.addNumber(15.9);

    std::cout << "\nDouble Stats:\n";
    std::cout << "Min: " << doubleStats.getMin() << "\n";
    std::cout << "Max: " << doubleStats.getMax() << "\n";
    std::cout << "Avg: " << doubleStats.getAverage() << "\n";

    return 0;
}
