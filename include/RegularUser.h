#ifndef REGULARUSER_H
#define REGULARUSER_H

#include <string>
#include <list>
#include "User.h"
#include "Book.h"
#include "BorrowRecord.h"
#include "LibraryCatalog.h"

using namespace std;

class RegularUser : public User {
    private:
        list<BorrowRecord> borrowList;
    public:
        // Book-related functions
        void browseCatalog(LibraryCatalog& catalog);
        void borrowBook(Book& book);
        void renewBook(BorrowRecord& record);
        void returnBook(BorrowRecord& record);
};

#endif
