#include <iostream>
#include <string>

class Node {
public:
    std::string url; // URL of the webpage
    Node* next;      // Pointer to the next node
    Node(std::string url) : url(url), next(nullptr) {}
};

class BrowserHistory {
private:
    Node* head;      // Oldest page
    Node* tail;      // Newest page
    Node* current;   // Current page for navigation
public:
    BrowserHistory() : head(nullptr), tail(nullptr), current(nullptr) {}

    // Add a new page to history (append to tail)
    void visitPage(const std::string& url) {
        Node* newNode = new Node(url);
        if (!head) {
            head = tail = current = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
            current = tail; // Reset navigation to the latest page
        }
    }

    void goBackOneRemove() {
        if (!current || current == head) {
            std::cout << "Already at the oldest page. Cannot go back." << std::endl;
            return;
        }
        Node* prev = head;
        // Traverse until we find the node whose next pointer is current.
        while (prev->next != current) {
            prev = prev->next;
        }
        // 'prev' is now the node just before 'current'
        Node* nodeToRemove = current;
        current = prev;              // Move current pointer back to previous node
        prev->next = nodeToRemove->next;  // Bypass the node to be removed

        // If we removed the tail, update tail accordingly.
        if (nodeToRemove == tail) {
            tail = prev;
        }
        delete nodeToRemove;
        std::cout << "Current URL (removed previous current): " << current->url << std::endl;
    }

    // Display full history
    void displayHistory() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->url;
            if (temp == current) std::cout << " [CURRENT]";
            std::cout << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    // Destructor to free memory
    ~BrowserHistory() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    BrowserHistory history;
    history.visitPage("https://google.com");
    history.visitPage("https://wikipedia.org");
    history.visitPage("https://github.com");
    history.displayHistory();

    history.goBackOneRemove(); // Navigate to previous page
    return 0;
}

// class Node {  
// public:  
//     std::string url;  
//     Node* next;  
//     Node(std::string url) : url(url), next(nullptr) {}  
// };  

// class BrowserHistory {  
// private:  
//     Node* head;  
//     Node* tail;  
//     Node* current;  

// public:  
//     BrowserHistory() : head(nullptr), tail(nullptr), current(nullptr) {}  

//     void visitPage(std::string url) {  
//         // TODO: Append new node to tail, update current  
//     }  

//     void goBack(int steps) {  
//         // TODO: Move current backward by steps, print current URL  
//     }  

//     void displayHistory() {  
//         // TODO: Print all URLs with current marked  
//     }  

//     ~BrowserHistory() {  
//         // TODO: Deallocate all nodes  
//     }  
// };  