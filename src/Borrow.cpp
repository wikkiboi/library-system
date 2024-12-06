#include "Borrow.h"
#include "Book.h"
#include "User.h"
#include <sstream>
#include <string>
#include <random>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

string timeToDate(time_t seconds) {
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", localtime(&seconds));
    return string(buffer);
}

bool Borrow::borrowBook(const string& libraryId, Book &book) {
    if(!book.getAvailability()) return false;
    this->borrowId = generateUniqueBorrowId();
    if (borrowId == "fail") return false;
    this->renewalCount = 0;
    this->book = book;
    this->borrowDate = time(nullptr);
    this->dueDate = this->borrowDate + (30 * 24 * 60 * 60);

    fstream file("data/borrow_records.csv", ios::app);
    if (!file.is_open()) {
        cerr << "Error: Unable to open the file!" << endl;
        return false;
    }

    file << borrowId << 
    "," << libraryId << "," << book.getBookId() << "," << timeToDate(borrowDate) << "," << timeToDate(dueDate) << "\n";
    file.close();
    book.setAvailability(false);
    return true;
}

string Borrow::getDueDate() const {
    return timeToDate(this->dueDate);
}

string Borrow::generateUniqueBorrowId() const {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<int> dist(10000, 99999);

    vector<string> existingIds;
    fstream inFile("data/borrow_record.csv");
    string line;
    string newBorrowId;
  
        while (getline(inFile, line)) {
            // Assuming borrowId is the first column in the CSV
            size_t pos = line.find(',');
            if (pos != string::npos) {
                existingIds.push_back(line.substr(0, pos));
            }
        }
    inFile.close();

    bool isUnique = false;
    while (!isUnique) {
        newBorrowId = to_string(dist(gen));

        if (find(existingIds.begin(), existingIds.end(), newBorrowId) == existingIds.end()) {
            isUnique = true;
        }
    }

    return newBorrowId;
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
 	if (this->borrowId.empty()) {
        cout << "Renewal failed: No borrow record found.\n";
        return false;
    }
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

bool Borrow::updateBorrowRecord() const {
    ifstream file("data/borrow_records.csv");
    if (!file.is_open()) {
        cerr << "Error: Unable to open the file for reading!" << endl;
        return false;
    }

    string line, newContent;
    while (getline(file, line)) {
        stringstream ss(line);
        string borrowId, libId, bookId, borrowDateStr, dueDateStr;
        getline(ss, borrowId, ',');
        getline(ss, libId, ',');
        getline(ss, bookId, ',');
        getline(ss, borrowDateStr, ',');
        getline(ss, dueDateStr, ',');

        if (bookId == book.getBookId()) {
            newContent += borrowId + "," + libId + "," + bookId + "," + borrowDateStr + "," + getDueDate() + "\n";
        } else {
            newContent += line + "\n";
        }
    }
    file.close();

    ofstream outFile("data/borrow_records.csv", ios::trunc);
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open the file for writing!" << endl;
        return false;
    }
    outFile << newContent;
    outFile.close();
    return true;
}

bool Borrow::returnBorrow() {
    ifstream file("data/borrow_records.csv");
    if (!file.is_open()) {
        cerr << "Error: Unable to open the file for reading!" << endl;
        return false;
    }

    string line, newContent;
    bool recordFound = false;
     while (getline(file, line)) {
        stringstream ss(line);
        string borrowId, libId, bookId, borrowDateStr, dueDateStr;
        getline(ss, borrowId, ',');
        getline(ss, libId, ',');
        getline(ss, bookId, ',');
        getline(ss, borrowDateStr, ',');
        getline(ss, dueDateStr, ',');

        if (bookId == book.getBookId()) {
            recordFound = true;
            continue;
        }
        newContent += line + "\n"; 
    }
    file.close();

    if (!recordFound) {
        cerr << "Error: No record found for the specified book ID!" << endl;
        return false;
    }

    ofstream outFile("data/borrow_records.csv", ios::trunc);
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open the file for writing!" << endl;
        return false;
    }
    outFile << newContent;
    outFile.close();
    return true;
}
