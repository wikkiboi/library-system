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

        int getRenewalCount() const { return renewalCount; };
        string getBorrowId() const { return borrowId; };
        string getDueDate() const;
        string generateUniqueBorrowId() const;
        void incrementRenewalCount();
        void setDueDate(time_t newDueDate);
        bool updateBorrowRecord() const;
        bool renewBorrow();
        bool returnBorrow();

        friend class Client;
};

#endif
