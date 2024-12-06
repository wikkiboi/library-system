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
        vector<Book> bookHistory;
    public:
        Client() {};
        Client(const User& user);
        vector<Book> loadClientsBookHistory() { return bookHistory; };
        vector<Borrow> loadClientsBorrowList();
        Borrow getBookFromBorrowList(const string& borrowId) const;
        bool clientBorrowBook(Book& book);
        bool clientRenewBook(Borrow& record);
        bool clientReturnBook(Borrow& record);
};

#endif