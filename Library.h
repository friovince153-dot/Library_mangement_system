// Library.h, function declarations go here
#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

extern vector<Book> library; // dynamic array of books in the library, declared as extern to be accessible across multiple files
// function declarations for the program pretty self-explanatory.
void addBook();
void displayBooks();
void borrowBook();
void returnBook();
void searchBook();
void saveToFile();
void loadFromFile();
string tolowercase(string str); // function declaration for the case-insensitive search helper function

#endif