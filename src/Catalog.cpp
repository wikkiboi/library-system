#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <random>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include "Book.h"
#include "Client.h"
#include "Borrow.h"
#include "Catalog.h"

Book Catalog::getBookFromCatalog(const string& bookId) const {
    ifstream inFile("data/books.csv");
    string line;
    Book foundBook;

    while (getline(inFile, line)) {
        size_t pos = line.find(',');
        string currentBookId = line.substr(0, pos);

        if (currentBookId == bookId) {
            size_t nextPos = line.find(',', pos + 1);
            foundBook.setBookId(currentBookId);
            foundBook.setTitle(line.substr(pos + 1, nextPos - pos - 1));

            pos = nextPos;
            nextPos = line.find(',', pos + 1);
            foundBook.setAuthor(line.substr(pos + 1, nextPos - pos - 1));

            pos = nextPos;
            nextPos = line.find(',', pos + 1);
            foundBook.setGenre(line.substr(pos + 1, nextPos - pos - 1));

            pos = nextPos;
            nextPos = line.find(',', pos + 1);
            foundBook.setSubGenre(line.substr(pos + 1, nextPos - pos - 1));

            pos = nextPos;
            nextPos = line.find(',', pos + 1);
            foundBook.setYear(stoi(line.substr(pos + 1, nextPos - pos - 1)));

            foundBook.setAvailability(line.substr(nextPos + 1) == "1");  // '1' means available

            break;
        }
    }

    inFile.close();
    return (foundBook.getBookId() == bookId) ? foundBook : Book();
}

bool Catalog::updateBookCatalog(vector<Book>& catalog) const {
    ofstream outFile("data/books.csv");
    for (const auto& book: catalog) {
        outFile << book.detailsToString() << endl;
    }

    return true;
}

bool Catalog::deleteBookFromCatalog(const string& bookId) {
    vector<Book> catalog = loadBookCatalog();

    auto it = remove_if(catalog.begin(), catalog.end(), [&](const Book& bookToDelete) {
        return bookToDelete.getBookId() == bookId;
    });

    if (it != catalog.end()) {
        catalog.erase(it, catalog.end());
        updateBookCatalog(catalog);
        return true;
    }

    return false;
}

vector<Book> Catalog::loadBookCatalog() {
    ifstream inFile("data/books.csv");
    string line;
    vector<Book> books;

    while (getline(inFile, line)) {
        Book book;
        stringstream ss(line);
        string value;

        string bookId;
        string title;
        string author;
        string genre;
        string subGenre;
        string yearString;

        getline(ss, bookId, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, genre, ',');
        getline(ss, subGenre, ',');
        getline(ss, yearString, ',');
        getline(ss, value, ',');
        
        book.setBookId(bookId);
        book.setTitle(title);
        book.setAuthor(author);
        book.setGenre(genre);
        book.setSubGenre(subGenre);
        book.setYear(stoi(yearString));
        book.setAvailability(value == "1");

        books.push_back(book);
    }

    return books;
}

vector<Book> Catalog::getBookRecommendations(Client client) {
    vector<Book> bookCatalog = loadBookCatalog();
    vector<Book> bookHistory = client.loadClientsBookHistory();
    
    const int listSize = 20;

    unordered_map<string, int> freqMapGenre;
    unordered_map<string, int> freqMapSubGenre;
    for (const auto& book : bookHistory) {
        freqMapGenre[book.getGenre()]++;
        freqMapSubGenre[book.getSubGenre()]++;
    }

    vector<pair<string, int>> freqVecGenre(freqMapGenre.begin(), freqMapGenre.end());
    vector<pair<string, int>> freqVecSubGenre(freqMapSubGenre.begin(), freqMapSubGenre.end());

    sort(freqVecGenre.begin(), freqVecGenre.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    sort(freqVecSubGenre.begin(), freqVecSubGenre.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    vector<string> topThreeGenres;
    vector<string> topThreeSubGenres;

    for (size_t i = 0; i < topThreeSubGenres.size() && i < 3; ++i) {
        topThreeGenres.push_back(freqVecGenre[i].first);
    }
    for (size_t i = 0; i < topThreeGenres.size() && i < 3; ++i) {
        topThreeSubGenres.push_back(freqVecSubGenre[i].first);
    }

    unordered_set<string> addedBooks; //prevent duplicates
    vector<Book> bookRecommendations;
    for (size_t i = 0; i < topThreeSubGenres.size(); ++i) {
        if (bookRecommendations.size() >= listSize) break;
        string searchSubGenre = topThreeSubGenres[i];
        for (const Book& book : bookCatalog) {
            if (book.getSubGenre() == searchSubGenre && addedBooks.insert(book.getTitle()).second) {
                bookRecommendations.push_back(book);
            }
            if (bookRecommendations.size() >= listSize) break;
        }
    }
    for (size_t i = 0; i < topThreeGenres.size(); ++i) {
        if (bookRecommendations.size() >= listSize) break;
        string searchGenre = topThreeGenres[i];
        for (const Book& book : bookCatalog) {
            if (book.getGenre() == searchGenre && addedBooks.insert(book.getTitle()).second) {
                bookRecommendations.push_back(book);
            }
            if (bookRecommendations.size() >= listSize) break;
        }
    }
    return bookRecommendations;
}

vector<Book> Catalog::sortCatalogByAuthor(const vector<Book>& catalog) {
    vector<Book> sortedCatalog = catalog;
    sort(sortedCatalog.begin(), sortedCatalog.end(), [](const Book& a, const Book& b) {
        return a.getAuthor() < b.getAuthor();
    });
    return sortedCatalog;
}

vector<Book> Catalog::sortCatalogByGenre(const vector<Book>& catalog) {
    vector<Book> sortedCatalog = catalog;
    sort(sortedCatalog.begin(), sortedCatalog.end(), [](const Book& a, const Book& b) {
        return a.getGenre() < b.getGenre();
    });
    return sortedCatalog;
}

vector<Book> Catalog::sortCatalogByYear(const vector<Book>& catalog) {
    vector<Book> sortedCatalog = catalog;
    sort(sortedCatalog.begin(), sortedCatalog.end(), [](const Book& a, const Book& b) {
        return a.getYear() < b.getYear();
    });
    return sortedCatalog;
}