#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;

    // Constructor to initialize a node
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to clean up memory
    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert at the beginning
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) { // If the list is empty
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at the end
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) { // If the list is empty
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Delete a node by value
    void deleteByValue(int value) {
        if (head == nullptr) return; // List is empty

        Node* current = head;
        while (current != nullptr && current->data != value) {
            current = current->next;
        }

        if (current == nullptr) return; // Value not found

        if (current == head) { // If the node to delete is the head
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr; // List becomes empty
            }
        } else if (current == tail) { // If the node to delete is the tail
            tail = tail->prev;
            tail->next = nullptr;
        } else { // If the node is in the middle
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;
    }

   


 // Forward traversal
    void printForward() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Backward traversal
    void printBackward() const {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    // Insert elements
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtTail(30);
    list.insertAtTail(40);

    // Print the list
    cout << "Forward traversal: ";
    list.printForward();

    cout << "Backward traversal: ";
    list.printBackward();

    // Delete a node
    list.deleteByValue(30);
    cout << "After deleting 30 (Forward): ";
    list.printForward();

    list.deleteByValue(20);
    cout << "After deleting 20 (Forward): ";
    list.printForward();

    list.deleteByValue(40);
    cout << "After deleting 40 (Forward): ";
    list.printForward();

    return 0;
}
