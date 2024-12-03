#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include "User.h"
#include "Book.h"
#include "Borrow.h"
#include "Catalog.h"
using namespace std;

class Client: public User {
    private:
        vector<Borrow> borrowList;
    public:
        void browseCatalog(Catalog& catalog);
        bool clientBorrowBook(Book& book);
        bool clientRenewBook(Borrow& record);
        bool clientReturnBook(Borrow& record);
};

#endif