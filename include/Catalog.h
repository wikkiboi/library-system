#ifndef CATALOG_H
#define CATALOG_H
#include <vector>
#include <string>
#include "Book.h"
#include "Borrow.h"
#include "Client.h"
using namespace std;

class Catalog {
    private:
        vector<Book> books;
    public:
        Book getBookFromCatalog(const string& bookId) const;
        vector<Book> loadBookCatalog();
        vector<Book> getBookRecommendations(Client client);
        bool updateBookCatalog(vector<Book>& catalog) const;
        bool deleteBookFromCatalog(const string& bookId);
	    static vector<Book> sortCatalogByAuthor(const vector<Book>& catalog);
	    static vector<Book> sortCatalogByGenre(const vector<Book>& catalog);
        static vector<Book> sortCatalogByYear(const vector<Book>& catalog);
        friend class Admin;
};

#endif
