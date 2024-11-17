#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "User.h"

#include <iostream>
#include <fstream>
#include <random>
#include <sstream>

using namespace std;

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

    user.setFilePath("data/temp_users.csv");
    string backUp = backUpFile("data/temp_users.csv");

    bool registrationSuccess = user.registerUser("john_doe", "Password123");

    restoreFile(backUp, "data/temp_users.csv");

    EXPECT_TRUE(registrationSuccess);
}

TEST(UserTest, RegisterUserInvalidUsername) {
    User user;

    user.setFilePath("data/temp_users.csv");
    bool registrationSuccess = user.registerUser("", "Password123");

    EXPECT_FALSE(registrationSuccess);
}

TEST(UserTest, RegisterUserShortPassword) {
    User user;

    user.setFilePath("data/temp_users.csv");
    bool registrationSuccess = user.registerUser("john_doe", "123");

    EXPECT_FALSE(registrationSuccess);
}
TEST(UserTest, RegisterUserLowercasePassword) {
    User user;

    user.setFilePath("data/temp_users.csv");
    bool registrationSuccess = user.registerUser("john_doe", "password123");

    EXPECT_FALSE(registrationSuccess);
}

TEST(UserTest, RegisterUserNoDigitPassword) {
    User user;
    
    user.setFilePath("data/temp_users.csv");
    bool registrationSuccess = user.registerUser("john_doe", "Password");

    EXPECT_FALSE(registrationSuccess);
}

TEST(UserTest, RegisterUserUppercasePassword) {
    User user;

    user.setFilePath("data/temp_users.csv");
    bool registrationSuccess = user.registerUser("john_doe", "PASSWORD123");

    EXPECT_FALSE(registrationSuccess);
}

TEST(UserTest, LoginUserValid) {
    User user;

    user.setFilePath("data/temp_users.csv");
    bool loginSuccess = user.loginUser("testLoginUser", "testPassword123");

    EXPECT_TRUE(loginSuccess);
}

TEST(UserTest, LoginUserInvalidUsername) {
    User user;

    user.setFilePath("data/temp_users.csv");
    bool loginSuccess = user.loginUser("invalidUsername", "testPassword123");

    EXPECT_FALSE(loginSuccess);
}

TEST(UserTest, LoginUserInvalidPassword) {
    User user;

    user.setFilePath("data/temp_users.csv");
    bool loginSuccess = user.loginUser("testLoginUser", "invalidPassword123");

    EXPECT_FALSE(loginSuccess);
}


