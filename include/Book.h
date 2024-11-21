#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
    private:
        int bookId;

        string title;
        string author;
        string genre;
        int year;

        bool isAvailable;
    
    public:
        // Book-related functions
        Book();
        Book(const string& title, const string& author, const string& genre, const int& year);
        
        int getBookId() const;
        string getTitle() const;
        string getAuthor() const;
        string getGenre() const;
        int getYear() const;

        bool getIsAvailable() const;
        void borrowBook();
        void returnBook();

        string toCSV() const;

        void displayBookInfo();
};

#endif
