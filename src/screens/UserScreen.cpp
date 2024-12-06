#include "screens/UserScreen.h"
#include <string>
#include <iostream>

using namespace std;

UserScreen::UserScreen(Client& clientRef) : client(clientRef) {}

void UserScreen::render() {
    while(true) {
            cout << "\n--- " << client.getUsername() << "'s" << " Dashboard ---\n";
            cout << "1. Browse Book Catalog\n";
            cout << "2. Manage Borrowed Books\n";
            cout << "3. View Recommendations\n";
            cout << "4. Logout\n";
            cout << "Enter your choice: ";
            
            bool logout;
            logout = handleUserChoice();
            if (logout) break;
    }
}

bool UserScreen::handleUserChoice() {
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Catalog" << endl;
    } else if (choice == 2) {
        cout << "Borrowed Books" << endl;
    } else if (choice == 3) {
        cout << "View Recommendations" << endl;
    } else if (choice == 4) {
        return true;
    } else {
        cout << "Invalid option. Please try again.\n";
    }

    return false;
}