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
        int year;
        bool isAvailable;

    public:
        Book();
        void displayBookInfo() const;

        //Setters 
        void setTitle(const string& title);
        void setAuthor(const string& author);
        void setGenre(const string& genre);
        void setSubGenre(const string& subGenre);
        void setAvailability(const bool& availability);
        void setYear(const int& year);
        void setBookId();
        void setBookId(const string& bookId);

        //Getters
        bool getAvailability() const;
        string getBookId() const;
        string getTitle() const;
        string getAuthor() const;
        string getGenre() const;
        string getSubGenre() const;
        int getYear() const;

        bool addToBookCatalog() const;
        bool updateBookDetails(const string& title, const string& author, const string& genre, const string& subGenre, const int& year, const bool& isAvailable);
        string detailsToString() const;
        string generateUniqueBookId() const;

        friend class Admin;
};

#endif
