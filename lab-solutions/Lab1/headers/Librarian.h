#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include <vector>
#include "Book.h"
using namespace std;

class Librarian {
private:
    vector<Book*> books;  // List of all books in the library

public:
    void addBook(Book* book);
    void removeBook(const string& title);
    void displayAllBooks() const;
};

#endif // LIBRARIAN_H