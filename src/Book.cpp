#include "Book.h"
#include <sstream>

#include <string>
#include <iostream>
#include <fstream>
#include <random>

using namespace std;

Book::Book() {

}

Book::Book(const string &title, const string &author, const string &genre, const int &year)
    : title(title), author(author), genre(genre), year(year) {
    // Validate input
    if (title.empty() || author.empty() || genre.empty() || year <= 0) {
        throw invalid_argument("Error: Title, author, genre, and year must not be empty!");
    }

    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<int> dist(10000, 99999);

    this->bookId = dist(gen);
}

int Book::getBookId() const {
    return this->bookId;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getGenre() const {
    return genre;
}

int Book::getYear() const { 
    return year; 
}

bool Book::getIsAvailable() const {
    return this->isAvailable;
}

void Book::borrowBook() { 
    this->isAvailable = false;
}

void Book::borrowBook() { 
    this->isAvailable = true;
}

string Book::toCSV() const {
    std::ostringstream oss;
    oss << bookId << "," << title << "," << author << "," << genre << "," << year << "\n";
    return oss.str();
}
