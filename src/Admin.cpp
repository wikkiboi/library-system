#include "Admin.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "Book.h"
#include "Catalog.h"

Admin::Admin(const User& user) : User(user.getUsername(), user.getPassword()) {
        this->userId = user.getUserId();
        this->libraryId = user.getLibraryId();
        this->loggedIn = user.getLoggedIn();
    }

bool Admin::addBookNoId(const string& bookId, const string& title, const string& author, const string& genre, const string& subGenre, const int& year, const bool& isAvailable) const {
    Book newBook;
    newBook.setTitle(title);
    newBook.setAuthor(author);
    newBook.setGenre(genre);
    newBook.setSubGenre(subGenre);
    newBook.setYear(year);
    newBook.setAvailability(isAvailable);
    newBook.setBookId(bookId);
    return newBook.addToBookCatalog();
}

bool Admin::addBook(const string& title, const string& author, const string& genre, const string& subGenre, const int& year, const bool& isAvailable) const {
    Book newBook;
    newBook.setTitle(title);
    newBook.setAuthor(author);
    newBook.setGenre(genre);
    newBook.setSubGenre(subGenre);
    newBook.setYear(year);
    newBook.setAvailability(isAvailable);
    newBook.setBookId();
    return newBook.addToBookCatalog();
}

bool Admin::editBook(const string& bookId, const string& title, const string& author, const string& genre, const string& subGenre, const int& year, const bool& isAvailable) const {
    Catalog catalog;
    Book bookToUpdate = catalog.getBookFromCatalog(bookId);
    bookToUpdate.setTitle(title);
    bookToUpdate.setAuthor(author);
    bookToUpdate.setGenre(genre);
    bookToUpdate.setSubGenre(subGenre);
    bookToUpdate.setYear(year);
    bookToUpdate.setAvailability(isAvailable);

    return bookToUpdate.updateBookDetails(title, author, genre, subGenre, year, isAvailable);
}

bool Admin::deleteBook(const string& bookId) const {
    Catalog catalog;
    return catalog.deleteBookFromCatalog(bookId); 
}