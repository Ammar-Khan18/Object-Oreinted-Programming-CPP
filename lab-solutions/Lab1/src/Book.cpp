#include "Book.h"
using namespace std;

Book::Book(const string& title, const string& author)
    : title(title), author(author), available(true) {}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

bool Book::isAvailable() const {
    return available;
}

void Book::setAvailable(bool availability) {
    available = availability;
}