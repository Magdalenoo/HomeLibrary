#ifndef HOMELIBRARY_LIBRARY_H
#define HOMELIBRARY_LIBRARY_H

#include <iostream>
#include <vector>
#include "../../include/Book/Book.h"

class Library {
private:
    std::vector<Book> books;

public:
    //Methods
    //Adding a book to the library
    void addBook(const Book& book){
        books.push_back(book);
    }

    //Removing a book from the library by isbn no.
    void removeBookISBN(const std::string& isbn){

        //Lambda expression - iterator find_if searches for an element for which function returns true.
        auto it = std::find_if(books.begin(), books.end(), [&](const Book& b) {return b.getISBN() == isbn; });
        if (it != books.end()){
            books.erase(it);
            std::cout << "Book removed successfully.\n";
        } else {
            std::cout << "Book not found\n";
        }
    }

    //Removing a book from the library by the title
    void removeBookTitle(const std::string& title){

        auto it = std::find_if(books.begin(), books.end(), [&](const Book& b) {return b.getTitle() == title; });
        if (it != books.end()){
            books.erase(it);
            std::cout<< "Book removed successfully.\n";
        } else {
            std::cout << "Book not found\n";
        }
    }

    //Searching for a book by the title
    std::vector<Book> searchByTitle(const std::string& title){
        std::vector<Book> result;
        for(const auto& book : books){
            if (book.getTitle() == title){
                result.push_back(book);
            }
        }
        return result;
    }

};


#endif //HOMELIBRARY_LIBRARY_H
