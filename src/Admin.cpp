#include "Admin.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "Book.h"
#include "Catalog.h"

bool Admin::addBook(const string& bookId, const string& title, const string& author, const string& genre, const string& subGenre, bool isAvailable) const {
    Book newBook;
    newBook.setTitle(title);
    newBook.setAuthor(author);
    newBook.setGenre(genre);
    newBook.setSubGenre(subGenre);
    newBook.setAvailability(true);
    newBook.setBookId(bookId);
    return newBook.addToBookCatalog();
}

bool Admin::addBook(const string& title, const string& author, const string& genre, const string& subGenre, bool isAvailable) const {
    Book newBook;
    newBook.setTitle(title);
    newBook.setAuthor(author);
    newBook.setGenre(genre);
    newBook.setSubGenre(subGenre);
    newBook.setAvailability(true);
    newBook.setBookId();
    return newBook.addToBookCatalog();
}

bool Admin::editBook(const string& bookId, const string& newTitle, const string& newAuthor, const string& newGenre, const string& newSubGenre, bool isAvailable) const {
    Catalog catalog;
    Book bookToUpdate = catalog.getBookFromCatalog(bookId);

    return bookToUpdate.updateBookDetails(newTitle, newAuthor, newGenre, newSubGenre);
}

bool Admin::deleteBook(const string& bookId) const {
    Catalog catalog;
    return catalog.deleteBookFromCatalog(bookId); 
}