#include "screens/RemoveBookScreen.h"
#include <iostream>

RemoveBookScreen::RemoveBookScreen(Admin& admin) : admin(admin) {};

string getBookIdInput() {
    string bookId;
    cin.clear();
    cin.ignore(10000, '\n');

    cout << "(Input empty string to go back)" << '\n';
    cout << "Enter the Book ID of the book to edit: ";
    getline(cin, bookId);

    if (bookId.empty()) {
        cin.clear();
        return "";
    }

    cin.clear();

    return bookId;
}

void RemoveBookScreen::render() {
    Catalog catalog;
    vector<Book> books = catalog.loadBookCatalog();
    Book book;
    string bookId;

    for (const auto& book : books) {
        book.displayBookInfo();
        cout << "\n";
    }

    while (true) {
        bookId = getBookIdInput();
        if (bookId == "") break;
        book = catalog.getBookFromCatalog(bookId);

        if (book.getBookId() == "-1") {
            cout << "Book not found in catalog. Please enter a valid book ID." << '\n';
            return;
        }

        if (admin.deleteBook(book.getBookId())) {
            cout << "\n" << "Successfully deleted Book #" << bookId << "!\n";
            return;
        } else {
            cout << "\n" << "Error deleting book in the catalog. Please try again later." << "\n";
            return; 
        }
    }

    cin.clear();
    return;
}