#include "../../include/Book/Book.h"
#include <iostream>

//Parameterized constructor
Book::Book(std::string title, std::string author, std::string genre, std::string isbn, std::string location)
: title(title), author(author), genre(genre), isbn(isbn), location(location) {
}

//Getters
std::string Book::getTitle() const { return title; }

std::string Book::getAuthor() const { return author; }

std::string Book::getGenre() const { return genre; }

std::string Book::getISBN() const { return isbn; }

std::string Book::getLocation() const { return location; }

//Setters
void Book::setTitle(const std::string &newTitle){
    if (!title.empty()) {
        this->title = newTitle;
    } else {
        std::cout << "Title cannot be empty\n";
    }
}

void Book::setAuthor(const std::string& newAuthor) {
    if (!author.empty()) {
        this->author = newAuthor;
    } else {
        std::cout << "Author cannot be empty\n";
    }
}

void Book::setGenre(const std::string& newGenre) {
    if(!genre.empty()) {
        this->genre = newGenre;
    } else {
        this->genre = "None";
    }
}

void Book::setISBN(const std::string& newIsbn) {
    //Need to add checking for correct isbn no.
    this->isbn = newIsbn;
}

void Book::setLocation(const std::string& newLocation) {
    this->location = newLocation;
}