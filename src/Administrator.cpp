#include "Administrator.h"
#include "Book.h"
#include <iostream>
#include <fstream>
#include <random>
#include <sstream>

using namespace std;

bool Administrator::addBook(Book& book) {
    ofstream file("data/books.csv", ios::app);
    if (!file.is_open()) {
        cerr << "Error: Unable to open the file!" << endl;
        return false;
    }

    file << book.toCSV();
    file.close();

    cout << "Book added successfully!" << endl;
    cout << "Book ID: " << book.getBookId() << endl;
    return true;
}