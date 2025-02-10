#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Circular Linked List class
class CircularLinkedList {
private:
    Node* head;

public:
    // Constructor
    CircularLinkedList() : head(nullptr) {}

    // Destructor to clean up memory
    ~CircularLinkedList() {
        if (head == nullptr) return; // List is empty

        Node* current = head;
        Node* nextNode;
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }

    // Insert at the beginning
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) { // If the list is empty
            head = newNode;
            head->next = head; // Point to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // Insert at the end
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) { // If the list is empty
            head = newNode;
            head->next = head; // Point to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Delete a node by value
    void deleteByValue(int value) {
        if (head == nullptr) return; // List is empty

        Node* current = head;
        Node* prev = nullptr;

        // Traverse the list to find the node to delete
        do {
            if (current->data == value) {
                break;
            }
            prev = current;
            current = current->next;
        } while (current != head);

        if (current->data != value) return; // Value not found

        if (current == head && current->next == head) { // Only one node in the list
            delete current;
            head = nullptr;
        } else if (current == head) { // If the node to delete is the head
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;
            delete current;
        } else { // If the node is in the middle or tail
            prev->next = current->next;
            delete current;
        }
    }

    // Traverse and print the list
    void printList() const {
        if (head == nullptr) return; // List is empty

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;

    // Insert elements
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtTail(30);
    list.insertAtTail(40);

    // Print the list
    cout << "Circular Linked List: ";
    list.printList();

    // Delete a node
    list.deleteByValue(30);
    cout << "After deleting 30: ";
    list.printList();

    list.deleteByValue(20);
    cout << "After deleting 20: ";
    list.printList();

    list.deleteByValue(40);
    cout << "After deleting 40: ";
    list.printList();

    list.deleteByValue(10);
    cout << "After deleting 10: ";
    list.printList();

    return 0;
}
