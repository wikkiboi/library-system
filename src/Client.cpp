#include "Client.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "Book.h"
#include "Borrow.h"

Borrow Client::borrowBook(Book& book) {
    if (book.getAvailability()) {
        Borrow record = Borrow(this->libraryId, book);
        return record;
    }
    return Borrow();
}