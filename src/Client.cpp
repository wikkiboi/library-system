#include "Client.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Book.h"
#include "Catalog.h"
#include "Borrow.h"

using namespace std;

Client::Client(const User& user) : User(user.getUsername(), user.getPassword()) {
        this->userId = user.getUserId();
        this->libraryId = user.getLibraryId();
        this->loggedIn = user.getLoggedIn();
    }

vector<Borrow> Client::loadClientsBorrowList() {
    ifstream inFile("data/borrow_records.csv");
    string line;
    vector<Borrow> borrowList;

    while (getline(inFile, line)) {
        Borrow borrow;
        stringstream ss(line);
        string value;

        string borrowId;
        string borrowDate;
        string dueDate;
        string borrowerId;
        string bookId;

        getline(ss, borrowId, ',');
        getline(ss, borrowerId, ',');
        getline(ss, bookId, ',');
        getline(ss, borrowDate, ',');
        getline(ss, dueDate, ',');
        
        if (libraryId == borrowerId) {
            borrow.setBorrowId(borrowId);
            borrow.setBorrowDateOnly(borrowDate);
            borrow.setDueDateOnly(dueDate);
            borrow.setBookId(bookId);

            borrowList.push_back(borrow);
        }
    }

    return borrowList;
}

Borrow Client::getBookFromBorrowList(const string& borrowId) const {
    ifstream inFile("data/borrow_records.csv");
    string line;
    Borrow borrowRecord;

    while (getline(inFile, line)) {
        size_t pos = line.find(',');
        string currentBookId = line.substr(0, pos);

        if (currentBookId == borrowId) {
            size_t nextPos = line.find(',', pos + 1);
            borrowRecord.setBorrowId(currentBookId);

            pos = nextPos;
            nextPos = line.find(',', pos + 1);
            borrowRecord.setBookId(line.substr(pos + 1, nextPos - pos - 1));

            pos = nextPos;
            nextPos = line.find(',', pos + 1);
            borrowRecord.setBorrowDateOnly(line.substr(pos + 1, nextPos - pos - 1));

            pos = nextPos;
            nextPos = line.find(',', pos + 1);
            borrowRecord.setDueDateOnly(line.substr(pos + 1, nextPos - pos - 1));

            break;
        }
    }

    return borrowRecord;
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