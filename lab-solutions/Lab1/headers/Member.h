#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include "Book.h"
using namespace std;

class Member {
private:
    string name;
    vector<Book*> borrowedBooks;  // List of borrowed books

public:
    Member(const string& name);
    bool borrowBook(Book* book);
    bool returnBook();
    void displayBorrowedBooks() const;
};

#endif // MEMBER_H