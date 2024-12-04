#include <gtest/gtest.h>
#include "Book.h" 

#include <iostream>
#include <fstream>
#include <random>
#include <sstream>

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

TEST(BookTest, CatalogCreateTempBookFile) {
    EXPECT_NO_THROW({
        originalContent = backUpFile("data/books.csv");
        eraseFile("data/books.csv");
    });
}

TEST(BookTest, DefaultBook) {
    Book book;
    EXPECT_EQ(book.getBookId(), "-1");
}

TEST(BookTest, BookSettersAndGetters) {
    Book book;
    book.setBookId("53535");
    book.setTitle("Title");
    book.setAuthor("Author");
    book.setGenre("Genre");
    book.setSubGenre("SubGenre");
    book.setYear(2000);
    book.setAvailability(true);
    EXPECT_TRUE(
        book.getBookId() == "53535" && 
        book.getTitle() == "Title" && 
        book.getAuthor() == "Author" && 
        book.getGenre() == "Genre" && 
        book.getSubGenre() == "SubGenre" && 
        book.getYear() == 2000 &&
        book.getAvailability() == true
    );
}

TEST(BookTest, BookDetails) {
    Book book;
    book.setBookId("53535");
    book.setTitle("Title");
    book.setAuthor("Author");
    book.setGenre("Genre");
    book.setSubGenre("SubGenre");
    book.setYear(2000);
    book.setAvailability(true);
    EXPECT_TRUE(book.detailsToString() == "53535,Title,Author,Genre,SubGenre,2000,1");
}

TEST(BookTest, BookDisplay) {
    Book book;
    book.setBookId("53535");
    book.setTitle("Title");
    book.setAuthor("Author");
    book.setGenre("Genre");
    book.setSubGenre("SubGenre");
    book.setYear(2000);
    book.setAvailability(true);
    EXPECT_NO_THROW(book.displayBookInfo());
}

TEST(BookTest, BookUniqueId) {
    Book book1;
    book1.setBookId("66666");
    book1.setTitle("Title");
    book1.setAuthor("Author");
    book1.setGenre("Genre");
    book1.setSubGenre("SubGenre");
    book1.setYear(2000);
    book1.setAvailability(true);
    
    book1.addToBookCatalog();
    Book book2;
    book2.setBookId();

    EXPECT_FALSE(book1.getBookId() == book2.getBookId());
}

TEST(BookTest, BookUpdate) {
    Book book;
    book.setBookId("53535");
    book.setTitle("Title");
    book.setAuthor("Author");
    book.setGenre("Genre");
    book.setSubGenre("SubGenre");
    book.setYear(2000);
    book.setAvailability(true);
    
    book.addToBookCatalog();
    EXPECT_TRUE(
        book.updateBookDetails("UpdateTitle", "UpdateAuthor", "UpdateGenre", "UpdateSubGenre", 2020, false)
    );
    restoreFile(originalContent, "data/books.csv");
}

TEST(BookTest, CatalogRestoreOriginalBookFile) {
    EXPECT_NO_THROW({
        restoreFile(originalContent, "data/books.csv");
    });
}