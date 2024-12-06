#include "screens/MainMenuScreen.h"
#include "screens/RegisterScreen.h"
#include "screens/LoginScreen.h"
#include <iostream>

void MainMenuScreen::render() {
    cout << "\nLibraryLink\n";
    cout << "1. Register User\n";
    cout << "2. Login \n";
    cout << "3. Quit \n";
    cout << "Enter your choice: ";
}

void MainMenuScreen::handleMainMenuChoice() {
    bool quit = false;
    int choice;

    while (!quit) {
        cin >> choice;

        if (cin.fail() || choice < 1 && choice > 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid option. Please try again.\n";
            cout << "1. Register User\n";
            cout << "2. Login \n";
            cout << "3. Quit \n";
            cout << "Enter your choice: ";
            continue;
        }

        if (choice == 1) {
            RegisterScreen registerUser;
            registerUser.render();
            render();
        } else if (choice == 2) {
            LoginScreen loginUser;
            loginUser.render();
            render();
        } else if (choice == 3) {
            quit = true;
        }
    }

    return;
}   