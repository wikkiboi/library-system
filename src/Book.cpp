#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <random>
#include <vector>
#include <algorithm>
#include "Book.h"
#include "Catalog.h"

using namespace std;

Book::Book() {
    this->bookId = "-1";
};
    // Display Book Info
void Book::displayBookInfo() const {
    cout << "Book ID: " << bookId << "\n"
            << "Title: " << title << "\n"
            << "Author: " << author << "\n"
            << "Genre: " << genre << "\n"
            << "Sub-Genre: " << subGenre << "\n"
            << "Year Published: " << year << "\n"
            << "Available: " << (isAvailable ? "Yes" : "No") << "\n";
}

// Methods to add or modify book details
void Book::setTitle(const string& title) { 
    this->title = title;
}
void Book::setAuthor(const string& author) { 
    this->author = author;
}
void Book::setGenre(const string& genre) { 
    this->genre = genre; 
}
void Book::setSubGenre(const string& subGenre) {
    this->subGenre = subGenre;
}
void Book::setAvailability(const bool& availability) {
    this->isAvailable = availability;             
}
void Book::setYear(const int& year) {
    this->year = year;             
}
void Book::setBookId() {
    this->bookId = generateUniqueBookId();
}
void Book::setBookId(const string& bookId) {
    this->bookId = bookId;
}

bool Book::getAvailability() const {
    return this->isAvailable;
}

string Book::getBookId() const {
    return this->bookId;
}

string Book::getTitle() const {
    return this->title;
}
string Book::getAuthor() const{
    return this->author;
}
string Book::getGenre() const{
    return this->genre;
}
string Book::getSubGenre() const{
    return this->subGenre;
}
int Book::getYear() const{
    return this->year;
}

string Book::generateUniqueBookId() const {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<int> dist(10000, 99999);

    vector<string> existingIds;
    ifstream inFile("data/books.csv");
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

bool Book::addToBookCatalog() const {
    ofstream outFile("data/books.csv", ios::app);
    if (outFile.is_open()) {
        outFile << detailsToString() << "\n";
        outFile.close();
    } else {
        cerr << "Error: Unable to open books.csv file.\n";
        return false;
    }

    return true;
}

string Book::detailsToString() const {
    return bookId + "," + title + "," + author + "," + genre + "," + subGenre + "," + to_string(year) + "," + (isAvailable ? "1" : "0");
}

bool Book::updateBookDetails(const string& title, const string& author, const string& genre, const string& subGenre, const int& year,  const bool& isAvailable) {
    Catalog catalog;
    vector<Book> books = catalog.loadBookCatalog();
    
    for (auto& book: books) {
        if (book.bookId == this->bookId) {
            if (!title.empty()) book.setTitle(title);
            if (!author.empty()) book.setAuthor(author);
            if (!genre.empty()) book.setGenre(genre);
            if (!subGenre.empty()) book.setSubGenre(subGenre);
            if (year != 0) book.setYear(year);
            book.setAvailability(isAvailable);
            return catalog.updateBookCatalog(books);
        }
    }

    return false;
}