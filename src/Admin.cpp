#include "Admin.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "Book.h"

bool Admin::addBook(const string& bookId, const string& title, const string& author, const string& genre, const string& subGenre, bool isAvailable) const {
    Book newBook;
    newBook.setTitle(title);
    newBook.setAuthor(author);
    newBook.setGenre(genre);
    newBook.setSubGenre(subGenre);
    newBook.setAvailability(true);
    return newBook.addToBookCatalog();
}

bool Admin::editBook(const string& bookId, const string& newTitle, const string& newAuthor, const string& newGenre, const string& newSubGenre, bool isAvailable) const {
    Book book;
    Book bookToUpdate = book.getBookFromCatalog(bookId);

    return bookToUpdate.updateBookDetails(newTitle, newAuthor, newGenre, newSubGenre);
}

bool Admin::deleteBook(const string& bookId) const {
    Book book;
    return book.deleteBookFromCatalog(bookId); 
}