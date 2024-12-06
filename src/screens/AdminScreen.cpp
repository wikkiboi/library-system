#include "screens/AdminScreen.h"
#include "screens/CatalogScreen.h"
#include <iostream>
#include <string>

using namespace std;

AdminScreen::AdminScreen(Admin& adminRef) : admin(adminRef) {}

void AdminScreen::render() {
    while (true) {
        cout << "\n--- " << admin.getUsername() << "'s" << " Dashboard ---\n";
        cout << "1. View Catalog\n";
        cout << "2. Add Book\n";
        cout << "3. Edit Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Logout\n";
        cout << "Enter your choice: ";

        bool logout;
        logout = handleAdminChoice();
        if (logout) break;
    }
}

bool AdminScreen::handleAdminChoice() {
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Catalog" << endl;
    } else if (choice == 2) {
        cout << "Add Book" << endl;
    } else if (choice == 3) {
        cout << "Edit Book" << endl;
    } else if (choice == 4) {
        cout << "Delete Book" << endl;
    } else if (choice == 5) {
        return true;
    } else {
        cout << "Invalid option. Please try again.\n";
    }

    return false;
}