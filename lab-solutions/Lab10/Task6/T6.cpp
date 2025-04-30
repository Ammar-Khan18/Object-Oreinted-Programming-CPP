#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <functional>
#include <algorithm>

// Stopwatch utility
class Stopwatch {
private:
    std::chrono::steady_clock::time_point start_time, end_time;
    bool running = false;

public:
    void start() {
        start_time = std::chrono::steady_clock::now();
        running = true;
    }

    void stop() {
        if (running) {
            end_time = std::chrono::steady_clock::now();
            running = false;
        }
    }

    void reset() {
        running = false;
    }

    double get_elapsed_time_seconds() const {
        if (running) {
            return std::chrono::duration<double>(std::chrono::steady_clock::now() - start_time).count();
        }
        return std::chrono::duration<double>(end_time - start_time).count();
    }
};

// Insertion Sort Functor
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

// Selection Sort Functor
template<typename T>
struct selection_sort {
    void operator()(std::vector<T>& vec) const {
        for (size_t i = 0; i < vec.size() - 1; ++i) {
            size_t min_index = i;
            for (size_t j = i + 1; j < vec.size(); ++j) {
                if (vec[j] < vec[min_index]) {
                    min_index = j;
                }
            }
            std::swap(vec[i], vec[min_index]);
        }
    }
};

// Shell Sort Function
template<typename T>
void shell_sort(std::vector<T>& vec) {
    for (size_t gap = vec.size() / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < vec.size(); ++i) {
            T temp = vec[i];
            size_t j = i;
            while (j >= gap && vec[j - gap] > temp) {
                vec[j] = vec[j - gap];
                j -= gap;
            }
            vec[j] = temp;
        }
    }
}

// Binary Tree Class
template<typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;

    void insert(Node*& node, const T& val) {
        if (!node) node = new Node(val);
        else if (val < node->data) insert(node->left, val);
        else insert(node->right, val);
    }

    void in_order(Node* node, std::vector<T>& res) const {
        if (!node) return;
        in_order(node->left, res);
        res.push_back(node->data);
        in_order(node->right, res);
    }

    void clear(Node*& node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
        node = nullptr;
    }

public:
    ~BinaryTree() { clear(); }

    void insert(const T& val) { insert(root, val); }

    void clear() { clear(root); }

    std::vector<T> in_order() const {
        std::vector<T> res;
        in_order(root, res);
        return res;
    }

    void operator()(std::vector<T>& vec) {
        clear();
        for (const auto& v : vec) insert(v);
        vec = in_order();
    }
};

// Benchmark Evaluator Class
class BenchmarkEvaluator {
public:
    double evaluate(std::function<void(std::vector<int>&)> sorter, int runs) {
        Stopwatch sw;
        double total_time = 0.0;

        for (int i = 0; i < runs; ++i) {
            std::vector<int> data = generate_random_vector(100000);
            sw.start();
            sorter(data);
            sw.stop();
            total_time += sw.get_elapsed_time_seconds();
            sw.reset();
        }

        return total_time / runs;
    }

private:
    std::vector<int> generate_random_vector(size_t size) {
        std::vector<int> vec(size);
        std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution<int> dist(0, 1000000);
        for (auto& val : vec) val = dist(rng);
        return vec;
    }
};

// Main Function
int main() {
    BenchmarkEvaluator evaluator;

    std::cout << "Benchmarking Sorting Algorithms (Average over 3 runs):\n\n";

    double insertion_time = evaluator.evaluate(insertion_sort<int>(), 3);
    std::cout << "Insertion Sort Avg Time: " << insertion_time << " seconds\n";

    double selection_time = evaluator.evaluate(selection_sort<int>(), 3);
    std::cout << "Selection Sort Avg Time: " << selection_time << " seconds\n";

    double shell_time = evaluator.evaluate(shell_sort<int>, 3);
    std::cout << "Shell Sort Avg Time: " << shell_time << " seconds\n";

    BinaryTree<int> bt;
    double tree_time = evaluator.evaluate([&bt](std::vector<int>& v) { bt(v); }, 3);
    std::cout << "BinaryTree Sort Avg Time: " << tree_time << " seconds\n";

    std::cout << "\nConclusion:\n"
              << "- Insertion & Selection sorts are quadratic and very slow for large datasets.\n"
              << "- Shell sort is significantly faster due to better complexity (~O(n^1.3)).\n"
              << "- Binary Tree sort performs fairly well but can degrade to O(n²) if unbalanced.\n";

    return 0;
}
