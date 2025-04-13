#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class GenericLinkedList {
private:
    // Node structure
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    // Constructor
    GenericLinkedList() : head(nullptr) {}

    // Destructor to clean up memory
    ~GenericLinkedList() {
        while (head) {
            deleteFromTail();
        }
    }

    // Insert at tail
    void insertAtTail(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete from tail
    void deleteFromTail() {
        if (!head) {
            throw std::underflow_error("Cannot delete from an empty list.");
        }

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    // Display all elements
    void display() const {
        if (!head) {
            std::cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
};

int main() {
    // Integer list
    GenericLinkedList<int> intList;
    std::cout << "Integer Linked List:\n";
    intList.insertAtTail(10);
    intList.insertAtTail(20);
    intList.insertAtTail(30);
    intList.display();

    intList.deleteFromTail();
    intList.display();

    // String list
    GenericLinkedList<std::string> strList;
    std::cout << "\nString Linked List:\n";
    strList.insertAtTail("Alice");
    strList.insertAtTail("Bob");
    strList.insertAtTail("Charlie");
    strList.display();

    strList.deleteFromTail();
    strList.display();

    // Double list
    GenericLinkedList<double> doubleList;
    std::cout << "\nDouble Linked List:\n";
    doubleList.insertAtTail(3.14);
    doubleList.insertAtTail(2.71);
    doubleList.display();

    // Test exception
    std::cout << "\nTesting exception for empty list delete:\n";
    GenericLinkedList<int> emptyList;
    try {
        emptyList.deleteFromTail();
    } catch (const std::underflow_error& e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }

    return 0;
}
