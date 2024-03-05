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
    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setGenre(const std::string& genre);
    void setISBN(const std::string& isbn);
    void setLocation(const std::string& location);
};


#endif //HOMELIBRARY_BOOK_H
