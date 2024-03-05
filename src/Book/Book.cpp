#include "../../include/Book/Book.h"
#include <iostream>

//Parameterized constructor
Book::Book(std::string title, std::string author, std::string genre, std::string isbn, std::string location) : title(title), author(author), genre(genre), isbn(isbn), location(location) {
}

//Getters
std::string Book::getTitle() const { return title; }

std::string Book::getAuthor() const { return author; }

std::string Book::getGenre() const { return genre; }

std::string Book::getISBN() const { return isbn; }

std::string Book::getLocation() const { return location; }

//Setters
void Book::setTitle(const std::string& title) {
    if (!title.empty()) {
        this->title = title;
    } else {
        std::cout << "Title cannot be empty\n";
    }
}

void Book::setAuthor(const std::string& author) {
    if (!author.empty()) {
        this->author = author;
    } else {
        std::cout << "Author cannot be empty\n";
    }
}

void Book::setGenre(const std::string& genre) {
    if(!genre.empty()) {
        this->genre = genre;
    } else {
        this->genre = "None";
    }
}

void Book::setISBN(const std::string &isbn) {
    //Need to add checking for correct isbn no.
    this->isbn = isbn;
}

void Book::setLocation(const std::string &location) {
    this->location = location;
}