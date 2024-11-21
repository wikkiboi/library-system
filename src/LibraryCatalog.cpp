#include "LibraryCatalog.h"
#include "Administrator.h"
#include "Book.h"
#include <iostream>
#include <fstream>
#include <random>
#include <sstream>
#include <list>

using namespace std;

bool LibraryCatalog::addBook(Book* book) {
    books.push_back(book);
}