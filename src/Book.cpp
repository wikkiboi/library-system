#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <random>
#include <vector>
#include <algorithm>
#include "Book.h"

using namespace std;

Book::Book() {};
    // Display Book Info
void Book::displayBookInfo() const {
    cout << "Book ID: " << bookId << "\n"
            << "Title: " << title << "\n"
            << "Author: " << author << "\n"
            << "Genre: " << genre << "\n"
            << "Sub-Genre: " << subGenre << "\n"
            << "Available: " << (isAvailable ? "Yes" : "No") << "\n";
}

// Methods to add or modify book details
void Book::addTitle(const string& title) { 
    this->title = title;
}
void Book::addAuthor(const string& author) { 
    this->author = author;
}
void Book::addGenre(const string& genre) { 
    this->genre = genre; 
}
void Book::addSubGenre(const string& subGenre) {
    this->subGenre = subGenre;
}
void Book::setAvailability(bool availability) {
    this->isAvailable = availability;             
}
void Book::setBookId() {
    this->bookId = generateUniqueBookId();
}

string Book::generateUniqueBookId() {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<int> dist(10000, 99999);

    vector<string> existingIds;
    ifstream inFile(this->filePath);
    string line;
    string newBookId;
    if (inFile.good()) {
        while (getline(inFile, line)) {
            // Assuming bookId is the first column in the CSV
            size_t pos = line.find(',');
            if (pos != string::npos) {
                existingIds.push_back(line.substr(0, pos));
            }
        }
    }
    inFile.close();

    bool isUnique = false;
    while (!isUnique) {
        newBookId = to_string(dist(gen));

        if (find(existingIds.begin(), existingIds.end(), newBookId) == existingIds.end()) {
            isUnique = true;
        }
    }

    return newBookId;
}

void Book::saveToCSV() const {
    ofstream outFile(filePath, ios::app);
    if (outFile.is_open()) {
        outFile << bookId << "," << title << "," << author << "," << genre << ","
                << subGenre << "," << (isAvailable ? "1" : "0") << "\n";
        outFile.close();
    } else {
        cerr << "Error: Unable to open books.csv file.\n";
    }
}
