#ifndef BORROW_H
#define BORROW_H

#include <string>
#include <ctime>
#include "Book.h"

using namespace std;

class Borrow {
    private:
        string borrowId;
        Book book;
        time_t borrowDate;
        time_t dueDate;
        int renewalCount;


    public:
        bool borrowBook(const string& libraryId, Book& book);

        string getDueDate() const;
        string generateUniqueBorrowId() const;
        string getBorrowId() const;
        int getRenewalCount() const;
        void incrementRenewalCount();
        void setDueDate(time_t newDueDate);
        bool updateBorrowRecord() const;
        bool renewBorrow();
        bool returnBorrow();

        friend class Client;
};

#endif
