#include "screens/LoginScreen.h"
#include "User.h"
#include <iostream>
#include <string>

using namespace std;

void LoginScreen::render() {
    User user;
    string username;
    string password;

    do {
        cout << "Enter your username: ";
        username = handleUsernameInput();

        cout << "Enter your password: ";
        password = handlePasswordInput();

        if (user.loginUser(username, password)) {
            cout << "Login Success!" << endl;
            break;
        } else {
            cout << "Invalid username or password!" << endl;
        }
    } while (!user.loginUser(username, password));

    return;
}

string LoginScreen::handleUsernameInput() {
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

string LoginScreen::handlePasswordInput() {
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

bool LoginScreen::isValidPassword(const string& password) {
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