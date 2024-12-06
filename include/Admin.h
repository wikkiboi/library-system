#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "User.h"
#include "Book.h"
using namespace std;

class Admin: public User {
    public:
        Admin() {};
        Admin(const string& username, const string& password);
        bool addBookNoId(const string& bookId, const string& title, const string& author, const string& genre, const string& subGenre, const int& year, const bool& isAvailable) const;
        bool addBook(const string& title, const string& author, const string& genre, const string& subGenre, const int& year, const bool& isAvailable) const;
        bool editBook(const string& bookId, const string& newTitle, const string& newAuthor, const string& newGenre, const string& newSubGenre, const int& year, const bool& isAvailable) const;
        bool deleteBook(const string& bookId) const;
};

#endif