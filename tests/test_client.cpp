#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Book.h" 
#include "Admin.h"
#include "Client.h"
#include "Catalog.h"

#include <iostream>
#include <fstream>
#include <random>
#include <sstream>

TEST(ClientTest, BorrowBook) {
    Catalog catalog;
    Admin admin;
    
    string bookId = "31415";
    string title = "Test Book";
    string author = "Test Author";
    string genre = "Fiction";
    string subGenre = "Fantasy";
    bool isAvailable = true;
    bool addBook = admin.addBook(bookId, title, author, genre, subGenre, isAvailable);
    EXPECT_TRUE(addBook);

    Book borrowedBook = catalog.getBookFromCatalog(bookId);

    Client client;
    bool loginSuccess = client.loginUser("borrowUser", "borrowPassword123");
    Borrow borrow = client.borrowBook(borrowedBook);

    EXPECT_TRUE(borrow.getBorrowId() != -1);
}