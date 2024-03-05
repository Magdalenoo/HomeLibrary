#ifndef HOMELIBRARY_LIBRARY_H
#define HOMELIBRARY_LIBRARY_H

#include "../../include/Book/Book.h"
#include <iostream>
#include <vector>

class Library {
private:
    std::vector<Book> books;

public:

    //Constructor
    Library(std::vector<Book> books);

    //Methods
    //Adding a book to the library
    void addBook(const Book& book);

    //Removing a book from the library by isbn no.
    void removeBookISBN(const std::string& isbn);

    //Removing a book from the library by title
    void removeBookTitle(const std::string& title);

    //Searching for a book by title
    std::vector<Book> searchByTitle(const std::string& title);

    //Searching for a book by author
    std::vector<Book> searchByAuthor(const std::string& author);

    //Searching for a book by genre
    std::vector<Book> searchByGenre(const std::string& genre);

    //Retrieving all books from the library
    std::vector<Book> getAllBooks() const;

};


#endif //HOMELIBRARY_LIBRARY_H
