#ifndef BORROWRECORD_H
#define BORROWRECORD_H

#include <string>
#include <ctime>
#include "Book.h"

using namespace std;

class BorrowRecord {
    private:
        int borrowId;
        Book book;
        time_t borrowDate;
        time_t dueDate;
        int renewalCount;
    
    public:
        BorrowRecord(const string& libraryId, Book& book);
        void renew();
        bool isOverdue();
};

#endif
