#include "screens/LoginScreen.h"
#include "screens/UserScreen.h"
#include "screens/AdminScreen.h"
#include "User.h"
#include "Admin.h"
#include "Client.h"
#include <iostream>
#include <string>

using namespace std;

void LoginScreen::render() {
    User user;
    string username;
    string password;

    do {
        username = handleUsernameInput();
        password = handlePasswordInput();

        if (user.loginUser(username, password)) {
            cout << "Login Success!" << endl;
            if (user.getAdminFlag()) {
                Admin admin(user);
                AdminScreen adminScreen(admin);
            } else {
                Client client(user);
                UserScreen userScreen(client);
                userScreen.render();
            }
            break;
        } else {
            cout << "Invalid username or password!" << endl;
        }
    } while (!user.loginUser(username, password));

    return;
}

string LoginScreen::handleUsernameInput() {
    string username;
    cin.clear();
    cin.ignore(10000, '\n');

    do {
        cout << "Enter your username: ";
        getline(cin, username);

        if (username.empty()) {
            cout << "Invalid username. Please ensure it is not empty and meets the requirements.\n";
        }

        cin.clear();
    } while (username.empty());

    return username;
}

string LoginScreen::handlePasswordInput() {
    string password;
    cin.clear();

    do {
        cout << "Enter your password: ";
        getline(cin, password);
        if (!isValidPassword(password)) {
            cout << "Invalid password. It must be at least 8 characters long and contain a mix of letters and numbers.\n";
            cin.clear();
        }

        cin.clear();
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