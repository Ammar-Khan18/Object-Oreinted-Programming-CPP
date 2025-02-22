#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Cache {
protected:
    int capacity;
    vector<int> currentItems;

public:
    Cache(int cap) : capacity(cap) {}
    virtual void addItem(int item) = 0; // Pure virtual function

    void printCache() {
        for (int item : currentItems) {
            cout << item << " ";
        }
        cout << endl;
    }
};

class FIFOCache : public Cache {
public:
    FIFOCache(int cap) : Cache(cap) {}

    void addItem(int item) override {
        if (currentItems.size() >= capacity) {
            currentItems.erase(currentItems.begin()); // Evict the first item (oldest)
        }
        currentItems.push_back(item); // Add new item to the end
    }
};

class LRUCache : public Cache {
public:
    LRUCache(int cap) : Cache(cap) {}

    void addItem(int item) override {
        auto it = find(currentItems.begin(), currentItems.end(), item);
        if (it != currentItems.end()) {
            currentItems.erase(it); // If item exists, remove it
        } else if (currentItems.size() >= capacity) {
            currentItems.erase(currentItems.begin()); // Evict the first item (least recently used)
        }
        currentItems.push_back(item); // Add new item to the end
    }
};

int main() {
    FIFOCache fifo(3);
    fifo.addItem(1);
    fifo.addItem(2);
    fifo.addItem(3);
    fifo.addItem(4); // Evicts 1
    cout << "FIFO Cache: ";
    fifo.printCache(); // Output: 2 3 4

    LRUCache lru(3);
    lru.addItem(1);
    lru.addItem(2);
    lru.addItem(3);
    lru.addItem(2); // Moves 2 to the end (recently used)
    lru.addItem(4); // Evicts 1
    cout << "LRU Cache: ";
    lru.printCache(); // Output: 3 2 4

    return 0;
}