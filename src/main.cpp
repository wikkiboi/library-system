#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "User.h"

using namespace std;

void displayMainMenu();
void handleRegister();
bool isValidUsername(const string& username);
bool isTakenUsername(const string& username);
bool isValidPassword(const string& password);
void handleLogin();
void displayUserDashboard(const User& user);

void displayMainMenu() {
    cout << "\nLibraryLink\n";
    cout << "1. Register User\n";
    cout << "2. Login \n";
    cout << "3. View Book Catalog (with Sorting)\n";
    cout << "4. Quit \n";
    cout << "Enter your choice: ";
}

void handleRegister() {
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

    User user;
    if (user.registerUser(username, password)) {
        cout << "Registration successful!\n";
        displayUserDashboard(user);
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

void handleLogin() {
    cin.clear();
    cin.ignore(10000, '\n');
    string username, password;

    cout << "Enter your username: ";
    getline(cin, username);

    cout << "Enter your password: ";
    getline(cin, password);

    User user;
    if (user.loginUser(username, password)) {
        cout << "Login Success!" << endl;
        displayUserDashboard(user);
    } else {
        cout << "Invalid username or password!" << endl;
    }
}

void displayUserDashboard(const User& user) {
    return;
}

void displayCatalog() {
    Book book;
    vector<Book> catalog = book.loadBookCatalog();

    cout << "Choose a sorting method:\n";
    cout << "1. Sort by Author\n";
    cout << "2. Sort by Genre\n";
    cout << "Enter your choice: ";
    int sortChoice;
    cin >> sortChoice;

    if (cin.fail() || (sortChoice != 1 && sortChoice != 2)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid option. Showing unsorted catalog.\n";
    } else {
        if (sortChoice == 1) {
            catalog = Book::sortCatalogByAuthor(catalog);
        } else if (sortChoice == 2) {
            catalog = Book::sortCatalogByGenre(catalog);
        }
    }

    cout << "\n--- Book Catalog ---\n";
    for (const auto& book : catalog) {
        book.displayBookInfo();
        cout << "\n";
    }
}

int main() {
    bool quit = false;
    while (!quit) {
        displayMainMenu();

        int choice;
        cin >> choice;

        if (cin.fail() || choice != 1 && choice != 2 && choice != 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid option. Please try again.\n";
            continue;
        }

        if (choice == 1) {
            handleRegister();
        } else if (choice == 2) {
            handleLogin();
        } else if (choice == 3) {
    	    displayCatalog();
	}else if (choice == 4) {
            quit = true;
        } 
    }

    return 0;    
}
