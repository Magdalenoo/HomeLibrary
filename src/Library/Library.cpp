#include "../../include/Library/Library.h"
#include <iostream>
#include <vector>


Library::Library(std::vector<Book> books) : books(books) { }

//Methods
//Adding a book to the library
void Library::addBook(const Book& book){
    books.push_back(book);
}

//Removing a book from the library by isbn no.
void Library::removeBookISBN(const std::string& isbn){

    //Lambda expression - iterator find_if searches for an element for which function returns true.
    auto it = std::find_if(books.begin(), books.end(), [&](const Book& b) {return b.getISBN() == isbn; });
    if (it != books.end()){
        books.erase(it);
        std::cout << "Book removed successfully.\n";
    } else {
        std::cout << "Book not found\n";
    }
}

//Removing a book from the library by title
void Library::removeBookTitle(const std::string& title){

    auto it = std::find_if(books.begin(), books.end(), [&](const Book& b) {return b.getTitle() == title; });
    if (it != books.end()){
        books.erase(it);
        std::cout<< "Book removed successfully.\n";
    } else {
        std::cout << "Book not found\n";
    }
}

//Searching for a book by title
std::vector<Book> Library::searchByTitle(const std::string& title){
    std::vector<Book> result;
    for(const auto& book : books){
        if (book.getTitle() == title){
            result.push_back(book);
        }
    }
    return result;
}

//Searching for a book by author
std::vector<Book> Library::searchByAuthor(const std::string& author){
    std::vector<Book> result;
    for(const auto& book : books){
        if(book.getAuthor() == author){
            result.push_back(book);
        }
    }
    return result;
}

//Searching for a book by genre
std::vector<Book> Library::searchByGenre(const std::string &genre) {
    std::vector<Book> result;
    for(const auto book : books){
        if(book.getGenre() == genre){
            result.push_back(book);
        }
    }
    return result;
}

std::vector<Book> Library::getAllBooks() const {
    return books;
}




