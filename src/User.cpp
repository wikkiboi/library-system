#include "User.h"
#include <iostream>
#include <fstream>
#include <random>
#include <sstream>

using namespace std;

User::User(const string& username = "", const string& password = "") {
        this->username = username;
        this->password = password;
    }

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

    ofstream file("data/users.csv", ios::app);
    if (!file.is_open()) {
        cerr << "Error opening " << "data/users.csv" << endl;
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
    this->loggedIn = true;
    cout << "Library ID: " << libraryId << endl;
    return true;
}

bool User::loginUser(const string& username, const string& password) {
    ifstream file("data/users.csv");
    if (!file.is_open()) {
        cerr << "Error: Unable to open the file!" << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string fileUsername, filePassword, libraryId, userRole;

        if (getline(ss, fileUsername, ',') &&
            getline(ss, filePassword, ',') &&
            getline(ss, libraryId, ',') &&
            getline(ss, userRole, ',')) {
            
            if (fileUsername == username && filePassword == password) {
                this->username = fileUsername;
                this->password = filePassword;
                this->libraryId = libraryId;
                this->loggedIn = true;
                file.close();
                return true;
            }
        }
    }

    file.close();
    return false;
}

bool User::getLoggedIn() {
    return this->loggedIn;
}