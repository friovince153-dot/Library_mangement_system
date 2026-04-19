// variables and functions related to book class go here
#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;
// Book class definition and accessibility with its ID, title, author, and availability status
class Book
{
public: // can be accessible from other files and functions
    int id;
    string title;
    string author;
    bool isAvailable;

    Book(int i, string t, string a);
    void display(); // displaying information about the book
};

#endif