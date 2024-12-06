#include "screens/BorrowScreen.h"
#include "Catalog.h"
#include <iostream>
#include <string>

BorrowScreen::BorrowScreen(Client& clientRef) : client(clientRef) {}

void BorrowScreen::render() {
    Catalog catalog;
    while (true) {
        cout << "Enter the ID of the book you want to borrow (Enter empty input to return to dashboard): ";
        string bookId;
        getline(cin, bookId);

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid book ID.\n";
        }

        Book bookToBorrow = catalog.getBookFromCatalog(bookId);
        if (bookToBorrow.getBookId() != "-1") {
            if (client.clientBorrowBook(bookToBorrow)) {
                cout << "You have borrowed \"" << bookToBorrow.getTitle() << "\" by " << bookToBorrow.getAuthor() << "!\n";
                cout << "Please return the book by the due date.\n";
            } else {
                cout << "Unable to borrow the book. Unless book is unavailable, check your borrow limit or overdue status.\n";
            }
        } else {
            cout << "Book ID not found. Returning to the previous menu.\n";
            break;
        }
    }

    cin.clear();
    return;
}