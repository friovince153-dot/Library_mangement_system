// main program for checking a book status, borrowing and returning a book, and searching for a book by title
#include "Book.h"
#include <iostream>
using namespace std;
// Book class implementation
Book::Book(int i, string t, string a)
{
    id = i;
    title = t;
    author = a;
    isAvailable = true;
}
// displaying information about the book
void Book::display()
{
    cout << "ID: " << id
         << " | Title: " << title
         << " | Author: " << author
         << " | Status: " << (isAvailable ? "Available" : "Borrowed")
         << endl;
}