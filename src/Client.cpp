#include "Client.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Book.h"
#include "Catalog.h"
#include "Borrow.h"

using namespace std;

Client::Client(const User& user) : User(user.getUsername(), user.getPassword()) {
        this->userId = user.getUserId();
        this->libraryId = user.getLibraryId();
        this->loggedIn = user.getLoggedIn();
    }

bool Client::clientBorrowBook(Book& book) {
    Borrow borrow;
    if (book.getAvailability()) {
        if (borrow.borrowBook(this->libraryId, book) != true) return false;
        borrowList.push_back(borrow);
        bookHistory.push_back(book);
    } else {
        cout << "Book is not available" << endl;
        return false;
    }
    return true;
}

bool Client::clientRenewBook(Borrow& record) {
    auto it = find_if(borrowList.begin(), borrowList.end(), [&record](const Borrow& borrow) {
        return borrow.getBorrowId() == record.getBorrowId();
    });

    if (it != borrowList.end()) {
        if (it->renewBorrow()) {
            cout << "Book successfully renewed" << endl;
            return true;
        } else {
            cerr << "Error: Unable to renew the book!" << endl;
            return false;
        }
    }

    cerr << "Error: No matching borrow record found in borrow list" << endl;
    return false;
}

bool Client::clientReturnBook(Borrow &record) {
    auto it = remove_if(borrowList.begin(), borrowList.end(), [&record](const Borrow& borrow) {
        return borrow.getBorrowId() == record.getBorrowId();
    });

    if (it != borrowList.end()) {
        if (!record.returnBorrow()) {
            cerr << "Error: Unable to complete the return process" << endl;
            return false;
        }

        borrowList.erase(it, borrowList.end());
        cout << "Book successfully returned and removed from borrow list" << endl;
        return true;
    }

    cerr << "Error: Borrow record not found in borrow list" << endl;
    return false;
}