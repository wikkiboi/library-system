#ifndef USER_H
#define USER_H

#include <string>
using namespace std;
class User {
    private:
        string userId;
        string username;
        string password;
        string libraryId;
    
    public:
        bool registerUser(const string& username, const string& password);


};

#endif