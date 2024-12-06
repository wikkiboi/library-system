#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "User.h"
#include "Admin.h"
#include "Client.h"
#include "Borrow.h"
#include "Catalog.h"
#include "Book.h"
#include "screens/MainMenuScreen.h"

using namespace std;


void displayCatalog(Client &client);
void displayBorrow(Client &client);
void displayUserDashboard(const Client& client);


void displayCatalog(Client& client) {
    if (!client.getLoggedIn()) {
        cout << "Please log in or register before viewing\n";
        return;
    }

    Catalog catalog;
    vector<Book> books = catalog.loadBookCatalog();

    cout << "Choose a sorting method:\n";
    cout << "1. Sort by Author\n";
    cout << "2. Sort by Genre\n";
    cout << "3. Sort by Year Published\n";
    cout << "Enter your choice: ";
    int sortChoice;
    cin >> sortChoice;

    if (cin.fail() || (sortChoice != 1 && sortChoice != 2 && sortChoice != 3)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid option. Showing unsorted catalog.\n";
    } else {
        if (sortChoice == 1) {
            books = catalog.sortCatalogByAuthor(books);
        } else if (sortChoice == 2) {
            books = catalog.sortCatalogByGenre(books);
        } else if (sortChoice == 3) {
            books = catalog.sortCatalogByYear(books);
        }
    }

    cout << "\n--- Book Catalog ---\n";
    for (const auto& book : books) {
        book.displayBookInfo();
        cout << "\n";
    }

    cout << "Would you like to borrow a book?\n";
    cout << "1. Yes\n";
    cout << "2. No\n";
    cout << "Enter your choice: ";
    int input;
    cin >> input;

    if (cin.fail() || (input != 1 && input != 2)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid option. Quitting.\n";
        return;
    } else {
        if (input == 1) {
            displayBorrow(client);
        } else if (input == 2) {
            return;
        }
    }
}

void displayRecommendations(Client& client) {
    if (!client.getLoggedIn()) {
        cout << "Please log in or register before viewing\n";
        return;
    }

    Catalog catalog;
    vector<Book> books = catalog.getBookRecommendations(client);

    cout << "\n--- Book Recommendations ---\n";
    for (const auto& book : books) {
        book.displayBookInfo();
        cout << "\n";
    }

    cout << "Would you like to borrow a book?\n";
    cout << "1. Yes\n";
    cout << "2. No\n";
    cout << "Enter your choice: ";
    int input;
    cin >> input;

    if (cin.fail() || (input != 1 && input != 2)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid option. Quitting.\n";
        return;
    } else {
        if (input == 1) {
            displayBorrow(client);
        } else if (input == 2) {
            return;
        }
    }
}

void handleRenewal(Client& client, Borrow& borrow) {
    cout << "Would you like to renew your borrow?\n";
    cout << "1. Yes\n";
    cout << "2. No\n";
    cout << "Enter your choice: ";
    int renewChoice;
    cin >> renewChoice;

    if (cin.fail() || (renewChoice != 1 && renewChoice != 2)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid option.\n";
    } else {
        if (renewChoice == 1) {
            // Call the renew function
            if (borrow.renewBorrow()) {
                cout << "Book renewed successfully!\n";
                handleRenewal(client, borrow);
                
            } else {
                cout << "You have reached the maximum renewal limit.\n";
            }
        } else if (renewChoice == 2) {
            cout << "Thank you! Enjoy your book.\n";
        }
    }
}

void displayBorrow(Client &client) {
    Catalog catalog;
    cout << "Choose a book ID you want to borrow: ";
    string bookId;
    cin >> bookId;

    if (cin.fail()) {
        cout << "Invalid input\n";
        displayBorrow(client);
        return;
    }

    Book borrowedBook = catalog.getBookFromCatalog(bookId);
    if (borrowedBook.getBookId() != "-1") {
        bool borrowSuccess = client.clientBorrowBook(borrowedBook);
        Borrow borrow = client.getClientsBorrowList().back();
        cout << "You have borrowed \"" << borrowedBook.getTitle() << "\" by " << borrowedBook.getAuthor() << "!\n";
        cout << "Please return this book by " << borrow.getDueDate() << "\n";
        handleRenewal(client, borrow);
        
    } else {
        cout << "Invalid book ID:\n";
    }
}

void generateBooks() {
    Admin admin;
}

int main() {
    MainMenuScreen menu;
    menu.render();
    menu.handleMainMenuChoice();

    return 0;    
}
