#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Book.h" 
#include "Admin.h"
#include "Client.h"
#include "Catalog.h"

#include <vector>
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
    int year = 2000;
    bool isAvailable = true;
    bool addBook = admin.addBook(bookId, title, author, genre, subGenre, year, isAvailable);
    EXPECT_TRUE(addBook);

    Book borrowedBook = catalog.getBookFromCatalog(bookId);

    Client client;
    bool loginSuccess = client.loginUser("borrowUser", "borrowPassword123");
    ;

    EXPECT_TRUE(client.clientBorrowBook(borrowedBook));
}

TEST(ClientTest, BorrowBookSuccess) {
    Book book;
    book.setBookId("12345");
    book.setTitle("C++ Primer");
    book.setAvailability(true);

    Client client;
    EXPECT_TRUE(client.clientBorrowBook(book));
}

TEST(ClientTest, BorrowBookFailureWhenUnavailable) {
    Book book;
    book.setBookId("12345");
    book.setTitle("C++ Primer");
    book.setAvailability(false);

    Client client;
    EXPECT_FALSE(client.clientBorrowBook(book));
}


TEST(ClientTest, TestClientRenewBook_Success) {
    Client client;
    Book book1;
    book1.setBookId("B001");
    book1.setTitle("Book 1");
    book1.setAuthor("Author 1");
    book1.setAvailability(true);

    client.clientBorrowBook(book1);
    Borrow borrowRecord = client.getClientsBorrowList()[0];  
    

    EXPECT_TRUE(client.clientRenewBook(borrowRecord)); 
}


TEST(ClientTest, TestClientRenewBook_Failure_RecordNotFound) {
    Client client;
    Book book;
    book.setBookId("B003"); //
    

    Borrow borrowRecord;
    borrowRecord.borrowBook("L001", book);  
    
    EXPECT_FALSE(client.clientRenewBook(borrowRecord));  
}

TEST(ClientTest, TestClientReturnBook_Success) {
    Client client;
    Book book1;
    book1.setBookId("B001");
    book1.setTitle("Book 1");
    book1.setAuthor("Author 1");
    book1.setAvailability(true);

    client.clientBorrowBook(book1);
    Borrow borrowRecord = client.getClientsBorrowList()[0]; 
    EXPECT_TRUE(client.clientReturnBook(borrowRecord)); 
    EXPECT_EQ(client.getClientsBorrowList().size(), 0);  
}
TEST(ClientTest, TestClientReturnBook_Failure_RecordNotFound) {
     Client client;
    Book book;
    book.setBookId("non-existing-borrow-id"); //
    

    Borrow borrowRecord;
    borrowRecord.borrowBook("L001", book);  

    
    EXPECT_FALSE(client.clientReturnBook(borrowRecord));  
}
