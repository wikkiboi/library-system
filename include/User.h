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
        string filePath = "data/users.csv"; // Default file path for user data
    
    public:
        // User-related functions
        bool registerUser(const string& username, const string& password);
        bool loginUser(const string& username, const string& password);
        void setFilePath(const string& filePath);

        // Book-related function
        bool addBook(const string& title, const string& author, const string& genre);
};

#endif
