#include "screens/BorrowReturnScreen.h"
#include <iostream>

BorrowReturnScreen::BorrowReturnScreen(Client& client) : client(client) {};

void BorrowReturnScreen::render() {
    vector<Borrow> borrowList = client.loadClientsBorrowList();

    if (borrowList.empty()) {
        cout << "No borrowed books to return. Check out the catalog to borrow one!\n";
        return;
    }

    for (const auto& borrow : borrowList) {
        borrow.displayBorrowInfo();
        cout << "\n";
    }

    while (true) {
        cout << "Enter Borrow ID of the book to return (Enter empty input to return to dashboard): ";
        string borrowId;
        getline(cin, borrowId);

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid option.\n";
        } else {
            if (borrowId != "") {
                Borrow borrow;
                borrow = client.getBookFromBorrowList(borrowId);

                if (borrow.returnBorrow()) {
                    cout << "Book returned successfully!\n";
                }
            } else if (borrowId == "") {
                break;
            }

            break;
        }
    }

    cin.clear();
    return;
}