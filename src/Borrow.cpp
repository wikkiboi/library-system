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

string Borrow::getDueDate() {
    return timeToDate(this->dueDate);
}

int Borrow::getBorrowId() {
    return this->borrowId;
}