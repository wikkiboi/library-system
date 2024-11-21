#ifndef LIBRARYCATALOG_H
#define LIBRARYCATALOG_H

#include <string>
#include <list>

#include "Book.h"

using namespace std;

class LibraryCatalog {
    private:
        list<Book> books;
    public:
        list<Book> sortBooks(const string& sortParameter);
        list<Book> searchBook(const string& searchParameter);
        
        bool addBook(Book& book);
        bool editBook(Book& oldBook, Book& newBook);
        bool removeBook(Book& book);
};

#endif
