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
        Book();
        void displayBookInfo() const;
        void addTitle(const string& title);
        void addAuthor(const string& author);
        void addGenre(const string& genre);
        void addSubGenre(const string& subGenre);
        void setAvailability(bool availability);
        void setBookId();
        string generateUniqueBookId();
        void saveToCSV() const;
};

#endif