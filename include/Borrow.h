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
        string bookId;
        string borrowerId;
        time_t borrowDate;
        time_t dueDate;
        string borrowDateOnly;
        string dueDateOnly;
        int renewalCount;


    public:
        bool borrowBook(const string& libraryId, Book& book);
        void displayBorrowInfo() const;
        int getRenewalCount() const { return renewalCount; };
        string getBorrowId() const { return borrowId; };
        string getDueDate() const;
        string generateUniqueBorrowId() const;
        void setBorrowId(const string& borrowId);
        void setBookId(const string& bookId);
        void setBorrowDateOnly(const string& borrowDate);
        void setDueDateOnly(const string& dueDate);
        void setRenewalCount(const int& renewalCount);
        void incrementRenewalCount();
        void setDueDate(time_t newDueDate);
        bool updateBorrowRecord() const;
        bool renewBorrow();
        bool returnBorrow();

        friend class Client;
};

#endif
