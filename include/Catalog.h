#ifndef CATALOG_H
#define CATALOG_H
#include <vector>
#include <string>
#include "Book.h"
using namespace std;

class Catalog {
    private:
        string filePath = "data/books.csv";

    public:
        Book getBookFromCatalog(const string& bookId) const;
        vector<Book> loadBookCatalog();
        bool updateBookCatalog(vector<Book>& catalog) const;
        bool updateBookDetails(const string& title, const string& author, const string& genre, const string& subGenre);
        bool deleteBookFromCatalog(const string& bookId);
	    static vector<Book> sortCatalogByAuthor(const vector<Book>& catalog);
	    static vector<Book> sortCatalogByGenre(const vector<Book>& catalog);
        friend class Admin;
};

#endif
