#include <iostream>
#include <vector>

template<typename T>
struct insertion_sort {
    void operator()(std::vector<T>& vec) const {
        for (size_t i = 1; i < vec.size(); ++i) {
            T key = vec[i];
            size_t j = i;
            while (j > 0 && vec[j - 1] > key) {
                vec[j] = vec[j - 1];
                --j;
            }
            vec[j] = key;
        }
    }
};
int main() {
    std::vector<int> numbers = {5, 2, 9, 1, 5, 6};

    insertion_sort<int> sorter;
    sorter(numbers);

    std::cout << "Sorted vector: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << '\n';

    return 0;
}
