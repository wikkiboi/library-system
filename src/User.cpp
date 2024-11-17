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

    ifstream readFile(this->filePath);
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

    ofstream file(this->filePath, ios::app);
    if (!file.is_open()) {
        cerr << "Error opening " << this->filePath << endl;
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

bool User::loginUser(const string& username, const string& password) {
    ifstream file(this->filePath);
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
                file.close();
                return true;
            }
        }
    }

    file.close();
    return false;
}

void User::setFilePath(const string& filePath) {
    this->filePath = filePath;
}