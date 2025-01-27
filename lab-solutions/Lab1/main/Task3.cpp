#include <iostream>
#include "Book.h"
#include "Member.h"
#include "Librarian.h"

int main() {
    Book book1("The Great Gatsby", "F. Scott Fitzgerald");
    Book book2("1984", "George Orwell");
    Book book3("To Kill a Mockingbird", "Harper Lee");

    Member member1("Alice");
    Member member2("Bob");

    Librarian librarian;

    // Add books to the library
    librarian.addBook(&book1);
    librarian.addBook(&book2);
    librarian.addBook(&book3);

    // Display all books
    librarian.displayAllBooks();

    // Members borrow books
    member1.borrowBook(&book1);
    member1.borrowBook(&book2);
    member2.borrowBook(&book3);

    // Display all books after borrowing
    librarian.displayAllBooks();

    // Display borrowed books by members
    member1.displayBorrowedBooks();
    member2.displayBorrowedBooks();

    // Members return books
    member1.returnBook();
    member2.returnBook();

    // Display all books after returning
    librarian.displayAllBooks();

    return 0;
}