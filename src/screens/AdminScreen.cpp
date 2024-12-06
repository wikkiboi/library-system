#include "screens/AdminScreen.h"
#include "screens/CatalogScreen.h"
#include <iostream>

using namespace std;

AdminScreen::AdminScreen(Admin& adminRef) : admin(adminRef) {}

void AdminScreen::render() {
    while (true) {
        cout << "\n--- Admin Dashboard ---\n";
        cout << "1. View Entire Catalog\n";
        cout << "2. Add Book\n";
        cout << "3. Edit Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Logout\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 5) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid option. Please try again.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                CatalogScreen catalogScreen(admin);
                catalogScreen.render();
                break;
            }
            case 2:
                admin.addBook();
                break;
            case 3:
                admin.editBook();
                break;
            case 4:
                admin.deleteBook();
                break;
            case 5:
                cout << "Logging out...\n";
                return; // Exit to main menu
        }
    }
}