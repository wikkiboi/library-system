#include "User.h"
#include <iostream>
#include <fstream>
#include <random>
#include <sstream>

using namespace std;

bool User::registerUser(const string& username, const string& password) {
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
    cout << "User registered successfully.\n";
    cout << "Library ID: " << libraryId << endl;
    return true;
}
