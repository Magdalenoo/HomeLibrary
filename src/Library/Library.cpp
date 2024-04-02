#include "../../include/Library/Library.h"
#include <iostream>
#include <string>

//Constructor
Library::Library(const std::string& dbName) : db(nullptr) {
    //Initializing the SQLite database connection
    //c_str() - converts string to array of chars
    int rc = sqlite3_open(dbName.c_str(), &db);
    if (rc != SQLITE_OK){
            std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
    } else {
        createTables();
    }
}

bool Library::openDatabase(const std::string& dbName){
    if(db){
        std::cerr << "Database is already open.\n";
        return false;
    }
    int rc = sqlite3_open(dbName.c_str(), &db);
    if (rc != SQLITE_OK){
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    return true;
}

void Library::createTables() {
    std::string sql = "CREATE TABLE IF NOT EXISTS books ("
                      "id INTEGER PRIMARY KEY,"
                      "title TEXT NOT NULL,"
                      "author TEXT NOT NULL,"
                      "isbn TEXT,"
                      "genre TEXT,"
                      "rate INT,"
                      "location TEXT"
                      ");";
    char* errMsg;
    // Function used to execute one or multiple SQL statements against a database
    int result = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (result != SQLITE_OK) {
        std::cerr << "Error creating table: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

//Destructor
Library::~Library(){
    closeDatabase();
}

//Closing database
void Library::closeDatabase() {
    if(db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

//Adding a book to the library
bool Library::addBook(const Book& book){
    std::string sql = "INSERT INTO books (title, author, isbn, genre, rate, location) "
                      "VALUES (?, ?, ?, ?, ?, ?);";

    //The prepared statement handle
    sqlite3_stmt* stmt;
    //Function used to compile an SQL statement into a program that SQLite understands
    int result = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if(result != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    //Function used to bind a string to a parameter in prepared SQL statement
    sqlite3_bind_text(stmt, 1, book.getTitle().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, book.getAuthor().c_str(), -1, SQLITE_STATIC);
}


