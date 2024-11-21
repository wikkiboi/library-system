#include "Admin.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "Book.h"

bool Admin::addBook(const string& bookId, const string& title, const string& author, const string& genre, const string& subGenre, bool isAvailable) {
    Book newBook;
    newBook.addTitle(title);
    newBook.addAuthor(author);
    newBook.addGenre(genre);
    newBook.addSubGenre(subGenre);
    newBook.setAvailability(true);
    if (newBook.saveToCSV()) {
        cout << "Book successfully added to the catalog.\n";
    }
}