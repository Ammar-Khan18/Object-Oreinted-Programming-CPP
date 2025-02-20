#include <iostream>

/*
Adding a Score (O(1) Amortized)
Updating a Score (O(1))
Retrieving a Score (O(1))
Resizing the Array (O(n))
*/

class Leaderboard {
private:
    int* scores;      // Dynamic array for player scores
    int capacity;     // Maximum number of scores the array can hold
    int size;         // Current number of players

    // Function to resize the array when full
    void resize() {
        int newCapacity = capacity * 2;
        int* newScores = new int[newCapacity];

        // Copy existing scores to new array
        for (int i = 0; i < size; i++) {
            newScores[i] = scores[i];
        }

        // Delete old array and update pointers
        delete[] scores;
        scores = newScores;
        capacity = newCapacity;
    }

public:
    // Constructor
    Leaderboard(int cap = 4) {  // Default capacity of 4
        capacity = cap;
        scores = new int[capacity];
        size = 0;
    }

    // Destructor
    ~Leaderboard() {
        delete[] scores;
    }

    // Add a new player score
    void addScore(int score) {
        if (size == capacity) {
            resize();  // Double the size when full
        }
        scores[size++] = score;
    }

    // Update an existing player's score
    void updateScore(int index, int newScore) {
        if (index < 0 || index >= size) {
            std::cerr << "Invalid index!" << std::endl;
            return;
        }
        scores[index] = newScore;
    }

    // Get a player's score
    int getScore(int index) {
        if (index < 0 || index >= size) {
            std::cerr << "Invalid index!" << std::endl;
            return -1;
        }
        return scores[index];
    }

    // Display all scores
    void printLeaderboard() {
        if (size == 0) {
            std::cout << "Leaderboard is empty." << std::endl;
            return;
        }
        std::cout << "Leaderboard Scores: ";
        for (int i = 0; i < size; i++) {
            std::cout << scores[i] << " ";
        }
        std::cout << std::endl;
    }
};

// Driver Code
int main() {
    Leaderboard lb;

    lb.addScore(1500);
    lb.addScore(1800);
    lb.addScore(1200);
    lb.addScore(2000);
    lb.printLeaderboard();

    lb.addScore(1700);  // This triggers a resize
    lb.printLeaderboard();

    lb.updateScore(2, 1300);  // Update a score
    lb.printLeaderboard();

    std::cout << "Player at index 1 has score: " << lb.getScore(1) << std::endl;

    return 0;
}