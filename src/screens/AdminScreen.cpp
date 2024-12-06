#include "screens/AdminScreen.h"
#include "screens/AddBookScreen.h"
#include "screens/EditBookScreen.h"
#include "screens/RemoveBookScreen.h"
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
        CatalogScreen catalogScreen;
        catalogScreen.render();
    } else if (choice == 2) {
        AddBookScreen addBookScreen(admin);
        addBookScreen.render();
    } else if (choice == 3) {
        EditBookScreen editBookScreen(admin);
        editBookScreen.render();
    } else if (choice == 4) {
        RemoveBookScreen removeBookScreen(admin);
        removeBookScreen.render();
    } else if (choice == 5) {
        return true;
    } else {
        cout << "Invalid option. Please try again.\n";
    }

    return false;
}