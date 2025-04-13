#include <iostream>

// Define the function pointer type
typedef int (*ftype)(void* arr, int n);

// Generic function that takes array, size, and a function pointer
int findpos(void* A, int n, ftype fp) {
    return fp(A, n);
}

// Find position of max element in int array
int findMaxPos(void* arr, int n) {
    int* intArr = static_cast<int*>(arr);
    int maxPos = 0;
    for (int i = 1; i < n; ++i) {
        if (intArr[i] > intArr[maxPos]) {
            maxPos = i;
        }
    }
    return maxPos;
}

// Find position of min element in int array
int findMinPos(void* arr, int n) {
    int* intArr = static_cast<int*>(arr);
    int minPos = 0;
    for (int i = 1; i < n; ++i) {
        if (intArr[i] < intArr[minPos]) {
            minPos = i;
        }
    }
    return minPos;
}

// ---- MAIN ----
int main() {
    int arr[] = {10, 25, 5, 40, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxPos = findpos(arr, n, findMaxPos);
    std::cout << "Position of max element: " << maxPos << "\n";

    int minPos = findpos(arr, n, findMinPos);
    std::cout << "Position of min element: " << minPos << "\n";

    return 0;
}
