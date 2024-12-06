#include <gtest/gtest.h>
#include "Book.h" 
#include "Admin.h"
#include "Catalog.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <random>
#include <sstream>
#include <algorithm>

using namespace std;

inline string originalContent;

inline string backUpFile(const string& filePath) {
    ifstream inputFile(filePath);
    string originalContent;
    if (inputFile.is_open()) {
        stringstream buffer;
        buffer << inputFile.rdbuf();
        originalContent = buffer.str();
        inputFile.close();
    }
    return originalContent;
}

inline void eraseFile(const string& filePath) {
    ofstream outFile(filePath, ios::out);
    if (!outFile) {
        cerr << "Error opening file: " << filePath << endl;
        return;
    }
    outFile.close();
}

inline void restoreFile(const string& originalContent, const string& filePath) {
    ofstream restoreFile(filePath);
    if (restoreFile.is_open()) {
        restoreFile << originalContent;
        restoreFile.close();
    }
}

TEST(CatalogTest, CatalogCreateTempBookFile) {
    EXPECT_NO_THROW({
        originalContent = backUpFile("data/books.csv");
        eraseFile("data/books.csv");
    });
}

TEST(CatalogTest, GetBookFromCatalog) {
    Admin admin;
    Catalog catalog;

    string bookId = "54321";
    string title = "Test Book";
    string author = "Test Author";
    string genre = "Fiction";
    string subGenre = "Fantasy";    
    int year = 1970;
    bool isAvailable = true;
    bool addBookSuccess = admin.addBookNoId(bookId, title, author, genre, subGenre, year, isAvailable);

    Book bookFromCatalog;
    EXPECT_NO_THROW({
        bookFromCatalog = catalog.getBookFromCatalog(bookId);
    });
}

TEST(CatalogTest, DeleteBookFromCatalog) {
    Admin admin;
    Catalog catalog;

    EXPECT_TRUE(catalog.deleteBookFromCatalog("54321"));
}

TEST(CatalogTest, AddMultipleBooks) {
    Admin admin;
    Catalog catalog;

    admin.addBookNoId("11111", "Title", "AuthorA", "GenreC", "SubGenre", 1990, false);
    admin.addBookNoId("22222", "Title", "AuthorB", "GenreB", "SubGenre", 2000, false);
    admin.addBookNoId("33333", "Title", "AuthorC", "GenreA", "SubGenre", 1980, false);
}

TEST(CatalogTest, LoadBookCatalog) {
    Catalog catalog;
    EXPECT_NO_THROW(vector<Book> books = catalog.loadBookCatalog());
}

TEST(CatalogTest, SortByAuthor) {
    Catalog catalog;

    vector<Book> books = catalog.loadBookCatalog();
    vector<Book> sortedBooks = catalog.sortCatalogByAuthor(books);
    EXPECT_TRUE((is_sorted(sortedBooks.begin(), sortedBooks.end(), [](const Book& a, const Book& b) {
            return a.getAuthor() <= b.getAuthor();
        })));
}

TEST(CatalogTest, SortByGenre) {
    Catalog catalog;

    vector<Book> books = catalog.loadBookCatalog();
    vector<Book> sortedBooks = catalog.sortCatalogByGenre(books);
    EXPECT_TRUE((is_sorted(sortedBooks.begin(), sortedBooks.end(), [](const Book& a, const Book& b) {
            return a.getGenre() <= b.getGenre();
        })));
}

TEST(CatalogTest, SortByYear) {
    Catalog catalog;

    vector<Book> books = catalog.loadBookCatalog();
    vector<Book> sortedBooks = catalog.sortCatalogByYear(books);
    EXPECT_TRUE((is_sorted(sortedBooks.begin(), sortedBooks.end(), [](const Book& a, const Book& b) {
            return a.getYear() <= b.getYear();
        })));
}

TEST(CatalogTest, BookRecommendations) {
    Client client;
    Catalog catalog;
    EXPECT_NO_THROW(catalog.getBookRecommendations(client));
}

TEST(CatalogTest, CatalogRestoreOriginalBookFile) {
    EXPECT_NO_THROW({
        restoreFile(originalContent, "data/books.csv");
    });
}