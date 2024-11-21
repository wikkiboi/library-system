#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
    protected:
        string userId;
        string username;
        string password;
    
    public:

        string libraryId;
        // User-related functions
        bool registerUser(const string& username, const string& password);
        bool loginUser(const string& username, const string& password);
};

#endif
