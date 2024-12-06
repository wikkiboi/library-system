#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
    protected:
        string userId;
        string username;
        string password;
        string libraryId;
        bool loggedIn = false;
    public:
        User() {};
        User(const string& username, const string& password);
        bool registerUser(const string& username, const string& password);
        bool loginUser(const string& username, const string& password);
        bool getLoggedIn();
};

#endif
