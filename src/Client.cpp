#include "Client.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Book.h"
#include "Borrow.h"

using namespace std;

bool Client::clientBorrowBook(Book& book) {
    Borrow borrow;
    if (book.getAvailability()) {
        if (borrow.borrowBook(this->libraryId, book) != true) return false;
        borrowList.push_back(borrow);
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
            return false;
        } else {
            cerr << "Error: Unable to renew the book!" << endl;
            return false;
        }
    }

    cerr << "Error: No matching borrow record found in borrow list" << endl;
    return false;
}