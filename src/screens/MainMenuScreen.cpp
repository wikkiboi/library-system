#include "screens/MainMenuScreen.h"
#include "screens/RegisterScreen.h"
#include "screens/LoginScreen.h"
#include <iostream>
#include <string>

void MainMenuScreen::render() {
    cout << "\nLibraryLink\n";
    cout << "1. Register User\n";
    cout << "2. Login \n";
    cout << "3. Login as Admin \n";
    cout << "4. Quit \n";
    cout << "Enter your choice: ";
}

void MainMenuScreen::handleMainMenuChoice() {
    bool quit = false;

    while (!quit) {
        int choice;
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 4) {
            cout << "Invalid option. Please try again.\n" << endl;
            cout << "1. Register User\n";
            cout << "2. Login \n";
            cout << "3. Login as Admin \n";
            cout << "4. Quit \n";
            cout << "Enter your choice: ";
            continue;
        }


        if (choice == 1) {
            RegisterScreen registerUser;
            registerUser.render();
            render();
        } else if (choice == 2) {
            LoginScreen loginUser(false);
            loginUser.render();
            render();
        } else if (choice == 3) {
            LoginScreen loginUser(true);
            loginUser.render();
            render();
        } else if (choice == 4) {
            quit = true;
        }

        cin.clear();
    }

    return;
}   