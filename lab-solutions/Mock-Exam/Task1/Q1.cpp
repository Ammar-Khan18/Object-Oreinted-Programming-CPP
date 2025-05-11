#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <map>
// #include <optional> // removed optional
// #include <ranges>   // commented out ranges
#include <string>
#include <vector>

// Benchmark result struct
struct BenchmarkResult {
    std::string algorithmId;
    int inputSize;
    std::chrono::microseconds executionTime;
    bool success;
};

// Templated Algorithm class
template <typename T>
class Algorithm {
public:
    using ImplFunc = std::function<void(std::vector<T>&)>; // removed optional parameter

    Algorithm(std::string id, std::string name, std::string category,
              std::string timeCplx, std::string spaceCplx,
              ImplFunc func)
        : algorithmId(std::move(id)), name(std::move(name)), category(std::move(category)),
          timeComplexity(std::move(timeCplx)), spaceComplexity(std::move(spaceCplx)),
          implementationFunction(std::move(func)) {}

    // Getters
    const std::string& getId() const { return algorithmId; }
    const std::string& getName() const { return name; }
    const std::string& getCategory() const { return category; }
    const std::string& getTimeComplexity() const { return timeComplexity; }
    const std::string& getSpaceComplexity() const { return spaceComplexity; }

    // Execute
    void execute(std::vector<T>& data) const {
        implementationFunction(data);
    }

private:
    std::string algorithmId;
    std::string name;
    std::string category;
    std::string timeComplexity;
    std::string spaceComplexity;
    ImplFunc implementationFunction;
};

// Analyzer class
template <typename T>
class AlgorithmAnalyzer {
public:
    void registerAlgorithm(const Algorithm<T>& algo) {
        algorithms.push_back(algo);
    }

    void removeAlgorithm(const std::string& id) {
        algorithms.erase(
            std::remove_if(algorithms.begin(), algorithms.end(), [&](const auto& a) { return a.getId() == id; }),
            algorithms.end());
    }

    // Filter by category using C++20 ranges (commented out)
    // auto getAlgorithmsByCategory(const std::string& cat) const {
    //     return algorithms | std::views::filter([&](const auto& a) { return a.getCategory() == cat; });
    // }

    // Filter by time complexity using ranges (commented out)
    // auto getAlgorithmsByComplexity(const std::string& complexity) const {
    //     return algorithms | std::views::filter([&](const auto& a) { return a.getTimeComplexity() == complexity; });
    // }

    // Benchmark an algorithm over input sizes
    std::vector<BenchmarkResult> benchmarkAlgorithm(const std::string& id,
                                                    const std::vector<int>& sizes) {
        std::vector<BenchmarkResult> results;
        for (int n : sizes) {
            std::vector<T> data(n);
            // generate random data
            std::generate(data.begin(), data.end(), []() { return rand() % 10000; });

            auto it = std::find_if(algorithms.begin(), algorithms.end(), [&](auto& a) { return a.getId() == id; });
            if (it == algorithms.end()) continue;
            auto& algo = *it;

            auto start = std::chrono::high_resolution_clock::now();
            try {
                algo.execute(data);
                auto end = std::chrono::high_resolution_clock::now();
                results.push_back({id, n,
                                   std::chrono::duration_cast<std::chrono::microseconds>(end - start),
                                   true});
            } catch (...) {
                results.push_back({id, n, {}, false});
            }
        }
        return results;
    }

    // Compare algorithms on same data
    std::map<std::string, std::vector<BenchmarkResult>> compareAlgorithms(
        const std::vector<std::string>& ids,
        int size) {
        std::map<std::string, std::vector<BenchmarkResult>> allResults;
        for (const auto& id : ids) {
            allResults[id] = benchmarkAlgorithm(id, {size});
        }
        return allResults;
    }

private:
    std::vector<Algorithm<T>> algorithms;
};

