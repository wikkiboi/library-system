#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "User.h"
#include "Book.h"
using namespace std;

class Admin: public User {
    public:
        bool addBook(const string& bookId, const string& title, const string& author, const string& genre, const string& subGenre, bool isAvailable);
        bool editBook(const string& bookId, const string& newTitle, const string& newAuthor, const string& newGenre, const string& newSubGenre, bool isAvailable);
        bool deleteBook(const string& bookId);
        string generateUniqueBookId();
};

#endif