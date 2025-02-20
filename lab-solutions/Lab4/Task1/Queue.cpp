#include <iostream>

class PrintQueue {
private:
    int* arr;         // Dynamic array for queue storage
    int capacity;     // Maximum capacity of queue
    int front;        // Index of the front element
    int rear;         // Index of the last element
    int size;         // Number of elements in the queue

    // Function to resize the queue when full
    void resize() {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];

        // Copy elements from old array to new array
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[(front + i) % capacity];
        }

        // Delete old array and update pointers
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
        front = 0;
        rear = size - 1;
    }

public:
    // Constructor
    PrintQueue(int cap = 4) {  // Default capacity of 4
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Destructor
    ~PrintQueue() {
        delete[] arr;
    }

    // Enqueue: Add a new print job
    void enqueue(int job) {
        if (size == capacity) {
            resize();  // Double the size if full
        }
        rear = (rear + 1) % capacity;
        arr[rear] = job;
        size++;
    }

    // Dequeue: Process the front job
    int dequeue() {
        if (size == 0) {
            std::cerr << "Queue is empty!" << std::endl;
            return -1;
        }
        int job = arr[front];
        front = (front + 1) % capacity;
        size--;
        return job;
    }

    // Check if queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Get the front element without removing
    int peek() {
        if (size == 0) {
            std::cerr << "Queue is empty!" << std::endl;
            return -1;
        }
        return arr[front];
    }

    // Print queue elements
    void printQueue() {
        if (size == 0) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        std::cout << "Print Queue: ";
        for (int i = 0; i < size; i++) {
            std::cout << arr[(front + i) % capacity] << " ";
        }
        std::cout << std::endl;
    }
};

// Driver Code
int main() {
    PrintQueue pq;

    pq.enqueue(101);
    pq.enqueue(102);
    pq.enqueue(103);
    pq.enqueue(104);
    pq.printQueue();

    pq.enqueue(105);  // This will trigger a resize
    pq.printQueue();

    std::cout << "Processing: " << pq.dequeue() << std::endl;
    pq.printQueue();

    return 0;
}