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
void Book::setAvailability(bool availability) {
    this->isAvailable = availability;             
}
void Book::setBookId() {
    this->bookId = generateUniqueBookId();
}

string Book::generateUniqueBookId() const {
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

bool Book::addToBookCatalog() const {
    ofstream outFile(filePath, ios::app);
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
    return bookId + "," + title + "," + author + "," + genre + "," + subGenre + "," + (isAvailable ? "1" : "0");
}

Book Book::getBookFromCatalog(const string& bookId) const {
    ifstream inFile(filePath);
    string line;
    Book foundBook;

    while (getline(inFile, line)) {
        size_t pos = line.find(',');
        string currentBookId = line.substr(0, pos);

        if (currentBookId == bookId) {
            size_t nextPos = line.find(',', pos + 1);
            foundBook.bookId = currentBookId;
            foundBook.title = line.substr(pos + 1, nextPos - pos - 1);

            pos = nextPos;
            nextPos = line.find(',', pos + 1);
            foundBook.author = line.substr(pos + 1, nextPos - pos - 1);

            pos = nextPos;
            nextPos = line.find(',', pos + 1);
            foundBook.genre = line.substr(pos + 1, nextPos - pos - 1);

            pos = nextPos;
            nextPos = line.find(',', pos + 1);
            foundBook.subGenre = line.substr(pos + 1, nextPos - pos - 1);

            foundBook.isAvailable = line.substr(nextPos + 1) == "1";  // '1' means available

            break;
        }
    }

    inFile.close();
    return (foundBook.bookId == bookId) ? foundBook : Book();
}

bool Book::updateBookCatalog(vector<Book>& catalog) const {
    ofstream outFile(filePath);
    for (const auto& book: catalog) {
        outFile << book.detailsToString() << endl;
    }

    return true;
}

bool Book::updateBookDetails(const string& title, const string& author, const string& genre, const string& subGenre) const {
    Book myBook;
    vector<Book> catalog = myBook.loadBookCatalog();
    
    for (auto& book: catalog) {
        if (book.bookId == this->bookId) {
            if (!title.empty()) book.setTitle(title);
            if (!author.empty()) book.setAuthor(author);
            if (!genre.empty()) book.setGenre(genre);
            if (!subGenre.empty()) book.setSubGenre(subGenre);
            return updateBookCatalog(catalog);
        }
    }

    return false;
}

vector<Book> Book::loadBookCatalog() {
    ifstream inFile(filePath);
    string line;
    vector<Book> books;

    while (getline(inFile, line)) {
        Book book;
        stringstream ss(line);
        string value;

        getline(ss, book.bookId, ',');
        getline(ss, book.title, ',');
        getline(ss, book.author, ',');
        getline(ss, book.genre, ',');
        getline(ss, book.subGenre, ',');
        getline(ss, value, ',');
        book.isAvailable = (value == "1");

        books.push_back(book);
    }

    return books;
}
