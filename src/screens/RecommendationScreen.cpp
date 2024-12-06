#include "screens/RecommendationScreen.h"
#include <iostream>

using namespace std;

RecommendationScreen::RecommendationScreen(Client& clientRef) : client(clientRef) {}

void RecommendationScreen::render() {
    if (!client.getLoggedIn()) {
        cout << "Please log in or register to view recommendations.\n";
        return;
    }

    // Get recommended books for the logged-in client
    vector<Book> books = catalog.getBookRecommendations(client);

    cout << "\n--- Book Recommendations ---\n";

    if (books.empty()) {
        cout << "No recommendations available at the moment.\n";
        return;
    }

    for (const auto& book : books) {
        book.displayBookInfo();
        cout << "\n";
    }

    cout << "Would you like to borrow a book?\n";
    cout << "1. Yes\n";
    cout << "2. No\n";
    cout << "Enter your choice: ";

    int input;
    cin >> input;

    if (cin.fail() || (input != 1 && input != 2)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid option. Returning to the previous menu.\n";
        return;
    }

    if (input == 1) {
        cout << "Enter the ID of the book you want to borrow: ";
        string bookId;
        cin >> bookId;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid book ID. Returning to the previous menu.\n";
            return;
        }

        Book bookToBorrow = catalog.getBookFromCatalog(bookId);
        if (bookToBorrow.getBookId() != "-1") {
            if (client.clientBorrowBook(bookToBorrow)) {
                cout << "You have borrowed \"" << bookToBorrow.getTitle() << "\" by " << bookToBorrow.getAuthor() << "!\n";
                cout << "Please return the book by the due date.\n";
            } else {
                cout << "Unable to borrow the book. Check your borrow limit or overdue status.\n";
            }
        } else {
            cout << "Book ID not found. Returning to the previous menu.\n";
        }
    }
}