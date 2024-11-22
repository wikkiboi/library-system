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
        Borrow borrowBook(Book& book);
        void renewBook(Borrow& record);
        void returnBook(Borrow& record);
};

#endif