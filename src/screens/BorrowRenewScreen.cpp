#include "screens/BorrowRenewScreen.h"
#include <iostream>

BorrowRenewScreen::BorrowRenewScreen(Client& client) : client(client) {};

void BorrowRenewScreen::render() {
    vector<Borrow> borrowList = client.loadClientsBorrowList();

    for (const auto& borrow : borrowList) {
        borrow.displayBorrowInfo();
        cout << "\n";
    }

    while (true) {
        cout << "Enter Borrow ID of the book to renew (Enter empty input to return to dashboard): ";
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

                if (borrow.renewBorrow()) {
                    cout << "Book renewed successfully!\n";
                } else {
                    cout << "You have reached the maximum renewal limit.\n";
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