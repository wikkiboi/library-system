#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include "User.h"
#include "Book.h"

using namespace std;

class Administrator : public User {
    public:
        // Book-related functions
        bool addBook(Book& book);
        bool editBook(Book& oldBook, Book& newBook);
        bool removeBook(Book& book);
};

#endif
