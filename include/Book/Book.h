#ifndef HOMELIBRARY_BOOK_H
#define HOMELIBRARY_BOOK_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string genre;
    std::string isbn;
    std::string location;


public:
    //Constructor
    Book(std::string title, std::string author, std::string genre, std::string isbn, std::string location);

    //Getters
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getGenre() const;
    std::string getISBN() const;
    std::string getLocation() const;


    //Setters
    void setTitle(const std::string& newTitle);
    void setAuthor(const std::string& newAuthor);
    void setGenre(const std::string& newGenre);
    void setISBN(const std::string& newIsbn);
    void setLocation(const std::string& newLocation);
};


#endif //HOMELIBRARY_BOOK_H
