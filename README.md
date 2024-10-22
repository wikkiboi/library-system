# \LibraryLink\

> Authors: \<[Matthew Godinez](https://github.com/jarvisghost13)\>, \<[Ricky Ho](https://github.com/wikkiboi)\>, \<[Tareq Hassan](https://github.com/Thass004)\>, \<[Haishan Zhao](https://github.com/HaiShan-el)\>, \<[Advit Singh](https://github.com/Ghostmaster-UI)\>

## Project Description

> ## Overview
> LibraryLink is a Library Management System that allows users to sign up, log in, and borrow books from the library database. The system provides users with personalized features such as book recommendations and account management for borrow lists. It also includes an interface for administrators that can add, edit, and remove books in the library's catalog.
> ## Why is this important or interesting to us?
> Libraries play an essential role in providing access to education, research, and entertainment. We want to create software that is user-friendly for people of all ages and can also provide to the user beyond the software itself. By building a management system that mimics what a real-life library can provide, we are not only grasping a better understanding of object-oriented design and software accessibility, but we are also promoting the wonders of reading and lifelong learning to people of all ages.
> ## Tools and Technologies
> * Programming Language: C++ IDE: Visual Studio Code
> * Version Control: Git & GitHub
> * User Authentication: libbcrypt https://github.com/trusch/libbcrypt
> ## Features
> * Login/Register with User Authentication
> * Account Recovery using assigned ID and security questions
> * Regular Users:
>   * View/manage account status, debt, password/security questions
>   * Browse Available Book Catalog. Books are organized by genre/sub-genre
>   * Get Book Recommendations based on borrow history
>   * Borrow/Renew/Return Book with an issue period of 30 days. The renewal period is 7 additional days with a limit of 3 per issue period.
>   * If any books are overdue for over 14 days, the account will be locked from borrowing until the overdue books are returned.
>   * View Borrow history
> * Administrator:
>   * View/manage account status, password/security questions -Manage password/security questions
>   * Browse Book Catalog with Borrow Status
>   * Add/Update/Remove Books from Catalog
> ## Input/Output
> * Main Menu Screen:
>   * Login
>   * Input username or ID
>   * Input password
>   * If either is invalid, alert the user and then send them back to the main menu
> * Register
>   * Ask if this account is for administrative purposes.
>   * If yes, prompt for an ID (from a predetermined list of available IDs to be implemented) and universal security question answer
purposes.
>   * If verified, alert the user and continue on to registration
>   * Input username (check if the username is taken)
>   * If the username is taken, prompt the user to input -Input password
>   * Confirm password
>   * Output generated ID if regular user and alert user to keep for account recovery
> * Forgot username/password?
>   * Prompt for ID and security question answer set by the user (if none set by the user, ask for date of account creation MM/YYYY
>   * If verified, ask to reset username or password.
>   * For either option, prompt for input and then a 2nd input asking for the same input for confirmation.
>   * Once logged in or registered, bring the user to the appropriate interface 
> * Regular User Interface
>   * Choose between options 1-7
>   * 1: Account Info
>     * Show Current Borrow Count -Show ID
>     * Change Username/Password
>     * View/Set security questions
>       * View current security questions
>       * Pick a question from a list of security questions to use
>       * Input password for verification
>       * Set answer for the selected question
>   * 2: Browse Catalog showing Availability status
>     * Sort By Genre/Author/Alphabetical/ID
>     * Output list of catalog with pagination
>   * 3: Get Book Recommendations
>     * Output list of recommended books based on borrow history genres, authors, etc. 
>   * 4: Borrow Book
>     * Similar output to browsing catalog but showing only available books
>     * Input number corresponding to the displayed list of books
deadline
>     * Input confirming borrow status
>     * Output borrowed book details, borrow date, and return deadline
>   * 5: Return/Renew Book
>     * Choose from the list of borrowed books listed by number
>     * Pick between return and renew
>     * Input confirming selected option
>     * Output return confirmation or renew confirmation with an extended return
>   * 6: View Borrow Status/History
>   * 7: Log Out
> * Admin Interface:
>   * -Choose between options 1-5 
>   * 1: Account Info
>   * 2: Browse Current Catalog
>   * 3: Add/Update/Remove Book Catalog 
>   * 4: View Borrower Status
>   * 5: Log out
