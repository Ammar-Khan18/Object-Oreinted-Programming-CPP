#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    bool available;

public:
    Book(const string& title, const string& author);
    string getTitle() const;
    string getAuthor() const;
    bool isAvailable() const;
    void setAvailable(bool availability);
};

#endif // BOOK_H