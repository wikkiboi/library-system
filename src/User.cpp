#include "User.h"
#include <iostream>
#include <fstream>
#include <random>
#include <sstream>

using namespace std;

bool User::registerUser(const string& username, const string& password) {
    if (username.empty()) {
        return false;
    }

    ifstream readFile("data/users.csv");
    string line;
    while (getline(readFile, line)) {
        istringstream stream(line);
        string fileUsername;
        getline(stream, fileUsername, ',');
        if (fileUsername == username) {
            cout << "Username already taken. Please choose a different username.";
            return false;
        }
    }

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

    if (!hasUpper || !hasLower || !hasDigit) {
        return false;
    }

    ofstream file("data/users.csv", ios::app);
    if (!file.is_open()) {
        cerr << "Error opening users.csv\n";
        return false;
    }


    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<int> dist(10000, 99999);

    ostringstream oss;
    oss << dist(gen);

    string libraryId = oss.str();

    file << username << "," << password << "," << libraryId << ",user\n";
    file.close();
    cout << "Library ID: " << libraryId << endl;
    return true;
}
