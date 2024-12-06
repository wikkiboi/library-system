#include "screens/CatalogScreen.h"
#include <iostream>
#include <string>

void CatalogScreen::render() {
    Catalog catalog;
    vector<Book> books = catalog.loadBookCatalog();

    for (const auto& book : books) {
        book.displayBookInfo();
        cout << "\n";
    }

    cout << "\n";
    cout << "Choose a sorting method:\n";
    
    while (true) {
        cout << "1. Sort by Author\n";
        cout << "2. Sort by Genre\n";
        cout << "3. Sort by Year Published\n";
        cout << "4. Back to Dashboard\n";
        cout << "Enter your choice: ";
        int sortChoice;
        cin >> sortChoice;

        if (cin.fail() || (sortChoice > 4 || sortChoice < 1)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid option. Showing unsorted catalog.\n";
        } else {
            if (sortChoice == 1) {
                books = catalog.sortCatalogByAuthor(books);
            } else if (sortChoice == 2) {
                books = catalog.sortCatalogByGenre(books);
            } else if (sortChoice == 3) {
                books = catalog.sortCatalogByYear(books);
            } else if (sortChoice == 4) {
                break;
            }
        }
        cout << "\n--- Book Catalog ---\n";
        for (const auto& book : books) {
            book.displayBookInfo();
            cout << "\n";
        }

        cout << "\n";
    }

    return;
}