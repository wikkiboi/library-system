#include "screens/EditBookScreen.h"
#include <iostream>

EditBookScreen::EditBookScreen(Admin& admin) : admin(admin) {};

string handleBookIdInput() {
    string bookId;
    cin.clear();
    cin.ignore(10000, '\n');

    cout << "(Input empty string to go back)" << '\n';
    cout << "Enter the Book ID of the book to edit: ";
    getline(cin, bookId);

    if (bookId.empty()) {
        cin.clear();
        return "";
    }

    cin.clear();

    return bookId;
}

string handleTitleInput(string oldTitle) {
    string title;
    cin.clear();

    cout << "Enter the new title of the book (Current Title: " << oldTitle << "): ";
    getline(cin, title);

    if (title.empty()) {
        cin.clear();
        return "";
    }

    cin.clear();

    return title;
}

string handleAuthorInput(string oldAuthor) {
    string author;
    cin.clear();

    cout << "Enter the new author of the book (Current Author: " << oldAuthor << "): ";
    getline(cin, author);

    if (author.empty()) {
        cin.clear();
        return "";
    }

    cin.clear();

    return author;
}

string handleGenreInput(string oldGenre) {
    string genre;
    cin.clear();

    cout << "Enter the new genre of the book (Current Genre: " << oldGenre << "): ";
    getline(cin, genre);

    if (genre.empty()) {
        cin.clear();
        return "";
    }

    cin.clear();

    return genre;
}

string handleSubGenreInput(string oldSubGenre) {
    string subGenre;
    cin.clear();

    cout << "Enter the new sub-genre of the book (Current Sub-Genre: " << oldSubGenre << "): ";
    getline(cin, subGenre);

    if (subGenre.empty()) {
        cin.clear();
        return "";
    }

    cin.clear();

    return subGenre;
}

int handleYearInput(int oldYear) {
    string year;
    cin.clear();

    cout << "Enter the new book publication year (Current: " << oldYear << "): ";
    getline(cin, year);

    if (year.empty()) {
        cin.clear();
        return -1;
    }

    cin.clear();

    return stoi(year);
}

void EditBookScreen::render() {
    Catalog catalog;
    vector<Book> books = catalog.loadBookCatalog();
    Book book;
    string bookId;
    string title;
    string author;
    string genre;
    string subgenre;
    int year;

    for (const auto& book : books) {
        book.displayBookInfo();
        cout << "\n";
    }

    while (true) {
        bookId = handleBookIdInput();
        if (bookId == "") break;
        book = catalog.getBookFromCatalog(bookId);

        if (book.getBookId() == "-1") {
            cout << "Book not found in catalog. Please enter a valid book ID." << '\n';
            return;
        }

        title = handleTitleInput(book.getTitle());
        if (title == "") break;
        author = handleAuthorInput(book.getAuthor());
        if (author == "") break;
        genre = handleGenreInput(book.getGenre());
        if (genre == "") break;
        subgenre = handleSubGenreInput(book.getSubGenre());
        if (subgenre == "") break;
        year = handleYearInput(book.getYear());
        if (year == -1) break;

        if (admin.editBook(book.getBookId(), title, author, genre, subgenre, year, true)) {
            cout << "\n" << "Successfully edited Book #" << bookId << "\n";
            return;
        } else {
            cout << "\n" << "Error updating book in the catalog. Ensure that all fields are valid and try again." << "\n";
            return; 
        }
    }

    cin.clear();
    return;
}

