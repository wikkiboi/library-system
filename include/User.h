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
        string filePath = "data/users.csv";
    
    public:
        bool registerUser(const string& username, const string& password);
        bool loginUser(const string& username, const string& password);
        void setFilePath(const string& filePath);

};

#endif