#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

// Node representing a file in the BST
struct FileNode {
    std::string fileName;
    int fileSize;           // in megabytes
    std::string fileType;
    FileNode* left;
    FileNode* right;

    FileNode(const std::string& name, int size, const std::string& type)
        : fileName(name), fileSize(size), fileType(type), left(nullptr), right(nullptr) {}

    // overload << for printing
    friend std::ostream& operator<<(std::ostream& os, const FileNode& node) {
        os << "{" << node.fileName
           << ", " << node.fileSize << "MB"
           << ", ." << node.fileType << "}";
        return os;
    }
};

class FileBST {
private:
    FileNode* root;

    // Recursive cleanup
    void clear(FileNode* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    // Insert helper
    FileNode* insertNode(FileNode* node, FileNode* toInsert) {
        if (!node) {
            return toInsert;
        }
        if (toInsert->fileName == node->fileName) {
            throw std::runtime_error("Duplicate file name: " + toInsert->fileName);
        }
        if (toInsert->fileName < node->fileName) {
            node->left = insertNode(node->left, toInsert);
        } else {
            node->right = insertNode(node->right, toInsert);
        }
        return node;
    }

    // Find minimum node in subtree
    FileNode* findMin(FileNode* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    // Delete helper
    FileNode* deleteNode(FileNode* node, const std::string& name) {
        if (!node) {
            throw std::runtime_error("File not found: " + name);
        }
        if (name < node->fileName) {
            node->left = deleteNode(node->left, name);
        } else if (name > node->fileName) {
            node->right = deleteNode(node->right, name);
        } else {
            // found
            if (!node->left) {
                FileNode* r = node->right;
                delete node;
                return r;
            } else if (!node->right) {
                FileNode* l = node->left;
                delete node;
                return l;
            } else {
                FileNode* succ = findMin(node->right);
                node->fileName = succ->fileName;
                node->fileSize = succ->fileSize;
                node->fileType = succ->fileType;
                node->right = deleteNode(node->right, succ->fileName);
            }
        }
        return node;
    }

    // Search helper
    FileNode* searchNode(FileNode* node, const std::string& name) const {
        if (!node) return nullptr;
        if (name == node->fileName) return node;
        if (name < node->fileName) return searchNode(node->left, name);
        return searchNode(node->right, name);
    }

    // Collect files > threshold
    void collectLarger(FileNode* node, int threshold, std::vector<FileNode*>& out) const {
        if (!node) return;
        if (node->fileSize > threshold) out.push_back(node);
        collectLarger(node->left, threshold, out);
        collectLarger(node->right, threshold, out);
    }

    // Traversals
    void inorderNode(FileNode* node) const {
        if (!node) return;
        inorderNode(node->left);
        std::cout << *node << " ";
        inorderNode(node->right);
    }
    void preorderNode(FileNode* node) const {
        if (!node) return;
        std::cout << *node << " ";
        preorderNode(node->left);
        preorderNode(node->right);
    }
    void postorderNode(FileNode* node) const {
        if (!node) return;
        postorderNode(node->left);
        postorderNode(node->right);
        std::cout << *node << " ";
    }

public:
    FileBST() : root(nullptr) {}
    ~FileBST() { clear(root); }

    // Insert new file
    void insert(const std::string& name, int size, const std::string& type) {
        FileNode* node = new FileNode(name, size, type);
        try {
            root = insertNode(root, node);
        } catch (...) {
            delete node;  // avoid leak
            throw;
        }
    }

    // Delete by name
    void remove(const std::string& name) {
        root = deleteNode(root, name);
    }

    // Rename file (change key)
    void renameFile(const std::string& oldName, const std::string& newName) {
        FileNode* node = search(oldName);
        if (!node) throw std::runtime_error("File not found: " + oldName);
        int sz = node->fileSize;
        std::string tp = node->fileType;
        remove(oldName);
        insert(newName, sz, tp);
    }

    // Search by name
    FileNode* search(const std::string& name) const {
        return searchNode(root, name);
    }

    // Retrieve all files larger than threshold
    std::vector<FileNode*> getFilesLargerThan(int threshold) const {
        std::vector<FileNode*> result;
        collectLarger(root, threshold, result);
        return result;
    }

    // Traversals
    void inorder() const { 
        if (!root) throw std::runtime_error("Tree is empty");
        inorderNode(root); std::cout << std::endl;
    }
    void preorder() const { 
        if (!root) throw std::runtime_error("Tree is empty");
        preorderNode(root); std::cout << std::endl;
    }
    void postorder() const { 
        if (!root) throw std::runtime_error("Tree is empty");
        postorderNode(root); std::cout << std::endl;
    }
};

// Demonstration
int main() {
    FileBST fs;
    try {
        fs.insert("report.pdf", 5, "pdf");
        fs.insert("data.txt", 2, "txt");
        fs.insert("app.exe", 15, "exe");
        fs.insert("image.png", 8, "png");
        // Duplicate insertion
        fs.insert("data.txt", 3, "txt");
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Inorder traversal:" << std::endl;
    try { fs.inorder(); } catch (const std::exception& e) { std::cerr << e.what() << std::endl; }

    std::cout << "Preorder traversal:" << std::endl;
    fs.preorder();

    std::cout << "Postorder traversal:" << std::endl;
    fs.postorder();

    // Search
    auto node = fs.search("app.exe");
    if (node) std::cout << "Found: " << *node << std::endl;

    // Files larger than 6MB
    auto largeFiles = fs.getFilesLargerThan(6);
    std::cout << "Files > 6MB:";
    for (auto f : largeFiles) std::cout << " " << *f;
    std::cout << std::endl;

    // Delete and rename
    try {
        fs.remove("nonexistent.txt");
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    fs.remove("data.txt");
    fs.renameFile("app.exe", "application.exe");

    std::cout << "Final inorder:" << std::endl;
    fs.inorder();

    return 0;
}
