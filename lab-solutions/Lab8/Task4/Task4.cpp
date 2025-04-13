#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ---- Algorithm Functions ----

void sortArray(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    cout << "Sorted array.\n";
}

void reverseArray(vector<int>& arr) {
    reverse(arr.begin(), arr.end());
    cout << "Reversed array.\n";
}

void rotateArray(vector<int>& arr) {
    if (!arr.empty())
        rotate(arr.begin(), arr.begin() + 1, arr.end());
    cout << "Rotated array (left shift).\n";
}

void findMinElement(vector<int>& arr) {
    if (!arr.empty()) {
        auto minIt = min_element(arr.begin(), arr.end());
        cout << "Minimum element: " << *minIt << "\n";
    }
}

void findMaxElement(vector<int>& arr) {
    if (!arr.empty()) {
        auto maxIt = max_element(arr.begin(), arr.end());
        cout << "Maximum element: " << *maxIt << "\n";
    }
}

void countOccurrences(vector<int>& arr) {
    int value;
    cout << "Enter value to count: ";
    cin >> value;
    int count = std::count(arr.begin(), arr.end(), value);
    cout << "Occurrences of " << value << ": " << count << "\n";
}

// ---- Function Pointer Wrapper ----

void custom_algorithm(vector<int>& arr, void (*func)(vector<int>&)) {
    func(arr);
}

// ---- Helper to display the vector ----

void printArray(const vector<int>& arr) {
    cout << "Array: ";
    for (int n : arr)
        cout << n << " ";
    cout << "\n";
}

// ---- Main Function ----

int main() {
    vector<int> numbers = {4, 2, 9, 1, 5, 2};

    cout << "Initial ";
    printArray(numbers);

    // Apply each function through custom_algorithm
    custom_algorithm(numbers, sortArray);
    printArray(numbers);

    custom_algorithm(numbers, reverseArray);
    printArray(numbers);

    custom_algorithm(numbers, rotateArray);
    printArray(numbers);

    custom_algorithm(numbers, findMinElement);
    custom_algorithm(numbers, findMaxElement);
    custom_algorithm(numbers, countOccurrences);

    return 0;
}
