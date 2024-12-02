#ifndef BORROW_H
#define BORROW_H

#include <string>
#include <ctime>
#include "Book.h"

using namespace std;

class Borrow {
    private:
        int borrowId;
        Book book;
        time_t borrowDate;
        time_t dueDate;
        int renewalCount;


    public:
        Borrow();
        Borrow(const string& libraryId, Book& book);

        string getDueDate();
        int getBorrowId();
        int getRenewalCount();
        void incrementRenewalCount();
        void setDueDate(time_t newDueDate);
        bool renewBorrow();
        void updateBorrowRecord();
};

#endif
