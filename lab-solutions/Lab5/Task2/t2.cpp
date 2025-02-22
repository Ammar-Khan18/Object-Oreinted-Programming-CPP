#include <iostream>
using namespace std;

class MemoryResource {
public:
    MemoryResource() {
        cout << "MemoryResource base allocated\n";
    }
    
    ~MemoryResource() {
        cout << "MemoryResource base freed\n";
    }
};

class NetworkBuffer : public MemoryResource {
public:
    NetworkBuffer() {
        cout << "NetworkBuffer derived allocated\n";
    }
    
    ~NetworkBuffer() {
        cout << "NetworkBuffer derived freed\n";
    }
};

int main() {
    {
        NetworkBuffer buffer;  // Observe lifecycle in this scope
    }  // Buffer goes out of scope here
    return 0;
}