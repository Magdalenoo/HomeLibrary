#include <iostream>
#include <string>
#include "include/Book/Book.h"
#include "include/Library/Library.h"

int main() {

    const std::string dbName = "library.db";
    Library library(dbName);

    if(!library.openDatabase(dbName)){
        std::cerr << "Failed to open database." << std::endl;
        return 1;
    }

    int choice;

    std::cout << "----- Welcome to the Home Library! -----\n";
    std::cout << "What would you like to do?\n";
    std::cout << "1 - Show all books\n"
                 "2 - Add a book to the library\n"
                 "3 - Search for a book\n"
                 "4 - Remove a book\n";

    /*
    std::cin >> choice;
    switch (choice) {
        case 1:
            //Library::getAllBooks(books);
            break;

        case 2:
            std::string title;
            std::string author;
            std::string genre;
            std::string isbn;
            std::string location;

            std::cout << "Add book as follows: Title, Author, Genre, ISBN number, Location\n";
            std::cout << "Title: ";
            std::getline(std::cin,title);
            std::cout << "\nAuthor: ";
            std::getline(std::cin, author);
            std::cout << "\nGenre: ";
            std::getline(std::cin, genre);
            std::cout << "\nISBN number: ";
            std::getline(std::cin, isbn);
            std::cout << "Location: ";
            std::getline(std::cin, location);
            std::cout << "\n";

            Book bookToAdd(title, author, genre, isbn, location);


    }*/

    library.closeDatabase();

    return 0;
}
