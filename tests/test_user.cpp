#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "User.h"
#include "Book.h"
#include "Administrator.h"
#include "RegularUser.h"

#include <iostream>
#include <fstream>
#include <random>
#include <sstream>

using namespace std;

string usersFilePath = "data/users.csv";
string booksFilePath = "data/books.csv";
string borrowRecordsFilePath = "data/borrow_records.csv";

string backUpFile(const string& filePath) {
    ifstream inputFile(filePath);
    string originalContent;
    if (inputFile.is_open()) {
        stringstream buffer;
        buffer << inputFile.rdbuf();
        originalContent = buffer.str();
        inputFile.close();
    }
    return originalContent;
}

void restoreFile(const string& originalContent, const string& filePath) {
    ofstream restoreFile(filePath);
    if (restoreFile.is_open()) {
        restoreFile << originalContent;
        restoreFile.close();
    }
}

// Backups are used because running tests multiple times will cause errors due to csv files not going to their original state
// Using temp_users.csv

TEST(UserTest, RegisterUserValid) {
    User user;

    string backUp = backUpFile(usersFilePath);
    bool registrationSuccess = user.registerUser("john_doe", "Password123");
    restoreFile(backUp, usersFilePath);

    EXPECT_TRUE(registrationSuccess);
}

TEST(UserTest, RegisterUserInvalidUsername) {
    User user;

    bool registrationSuccess = user.registerUser("", "Password123");

    EXPECT_FALSE(registrationSuccess);
}

TEST(UserTest, RegisterUserShortPassword) {
    User user;

    bool registrationSuccess = user.registerUser("john_doe", "123");

    EXPECT_FALSE(registrationSuccess);
}
TEST(UserTest, RegisterUserLowercasePassword) {
    User user;

    bool registrationSuccess = user.registerUser("john_doe", "password123");

    EXPECT_FALSE(registrationSuccess);
}

TEST(UserTest, RegisterUserNoDigitPassword) {
    User user;
    
    bool registrationSuccess = user.registerUser("john_doe", "Password");

    EXPECT_FALSE(registrationSuccess);
}

TEST(UserTest, RegisterUserUppercasePassword) {
    User user;

    bool registrationSuccess = user.registerUser("john_doe", "PASSWORD123");

    EXPECT_FALSE(registrationSuccess);
}

TEST(UserTest, LoginUserValid) {
    User user;

    string backUp = backUpFile(usersFilePath);
    bool registrationSuccess = user.registerUser("testLoginUser", "testPassword123");
    bool loginSuccess = user.loginUser("testLoginUser", "testPassword123");
    restoreFile(backUp, usersFilePath);

    EXPECT_TRUE(loginSuccess);
}

TEST(UserTest, LoginUserInvalidUsername) {
    User user;

    string backUp = backUpFile(usersFilePath);
    bool registrationSuccess = user.registerUser("testLoginUser", "testPassword123");
    bool loginSuccess = user.loginUser("invalidUsername", "testPassword123");
    restoreFile(backUp, usersFilePath);

    EXPECT_FALSE(loginSuccess);
}

TEST(UserTest, LoginUserInvalidPassword) {
    User user;

    string backUp = backUpFile(usersFilePath);
    bool registrationSuccess = user.registerUser("testLoginUser", "testPassword123");
    bool loginSuccess = user.loginUser("testLoginUser", "invalidPassword123");
    restoreFile(backUp, usersFilePath);

    EXPECT_FALSE(loginSuccess);
}

TEST(UserTest, AdminUserAddBookValid) {
    Book newBook = Book("Hero", "John", "Fiction", 1984);
    Administrator user;

    bool addBookSuccess = user.addBook(newBook);
    EXPECT_TRUE(addBookSuccess);
}

