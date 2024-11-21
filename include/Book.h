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
        void setTitle(const string& title);
        void setAuthor(const string& author);
        void setGenre(const string& genre);
        void setSubGenre(const string& subGenre);
        void setAvailability(bool availability);
        void setBookId();
        string detailsToString() const;
        string generateUniqueBookId();
        vector<Book> loadBookCatalog();
        bool addToBookCatalog() const;
        bool updateBookCatalog(vector<Book>& catalog) const;
        bool updateBookDetails(const string& bookId, const string& title, const string& author, const string& genre, const string& subGenre) const;
};

#endif