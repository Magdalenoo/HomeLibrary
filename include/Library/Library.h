#ifndef HOMELIBRARY_LIBRARY_H
#define HOMELIBRARY_LIBRARY_H

#include "../../include/Book/Book.h"
#include <iostream>
#include <string>
#include <sqlite3.h>

class Library {
private:
    //The SQLite database connection handle
    sqlite3* db;

public:
    Library(const std::string& dbName);
    ~Library();

    //Methods
    bool openDatabase(const std::string& dbName);
    void createTables();
    bool addBook(const Book& book);
    bool removeBook(int id);
    std::vector<Book> getAllBooks();
    void closeDatabase();
/*
    //Searching for a book by title


    //Searching for books by author


    //Searching for books by genre


    //Retrieving all books from the library

*/
};

#endif //HOMELIBRARY_LIBRARY_H
