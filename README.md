# LibraryLink
 Authors: [Ricky Ho](https://github.com/wikkiboi), [Tareq Hassan](https://github.com/Thass004), [Haishan Zhao](https://github.com/HaiShan-el), [Advit Singh](https://github.com/Ghostmaster-UI)

## Project Description

 LibraryLink is a Library Management System that allows users to sign up, log in, and borrow books from the library database. The system provides users with personalized features such as book recommendations and account management for borrow lists. It also includes an interface for administrators that can add, edit, and remove books in the library's catalog.
 ## Why is this important or interesting to us?
 Libraries play an essential role in providing access to education, research, and entertainment. We want to create software that is user-friendly for people of all ages and can also provide to the user beyond the software itself. By building a management system that mimics what a real-life library can provide, we are not only grasping a better understanding of object-oriented design and software accessibility, but we are also promoting the wonders of reading and lifelong learning to people of all ages.
 ## Tools and Technologies
 * Programming Language: C++
 * IDE: Visual Studio Code
 * Version Control: Git & GitHub
 * Account/Book Database: via CSV file
 ## Features
 * Login/Register for account
 * Regular Users:
   * View/manage account status, borrow list/history
   * Browse Available Book Catalog. Books are organized by genre/sub-genre, author, etc.
   * Get Book Recommendations based on borrow history
   * Borrow/Renew/Return Book with an issue period of 30 days. The renewal period is 7 additional days with a limit of 3 per issue period.
   * If any books are overdue for over 14 days, the account will be locked from borrowing until the overdue books are returned.
 * Administrator:
   * View/manage account status
   * Browse Entire Book Catalog with Borrow Status
   * Add/Update/Remove Books from Catalog
## Input/Output
All users will be prompted to log in or register for an account with a username/password. Each user after registering will also be given a Library ID that can also be used to login. Regular users will be prompted to an interface where they can view their account status, available book catalog, and also an option to borrow, renew, or return books. Administrator accounts will be prompted to a separate interface where they can view account status, book catalog with borrow status, and the option to add, update, or remove books from the book catalog. The book catalog will also take in an input that will sort the catalog by said input (i.e. Sort By Author, Genre, etc.).


## User Interface Specification
 The program will run on a CLI, so users would navigate through menus and commands rather than graphical screens. Below is a brief navigation flow for the CLI. Admin screens are highlighted blue and regular user  screens are highlighted in light green.
## Navigation Diagram
 
 ![LibraryLink Navigation Diagram](https://i.imgur.com/jbaYgQS.png)

## Screen Layouts
Each screen will lead to a prompt with text-based options, where the user inputs commands or select from numbered options. In the navigation diagram, the black sub-boxes are the options for that screen and any additional black sub-boxes are output lines that prompt additional input, verification, or confirmation.
For example, the User screen for a non-admin user would look like:
>User Dashboard: <br/>
>- [1] Browse Book Catalog <br/>
>- [2] Borrow Book <br/>
>- [3] Renew Book <br/>
>- [4] Return Book <br/>
>- [5] View Recommendations <br/>
>- [6] Log Out <br/>
>- Enter the number of your choice: <br/>

Any operation fully completed will output text alerting the user that the operation was successful. For example, when registering for an account, the following line would output after a successful registration:
>Registration: <br/>
>- Username: [User Input] <br/>
>- Password: [User Input] <br/>
>- Confirm Password: [User Input] <br/>
>- Registration successful! Your Library ID is [generated ID]. <br/>

On the initial launch screen, we have the following options:
>LibraryLink <br/>
>- [1] Register User <br/>
>- [2] Login <br/>
>- [3] Login as admin <br/>
>- [4] Quit <br/>

## Class Diagram (most up-to-date version)
![LibraryLink Class Diagram](https://i.imgur.com/bFHyrqr.png)
 * DisplayScreen is an abstract class that specific screen layout classes i.e. AdminScreen, UserScreen, etc. inherit from.
 * Each specific screen class is associated with the class it is named after, for example, Admin and AdminScreen.
 * On initial entry of the program, we enter through the MainMenuScreen, which then prompts the loginScreen and the reigsterScreen.
 * There are also screen classes for the Admin add, edit, and remove books as well as Client borrow, renew, and return screens
 * User is the base class for all system users, including RegularUser and Administrator. 
 * The RegularUser class inherits from the User class and adds functionality specific to library users. 
 * The Administrator class also inherits from the User class and provides administrative privileges. 
   * It includes permissions to manage the library catalog and manage user accounts. 
   * This class allows the user to interact with the library catalog and borrowing records. 
 * The Book class represents the books in the library and contains a method to display book information. 
 * The LibraryCatalog class contains all the books available in the library. 
 * The BorrowRecord class represents a record of each borrowing by the user and allows tracking and management of borrowed books and the user's borrowing history. 
   * It also represents the user's borrowing history and allows tracking and management of borrowed books and the user's borrowing history.
 
## SOLID Class Diagram
![LibraryLink Class Diagram](https://i.imgur.com/42uroKY.png)
 * ### New Abstract DisplayScreen Class
    * Open-Closed Principle
    * We added an abstract DisplayScreen class with a render() function and different screens that inherit from it, such as UserScreen, AdminScreen, and CatalogScreen.
    * This allows new screen types to be added without modifying the DisplayScreen code. It makes the code more reusable and open to extension without touching the existing code.
 * ### New Catalog Class
    * Single Responsibility, Interface Segregation Principle
    * The Catalog class is solely responsible for managing the book catalog stored in the books.csv file. We moved the logic of modifying the CSV file from LibraryCatalog to the Catalog class.
    * This reduces the responsibility of the LibraryCatalog class. LibraryCatalog will handle the runtime operations and displaying details to the screen, while Catalog will handle the data storage logic. This also makes it easier to maintain and test as any modifications to file operations do not affect LibraryCatalog.
 * ### Getter/Setter Functions in Book class
   * Single Responsibility Principle (Encapsulation)
   * We added a getter and setter function for every member variable in the Book class.
   * This protects the internal state of the Book class and prevents direct access to the attributes. It also increases flexibility by allowing the addition of validation or formatting logic in between.
* ### Friend relationship between Admin & Catalog Class
   * Liskov Substitution Principle
   * We add a friend relationship to ensure that Admin has exclusive access to the private methods in Catalog, which modify the book catalog in the books.csv file.
   * By restricting access to only the Admin class, it protects the integrity of the Catalog class. This also clearly defines the Admin class, in which it is responsible for modifying the book catalog. 
 
 ## Screenshots
 ### Main Menu Screen
 ![Main Menu Screen](https://i.imgur.com/Skr0XSb.png)

 ### Catalog Screen
 ![Catalog Screen](https://i.imgur.com/Sv0nGgv.png)
 
 ### User (Client) Screen
 ![User Dashboard](https://i.imgur.com/dZlj4Wz.png)
 ![User Return Screen](https://i.imgur.com/lDPS3Ye.png)

 ### Admin Screen
 ![Admin Dashboard](https://i.imgur.com/j1yT99u.png)
 ![Admin Add Book Screen](https://i.imgur.com/fZA5Wgw.png)
 ![Admin Edit Book Screen](https://i.imgur.com/OpcCZqs.png)
 ## Installation/Usage
 - Clone this repo into a local repository
 - Run `cmake .` into `make`
 - Run main executable file `./run_main` to start the program
 - To run test files, run `./run_tests`
 - When prompted to enter a choice, enter a number corresponding to the available options.
 - Otherwise, input a string and press enter to submit the input.  
 ## Testing
 - The program was tested using the `googletest` submodule that is already inside the test directory.
 - Unit tests were manually run as listed in the Installation/Usage above.
 - All unit tests are compiled using `./run_tests` and were verified to be passing before pushing/merging to the main branch.
 

