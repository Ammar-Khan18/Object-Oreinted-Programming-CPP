#include "Librarian.h"
#include <iostream>
using namespace std;

// Add a book to the library
void Librarian::addBook(Book* book) {
    books.push_back(book);
    cout << "Book '" << book->getTitle() << "' added to the library." << endl;
}

// Remove a book from the library
void Librarian::removeBook(const string& title) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if ((*it)->getTitle() == title) {
            books.erase(it);
            cout << "Book '" << title << "' removed from the library." << endl;
            return;
        }
    }
    cout << "Book '" << title << "' not found in the library." << endl;
}

// Display all books in the library
void Librarian::displayAllBooks() const {
    cout << "Books in the library:" << endl;
    for (const auto& book : books) {
        cout << "- " << book->getTitle() << " by " << book->getAuthor() << " (" << (book->isAvailable() ? "Available" : "Borrowed") << ")" << endl;
    }
}