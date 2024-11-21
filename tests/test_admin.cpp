#include <gtest/gtest.h>
#include "Book.h" 
#include "Admin.h"

TEST(AdminTest, AddBook) {
    Admin admin;

    string bookId = "12345";
    string title = "Test Book";
    string author = "Test Author";
    string genre = "Fiction";
    string subGenre = "Fantasy";
    bool isAvailable = true;

    EXPECT_TRUE(admin.addBook(bookId, title, author, genre, subGenre, isAvailable));
}

TEST(AdminTest, EditBook) {
    Admin admin;

    string bookId = "12345";
    string newTitle = "Updated Book Title";
    string newAuthor = "Updated Author";
    string newGenre = "Updated Genre";
    string newSubGenre = "Updated Sub-Genre";
    bool isAvailable = false;

    EXPECT_TRUE(admin.editBook(bookId, newTitle, newAuthor, newGenre, newSubGenre, isAvailable));
}

TEST(AdminTest, DeleteBook) {
    Admin admin;
    string bookId = "12345";

    EXPECT_TRUE(admin.deleteBook(bookId));
}