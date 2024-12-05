#include "Borrow.h"
#include "Book.h"
#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

TEST(TestBorrowBook, TestBorrowBook_Success) {
    Book book1;
    book1.setBookId("B001");
    book1.setTitle("Test Book 1");
    book1.setAuthor("Author A");
    book1.setGenre("Fiction");
    book1.setYear(2020);
    book1.setAvailability(true);

    Borrow borrow;
    
   
    EXPECT_TRUE(borrow.borrowBook("L001", book1)); 
    EXPECT_FALSE(book1.getAvailability());  
}

TEST(TestBorrowBook, TestBorrowBook_Failure_BookUnavailable) {
    Book book2;
    book2.setBookId("B002");
    book2.setTitle("Test Book 2");
    book2.setAuthor("Author B");
    book2.setGenre("Non-Fiction");
    book2.setYear(2021);
    book2.setAvailability(false); 

    Borrow borrow;
    

    EXPECT_FALSE(borrow.borrowBook("L002", book2));  
}

TEST(TestRenewBook, TestRenewBook_Success) {
    Book book1;
    book1.setBookId("B001");
    book1.setTitle("Test Book 1");
    book1.setAuthor("Author A");
    book1.setGenre("Fiction");
    book1.setYear(2020);
    book1.setAvailability(true);

    Borrow borrow;

    borrow.borrowBook("L003", book1);
    EXPECT_TRUE(borrow.renewBorrow());  
}

TEST(TestRenewBook, TestRenewBook_Failure_NoBorrowRecord) {
    Borrow borrow1;
    
    EXPECT_FALSE(borrow1.renewBorrow());  
}
TEST(TestRenewBook, TestRenewBook_ExceedMaxRenewal) {
    Book book1;
    book1.setBookId("B001");
    book1.setTitle("Test Book 1");
    book1.setAuthor("Author A");
    book1.setGenre("Fiction");
    book1.setYear(2020);
    book1.setAvailability(true); 

    Borrow borrow;
    
    borrow.borrowBook("L004", book1);  
    EXPECT_TRUE(borrow.renewBorrow());  
    EXPECT_TRUE(borrow.renewBorrow());  
    EXPECT_TRUE(borrow.renewBorrow());  
    

    EXPECT_FALSE(borrow.renewBorrow());  
}

TEST(TestReturnBook, TestReturnBook_Success) {
    Book book1;
    book1.setBookId("B001");
    book1.setTitle("Test Book 1");
    book1.setAuthor("Author A");
    book1.setGenre("Fiction");
    book1.setYear(2020);
    book1.setAvailability(true); 

    Borrow borrow;
    
    borrow.borrowBook("L005", book1); 
    EXPECT_TRUE(borrow.returnBorrow());  
}

TEST(TestMultipleBorrows, TestMultipleBorrows) {
    Book book1;
    book1.setBookId("B001");
    book1.setTitle("Test Book 1");
    book1.setAuthor("Author A");
    book1.setGenre("Fiction");
    book1.setYear(2020);
    book1.setAvailability(true); 
    
    Book book2;
    book2.setBookId("B002");
    book2.setTitle("Test Book 2");
    book2.setAuthor("Author B");
    book2.setGenre("Non-Fiction");
    book2.setYear(2021);
    book2.setAvailability(false);

    Borrow borrow;
    

    EXPECT_TRUE(borrow.borrowBook("L005", book1));  
    EXPECT_FALSE(borrow.borrowBook("L006", book2));
    EXPECT_FALSE(book2.getAvailability());

    EXPECT_TRUE(borrow.returnBorrow());

}
