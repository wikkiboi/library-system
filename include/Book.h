#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
    private:
        string bookId;
        string title;
        string author;
        string genre;
        string subGenre;
        bool isAvailable;
        string filePath = "data/books.csv";

    public:
        void displayBookInfo();
    
};

#endif