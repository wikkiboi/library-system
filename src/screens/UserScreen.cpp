#include "screens/UserScreen.h"
#include "screens/BorrowScreen.h"
#include "screens/CatalogScreen.h"
#include "screens/RecommendationScreen.h"
#include <string>
#include <iostream>

using namespace std;

UserScreen::UserScreen(Client& clientRef) : client(clientRef) {}

void UserScreen::render() {
    while(true) {
            cout << "\n--- " << client.getUsername() << "'s" << " Dashboard ---\n";
            cout << "1. Browse Book Catalog\n";
            cout << "2. Borrow Book\n";
            cout << "3. Renew/Return Book\n";
            cout << "4. View Recommendations\n";
            cout << "5. Logout\n";
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
        CatalogScreen catalogScreen;
        catalogScreen.render();
    } else if (choice == 2) {
        BorrowScreen borrowScreen(client);
        borrowScreen.render();
    } else if (choice == 3) {

    } else if (choice == 4) {
        RecommendationScreen recommendationScreen(client);
        recommendationScreen.render();
    } else if (choice == 5) {
        return true;
    } else {
        cout << "Invalid option. Please try again.\n";
    }

    return false;
}