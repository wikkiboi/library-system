#include "screens/AddBookScreen.h"
#include <iostream>

AddBookScreen::AddBookScreen(Admin& admin) : admin(admin) {};

string handleTitleInput() {
    string title;
    cin.clear();
    cin.ignore(10000, '\n');

    cout << "(Enter empty input to return to dashboard)" << '\n';
    cout << "Enter title of the new book: ";
    getline(cin, title);

    if (title.empty()) {
        cin.clear();
        return "";
    }

    cin.clear();

    return title;
}

string handleAuthorInput() {
    string author;
    cin.clear();

    cout << "Enter author of the new book: ";
    getline(cin, author);

    if (author.empty()) {
        cin.clear();
        return "";
    }

    cin.clear();

    return author;
}

string handleGenreInput() {
    string genre;
    cin.clear();

    cout << "Enter genre of the new book: ";
    getline(cin, genre);

    if (genre.empty()) {
        cin.clear();
        return "";
    }

    cin.clear();

    return genre;
}

string handleSubGenreInput() {
    string subGenre;
    cin.clear();

    cout << "Enter sub-genre of the new book: ";
    getline(cin, subGenre);

    if (subGenre.empty()) {
        cin.clear();
        return "";
    }

    cin.clear();

    return subGenre;
}

int handleYearInput() {
    string year;
    cin.clear();

    cout << "Enter the book publication year: ";
    getline(cin, year);

    if (year.empty()) {
        cin.clear();
        return -1;
    }

    cin.clear();

    return stoi(year);
}

void AddBookScreen::render() {
    string title;
    string author;
    string genre;
    string subgenre;
    int year;
    while (true) {
        title = handleTitleInput();
        if (title == "") break;
        author = handleAuthorInput();
        if (author == "") break;
        genre = handleGenreInput();
        if (genre == "") break;
        subgenre = handleSubGenreInput();
        if (subgenre == "") break;
        year = handleYearInput();
        if (year == -1) break;

        if (admin.addBook(title, author, genre, subgenre, year, true)) {
            cout << "\n" << "Successfully added " << title << " to the catalog!" << "\n";
            return;
        } else {
            cout << "\n" << "Error adding book to catalog. Ensure that all fields are valid and try again." << "\n";
            return; 
        }
    }

    cin.clear();
    return;
}

