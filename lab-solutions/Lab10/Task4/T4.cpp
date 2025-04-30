#include <iostream>
#include <vector>

template<typename T>
void shell_sort(std::vector<T>& vec) {
    size_t n = vec.size();

    // Start with a big gap, then reduce the gap
    for (size_t gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size
        for (size_t i = gap; i < n; ++i) {
            T temp = vec[i];
            size_t j = i;

            // Shift earlier gap-sorted elements up until the correct location for vec[i] is found
            while (j >= gap && vec[j - gap] > temp) {
                vec[j] = vec[j - gap];
                j -= gap;
            }

            // Put temp (the original vec[i]) in its correct location
            vec[j] = temp;
        }
    }
}
int main() {
    std::vector<int> nums = {23, 12, 1, 8, 34, 54, 2, 3};

    shell_sort(nums);

    std::cout << "Sorted vector: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << '\n';

    return 0;
}
