#include "screens/BorrowEditScreen.h"
#include <iostream>

BorrowEditScreen::BorrowEditScreen(Client& client, Borrow& borrow): client(client), borrow(borrow) {};

void BorrowEditScreen::render() {
    while (true) {
        cout << "Enter Borrow ID of the book to return/renew: ";
        string bookId;
        cin >> bookId;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid option.\n";
        } else {
            if (bookId == "") {
                // Call the renew function
                if (borrow.renewBorrow()) {
                    cout << "Book renewed successfully!\n";
                } else {
                    cout << "You have reached the maximum renewal limit.\n";
                }
            } else if (bookId == "") {
                break;
            }

            break;
        }
    }
}