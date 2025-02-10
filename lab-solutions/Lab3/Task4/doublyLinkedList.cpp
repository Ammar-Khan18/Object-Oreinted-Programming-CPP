#include <iostream>
using namespace std;

// Node class represents each element in the doubly linked list
class Node {
public:
    int data;      // Value stored in the node
    Node* next;    // Pointer to the next node
    Node* prev;    // Pointer to the previous node

    // Constructor to initialize a new node with a value
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// DoublyLinkedList class encapsulates operations on the list
class DoublyLinkedList {
private:
    Node* head;    // Pointer to the first node in the list
    Node* tail;    // Pointer to the last node in the list

public:
    // Constructor initializes an empty list
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to free memory when the list is destroyed
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Add a new node with the given value at the end (tail) of the list
    void addAtEnd(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {  // The list is empty
            head = tail = newNode;
        } else {
            tail->next = newNode; // Link the current tail to newNode
            newNode->prev = tail; // Set newNode's previous pointer to the old tail
            tail = newNode;       // Update the tail pointer to the new node
        }
    }

    // Remove the first element (head) of the list
    void removeFirst() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to remove." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;  // Move head pointer to the next node
        if (head != nullptr) {
            head->prev = nullptr;  // New head has no previous node
        } else {
            // If the list becomes empty, update tail to nullptr as well
            tail = nullptr;
        }
        delete temp;  // Free memory of the removed node
    }

    // Get the value at a specified index (0-based)
    int getValueAt(int index) {
        Node* current = head;
        int count = 0;
        while (current != nullptr) {
            if (count == index) {
                return current->data;
            }
            current = current->next;
            count++;
        }
        cout << "Index " << index << " out of bounds." << endl;
        return -1;  // Return an error value; in production code, consider throwing an exception
    }

    // Traverse the list forward from head to tail and print each node's data
    void traverseForward() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Traverse the list backward from tail to head and print each node's data
    void traverseBackward() {
        Node* current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    // Add several values at the end of the list
    dll.addAtEnd(10);
    dll.addAtEnd(20);
    dll.addAtEnd(30);
    dll.addAtEnd(40);

    cout << "List after adding values at the end (forward traversal): ";
    dll.traverseForward();

    cout << "List traversed backward: ";
    dll.traverseBackward();

    cout<<"Adding 50 at the end: ";
    dll.addAtEnd(50);
    dll.traverseForward();

    // Retrieve and display the value at index 2 (expected value: 30)
    int index = 2;
    cout << "Value at index " << index << " is: " << dll.getValueAt(index) << endl;

    // Remove the first element from the list
    dll.removeFirst();
    cout << "List after removing the first element: ";
    dll.traverseForward();

    // Testing edge cases:
    // Remove all elements
    dll.removeFirst();  // Removes 20
    dll.removeFirst();  // Removes 30
    dll.removeFirst();  // Removes 40, list becomes empty
    // Attempt to remove from an empty list
    dll.removeFirst();
    dll.removeFirst();

    // Add a new value to an empty list
    dll.addAtEnd(100);
    cout << "List after adding 100 at the end: ";
    dll.traverseForward();

    return 0;
}
