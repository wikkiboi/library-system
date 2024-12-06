#include "screens/RegisterScreen.h"
#include "Client.h"
#include <string>
#include <iostream>

using namespace std;

void RegisterScreen::render() {
    Client client;
    string username;
    string password;

    do {
        cout << "Enter your username: ";
        username = handleUsernameInput();

        cout << "Enter your password: ";
        password = handlePasswordInput();

        if (client.registerUser(username, password)) {
            cout << "Registration successful!\n";
            break;
        } else {
            cout << "Registration failed. Please try again later.\n";
        }

    } while (!client.registerUser(username, password));

    return;
}

string RegisterScreen::handleUsernameInput() {
    string username;

    do {
        cin.clear();
        cin.ignore(10000, '\n');

        cout << "Enter your username: ";
        getline(cin, username);

        if (username.empty()) {
            cout << "Invalid username. Please ensure it is not empty and meets the requirements.\n";
        }
    } while (username.empty());

    return username;
}

string RegisterScreen::handlePasswordInput() {
    string password;

    do {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter your username: ";
        getline(cin, password);
        if (!isValidPassword(password)) {
            cout << "Invalid password. It must be at least 8 characters long and contain a mix of letters and numbers.\n";
        }
    } while (!isValidPassword(password));

    return password;
}

bool RegisterScreen::isValidPassword(const string& password) {
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
