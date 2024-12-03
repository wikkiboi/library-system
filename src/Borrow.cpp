#include "Borrow.h"
#include "Book.h"
#include "User.h"
#include <sstream>

#include <string>
#include <iostream>
#include <fstream>
#include <random>

using namespace std;

string timeToDate(time_t seconds) {
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", localtime(&seconds));
    return string(buffer);
}

Borrow::Borrow() {
    this->borrowId = -1;
}

Borrow::Borrow(const string& libraryId, Book &book) {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<int> dist(10000, 99999);

    this->borrowId = dist(gen);
    this->renewalCount = 0;
    this->book = book;

    this->borrowDate = time(nullptr);
    this->dueDate = this->borrowDate + (30 * 24 * 60 * 60);

    ofstream file("data/borrow_records.csv", ios::app);
    if (!file.is_open()) {
        cerr << "Error: Unable to open the file!" << endl;
    }

    file << libraryId << "," << book.getBookId() << "," << timeToDate(borrowDate) << "," << timeToDate(dueDate) << "\n";
    file.close();
}

string Borrow::getDueDate() const {
    return timeToDate(this->dueDate);
}

int Borrow::getBorrowId() {
    return this->borrowId;
}

int Borrow::getRenewalCount() const {
    return this->renewalCount;
}

void Borrow::incrementRenewalCount() {
    this->renewalCount++;
}

void Borrow::setDueDate(time_t newDueDate) {
    this->dueDate = newDueDate;
}

bool Borrow::renewBorrow() {
    const int MAX_RENEWALS = 3;
    const int ONE_WEEK_SECONDS = 7 * 24 * 60 * 60;

    if (renewalCount >= MAX_RENEWALS) {
        cout << "Renewal failed: Maximum renewals reached.\n";
        return false;
    }

    this->dueDate += ONE_WEEK_SECONDS;
    this->renewalCount++;

    // Update the borrow record in the file
    updateBorrowRecord();
    cout << "Renewal successful. New due date: " << getDueDate() << "\n";
    return true;
}

void Borrow::updateBorrowRecord() const {
    ifstream file("data/borrow_records.csv");
    if (!file.is_open()) {
        cerr << "Error: Unable to open the file for reading!" << endl;
        return;
    }

    string line, newContent;
    while (getline(file, line)) {
        stringstream ss(line);
        string libId, bookId, borrowDateStr, dueDateStr;
        getline(ss, libId, ',');
        getline(ss, bookId, ',');
        getline(ss, borrowDateStr, ',');
        getline(ss, dueDateStr, ',');

        if (bookId == book.getBookId()) {
            newContent += libId + "," + bookId + "," + borrowDateStr + "," + getDueDate() + "\n";
        } else {
            newContent += line + "\n";
        }
    }
    file.close();

    ofstream outFile("data/borrow_records.csv", ios::trunc);
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open the file for writing!" << endl;
        return;
    }
    outFile << newContent;
    outFile.close();
}
