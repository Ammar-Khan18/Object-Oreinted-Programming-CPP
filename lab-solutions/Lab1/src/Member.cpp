#include "Member.h"
#include <iostream>
using namespace std;

Member::Member(const string& name) : name(name) {}

bool Member::borrowBook(Book* book) {
    if (borrowedBooks.size() >= 3) {
        cout << "Borrowing limit reached! You cannot borrow more than 3 books." << endl;
        return false;
    }
    if (book->isAvailable()) {
        borrowedBooks.push_back(book);
        book->setAvailable(false);
        cout << "Book '" << book->getTitle() << "' borrowed by " << name << "." << endl;
        return true;
    } else {
        cout << "Book '" << book->getTitle() << "' is not available." << endl;
        return false;
    }
}

// Return a book (FIFO policy)
bool Member::returnBook() {
    if (borrowedBooks.empty()) {
        cout << "No books to return." << endl;
        return false;
    }
    Book* book = borrowedBooks.front();  // Get the first borrowed book
    borrowedBooks.erase(borrowedBooks.begin());  // Remove it from the list
    book->setAvailable(true);
    cout << "Book '" << book->getTitle() << "' returned by " << name << "." << endl;
    return true;
}

// Display borrowed books
void Member::displayBorrowedBooks() const {
    cout << name << "'s borrowed books:" << endl;
    for (const auto& book : borrowedBooks) {
        cout << "- " << book->getTitle() << " by " << book->getAuthor() << endl;
    }
}