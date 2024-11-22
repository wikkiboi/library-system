#ifndef BOOK_H
#define BOOK_H
#include <vector>
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
    
    //private:
        void setTitle(const string& title);
        void setAuthor(const string& author);
        void setGenre(const string& genre);
        void setSubGenre(const string& subGenre);
        void setAvailability(bool availability);
        void setBookId();
        void setBookId(const string& bookId);

        bool getAvailability() const;
        string getBookId() const;
        string getTitle() const;
        string getAuthor() const;
        string getGenre() const;
        string getSubGenre() const;

        bool addToBookCatalog() const;
        string detailsToString() const;
        string generateUniqueBookId() const;

        bool updateBookDetails(const string& title, const string& author, const string& genre, const string& subGenre);

        friend class Admin;
};

#endif
