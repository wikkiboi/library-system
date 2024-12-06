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
        bool isAdmin = false;
    public:
        User() {};
        User(const string& username, const string& password);
        
        bool getAdminFlag() const { return isAdmin; }
        bool getLoggedIn() const { return loggedIn; }
        string getUserId() const { return userId; }
        string getUsername() const { return username; }
        string getPassword() const { return password; }
        string getLibraryId() const { return libraryId; }

        bool registerUser(const string& username, const string& password);
        bool loginUser(const string& username, const string& password);
};

#endif
