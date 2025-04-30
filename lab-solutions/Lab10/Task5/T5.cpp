#include <iostream>
#include <vector>

template<typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(Node*& node, const T& val) {
        if (!node) {
            node = new Node(val);
        } else if (val < node->data) {
            insert(node->left, val);
        } else {
            insert(node->right, val);
        }
    }

    void in_order_traversal(Node* node, std::vector<T>& result) const {
        if (!node) return;
        in_order_traversal(node->left, result);
        result.push_back(node->data);
        in_order_traversal(node->right, result);
    }

    void clear(Node*& node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
        node = nullptr;
    }

public:
    BinaryTree() : root(nullptr) {}
    
    ~BinaryTree() {
        clear();
    }

    void insert(const T& val) {
        insert(root, val);
    }

    std::vector<T> in_order_traversal() const {
        std::vector<T> result;
        in_order_traversal(root, result);
        return result;
    }

    void clear() {
        clear(root);
    }

    void operator()(std::vector<T>& values) {
        clear(); // Clear existing tree
        for (const T& val : values) {
            insert(val);
        }
        values = in_order_traversal(); // Replace input vector with sorted values
    }
};

int main() {
    BinaryTree<int> tree;
    std::vector<int> values = {7, 3, 9, 1, 5, 8, 10};

    tree(values); // Sorts the vector using the binary tree
    std::cout << "Sorted values: ";
    for (int val : values) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    return 0;
}
