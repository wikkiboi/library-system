#include "screens/RecommendationScreen.h"
#include <iostream>

using namespace std;

RecommendationScreen::RecommendationScreen(Client& clientRef) : client(clientRef) {}

void RecommendationScreen::render() {
    if (!client.getLoggedIn()) {
        cout << "Please log in or register to view recommendations.\n";
        return;
    }

    vector<Book> books = catalog.getBookRecommendations(client);

    cout << "\n--- " << client.getUsername() << "'s" << " Recommendations ---\n";

    if (books.empty()) {
        cout << "No recommendations available at the moment.\n";
        return;
    }

    for (const auto& book : books) {
        book.displayBookInfo();
        cout << "\n";
    }

    return;
}