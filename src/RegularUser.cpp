#include "RegularUser.h"
#include "User.h"
#include "BorrowRecord.h"
#include "Book.h"
#include <iostream>
#include <fstream>
#include <random>
#include <sstream>

using namespace std;

void RegularUser::borrowBook(Book& book) {
    if (book.getIsAvailable())
        BorrowRecord record = BorrowRecord(this->libraryId, book);
}