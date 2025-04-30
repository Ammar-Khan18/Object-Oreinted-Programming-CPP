#include <iostream>
#include <vector>

template<typename T>
struct selection_sort {
    void operator()(std::vector<T>& vec) const {
        size_t n = vec.size();
        for (size_t i = 0; i < n - 1; ++i) {
            size_t min_index = i;
            for (size_t j = i + 1; j < n; ++j) {
                if (vec[j] < vec[min_index]) {
                    min_index = j;
                }
            }
            if (min_index != i) {
                std::swap(vec[i], vec[min_index]);
            }
        }
    }
};
int main() {
    std::vector<int> data = {29, 10, 14, 37, 13};

    selection_sort<int> sorter;
    sorter(data);

    std::cout << "Sorted vector: ";
    for (const auto& val : data) {
        std::cout << val << " ";
    }
    std::cout << '\n';

    return 0;
}
