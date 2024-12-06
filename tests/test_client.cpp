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



TEST(ClientTest, TestClientRenewBook_Failure_RecordNotFound) {
    Client client;
    Book book;
    book.setBookId("B003"); //
    

    Borrow borrowRecord;
    borrowRecord.borrowBook("L001", book);  
    
    EXPECT_FALSE(client.clientRenewBook(borrowRecord));  
}

TEST(ClientTest, TestClientReturnBook_Failure_RecordNotFound) {
     Client client;
    Book book;
    book.setBookId("non-existing-borrow-id"); //
    

    Borrow borrowRecord;
    borrowRecord.borrowBook("L001", book);  

    
    EXPECT_FALSE(client.clientReturnBook(borrowRecord));  
}
