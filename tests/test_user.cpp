#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "User.h"

using namespace std;

TEST(UserTest, RegisterUserValid) {
    User user;
    bool registrationSuccess = user.registerUser("john_doe", "Password123");

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