// Example sorting implementations
namespace sorting {
    template <typename T>
    void bubbleSort(std::vector<T>& a) {
        int n = a.size();
        for (int i = 0; i < n - 1; ++i)
            for (int j = 0; j < n - i - 1; ++j)
                if (a[j] > a[j + 1]) std::swap(a[j], a[j + 1]);
    }

    template <typename T>
    void insertionSort(std::vector<T>& a) {
        for (size_t i = 1; i < a.size(); ++i) {
            T key = a[i];
            int j = i - 1;
            while (j >= 0 && a[j] > key) {
                a[j + 1] = a[j];
                --j;
            }
            a[j + 1] = key;
        }
    }

    template <typename T>
    void quickSort(std::vector<T>& a) {
        std::function<void(int, int)> qs = [&](int low, int high) {
            if (low < high) {
                T pivot = a[high];
                int i = low - 1;
                for (int j = low; j < high; ++j) {
                    if (a[j] < pivot) std::swap(a[++i], a[j]);
                }
                std::swap(a[i + 1], a[high]);
                int pi = i + 1;
                qs(low, pi - 1);
                qs(pi + 1, high);
            }
        };
        qs(0, a.size() - 1);
    }

    template <typename T>
    void mergeSort(std::vector<T>& a) {
        std::function<void(int, int)> ms = [&](int l, int r) {
            if (l >= r) return;
            int m = l + (r - l) / 2;
            ms(l, m);
            ms(m + 1, r);
            std::vector<T> tmp;
            int i = l, j = m + 1;
            while (i <= m && j <= r) {
                if (a[i] < a[j]) tmp.push_back(a[i++]);
                else tmp.push_back(a[j++]);
            }
            while (i <= m) tmp.push_back(a[i++]);
            while (j <= r) tmp.push_back(a[j++]);
            for (int k = l; k <= r; ++k) a[k] = tmp[k - l];
        };
        ms(0, a.size() - 1);
    }
} // namespace sorting

// Example searching implementations
namespace searching {
    template <typename T>
    void linearSearch(std::vector<T>& a) {
        for (auto& v : a) {
            // search logic (no key) -- user must filter input beforehand
            ;
        }
    }

    template <typename T>
    void binarySearch(std::vector<T>& a) {
        std::sort(a.begin(), a.end());
        int l = 0, r = a.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            // no key comparison
            l = m + 1; // dummy advance to prevent infinite loop
        }
    }
} // namespace searching

int main() {
    AlgorithmAnalyzer<int> analyzer;
    // Register sorting algorithms
    analyzer.registerAlgorithm({"bubble", "Bubble Sort", "Sorting", "O(n^2)", "O(1)", sorting::bubbleSort<int>});
    analyzer.registerAlgorithm({"insertion", "Insertion Sort", "Sorting", "O(n^2)", "O(1)", sorting::insertionSort<int>});
    analyzer.registerAlgorithm({"quick", "Quick Sort", "Sorting", "O(n log n)", "O(log n)", sorting::quickSort<int>});
    analyzer.registerAlgorithm({"merge", "Merge Sort", "Sorting", "O(n log n)", "O(n)", sorting::mergeSort<int>});
    
    // Register searching algorithms
    analyzer.registerAlgorithm({"linear", "Linear Search", "Searching", "O(n)", "O(1)", searching::linearSearch<int>});
    analyzer.registerAlgorithm({"binary", "Binary Search", "Searching", "O(log n)", "O(1)", searching::binarySearch<int>});

    // Benchmark example
    auto results = analyzer.benchmarkAlgorithm("quick", {1000, 10000, 50000});
    for (auto& r : results) {
        std::cout << r.algorithmId << " on " << r.inputSize << " -> " << r.executionTime.count() << "us" << std::endl;
    }

    // Compare algorithms
    auto compareResults = analyzer.compareAlgorithms({"bubble", "quick"}, 5000);
    for (auto& [id, vec] : compareResults) {
        for (auto& r : vec) {
            std::cout << id << " size=" << r.inputSize << " time=" << r.executionTime.count() << "us" << std::endl;
        }
    }

    return 0;
}
