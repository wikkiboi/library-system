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

using namespace std;

void displayMainMenu();
void handleRegister(Client& client);
bool isValidUsername(const string& username);
bool isTakenUsername(const string& username);
bool isValidPassword(const string& password);
void handleLogin(Client& client);
void displayCatalog(Client &client);
void displayBorrow(Client &client);
void displayUserDashboard(const Client& client);

void displayMainMenu() {
    cout << "\nLibraryLink\n";
    cout << "1. Register User\n";
    cout << "2. Login \n";
    cout << "3. View Book Catalog (with Sorting)\n";
    cout << "4. Quit \n";
    cout << "Enter your choice: ";
}

void handleRegister(Client& client) {
    cin.clear();
    cin.ignore(10000, '\n');
    string username, password;

    do {
    cout << "Enter your username: ";
    getline(cin, username);

    if (!isValidUsername(username)) {
        cout << "Invalid username. Please ensure it is not empty and meets the requirements.\n";
    }

    if (isTakenUsername(username)) {
        cout << "Username already taken. Please choose a different username.";
    }
    
    } while (!isValidUsername(username) && isTakenUsername(username));


    do {
    cout << "Enter your password: ";
    getline(cin, password);

    if (!isValidPassword(password)) {
        cout << "Invalid password. It must be at least 8 characters long and contain a mix of letters and numbers.\n";
    }

    } while (!isValidPassword(password));

    if (client.registerUser(username, password)) {
        cout << "Registration successful!\n";
        displayUserDashboard(client);
    } else {
        cout << "Registration failed. Please try again later.\n";
    }
}

bool isValidUsername(const string& username) {
    return !username.empty();
}

bool isTakenUsername(const string& username) {
    ifstream file("data/users.csv");
    string line;
    while (getline(file, line)) {
        istringstream stream(line);
        string fileUsername;
        getline(stream, fileUsername, ',');
        if (fileUsername == username) {
            return false;
        }
    }
    return true;
}

bool isValidPassword(const string& password) {
    if (password.length() < 8) {
        return false;
    }

    bool hasUpper = false, hasLower = false, hasDigit = false;
    for (char ch: password) {
        if (isupper(ch)) {
            hasUpper = true;
        } else if (islower(ch)) {
            hasLower = true;
        } else if (isdigit(ch)) {
            hasDigit = true;
        }
    }

    return hasUpper && hasLower && hasDigit;
}

void handleLogin(Client& client) {
    cin.clear();
    cin.ignore(10000, '\n');
    string username, password;

    cout << "Enter your username: ";
    getline(cin, username);

    cout << "Enter your password: ";
    getline(cin, password);

    if (client.loginUser(username, password)) {
        cout << "Login Success!" << endl;
        displayUserDashboard(client);
    } else {
        cout << "Invalid username or password!" << endl;
    }
}

void displayUserDashboard(const Client& client) {
    return;
}

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
        Borrow borrow = client.borrowBook(borrowedBook);
        cout << "You have borrowed \"" << borrowedBook.getTitle() << "\" by " << borrowedBook.getAuthor() << "!\n";
        cout << "Please return this book by " << borrow.getDueDate() << "\n";
    } else {
        cout << "Invalid book ID:\n";
    }
}

void generateBooks() {
    Admin admin;
}

int main() {
    bool quit = false;
    Client client;
    while (!quit) {
        displayMainMenu();

        int choice;
        cin >> choice;

        if (cin.fail() || choice < 0 && choice > 4) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid option. Please try again.\n";
            continue;
        }

        if (choice == 1) {
            handleRegister(client);
        } else if (choice == 2) {
            handleLogin(client);
        } else if (choice == 3) {
    	    displayCatalog(client);
	    }else if (choice == 4) {
            quit = true;
        } 
    }

    return 0;    
}
