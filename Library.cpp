// Library.cpp , Actual functions go here
#include "Library.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <limits>
using namespace std;

vector<Book> library;
string tolowercase(string str) // start of case sensitive search function, converts a string to lowercase for case-insensitive comparisons
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Add Book
void addBook()
{
    int id;
    string title, author;

    cout << "Enter Book ID: ";
    while (!(cin >> id))
    {
        cout << "Invalid input. Enter a valid numeric Book ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Enter Book Title: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, title);
    cout << "Enter Book Author: ";
    getline(cin, author);
    if (title.empty() || author.empty())
    {
        cout << "Error: Title and Author cannot be empty.\n";
        return;
    }

    for (size_t i = 0; i < library.size(); i++)
    {
        if (library[i].id == id)
        {
            cout << "Book with ID " << id << " already exists.\n";
            return;
        }
    }

    saveToFile(); // Save to file after adding a book
}
// display books
void displayBooks()
{ /*dynamically displays all the books in the library with their details and availability status with library.size() to get the number of books
   in the library*/
    cout << "Displaying " << library.size() << " books:\n";
    for (int i = 0; i < library.size(); i++)
    {
        library[i].display();
    }
}

// borrow book
void borrowBook()
{
    int id;
    cout << "Enter ID of Book: ";
    while (!(cin >> id))
    {
        cout << "Invalid input. Enter a valid numeric Book ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 0; i < library.size(); i++)
    { // checks if the book is in the library and if it is available, then marks it as borrowed
        if (library[i].id == id && library[i].isAvailable)
        {
            library[i].isAvailable = false;
            saveToFile(); // Save to file after borrowing a book(auto-saves after each action to ensure data persistence)
            cout << "Book borrowed!\n";

            return;
        }
    }
    cout << "Book not available.\n";
}
// return book
void returnBook()
{
    int id;
    cout << "Enter Book ID: ";
    while (!(cin >> id))
    {
        cout << "Invalid input. Enter a valid numeric Book ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 0; i < library.size(); i++)
    { // checks if the book is in the library and if it is currently borrowed, then marks it as available again
        if (library[i].id == id && !library[i].isAvailable)
        {
            library[i].isAvailable = true;
            saveToFile(); // Save to file after returning a book
            cout << "Book returned!\n";

            return;
        }
    }
    cout << "Book not found or already available.\n";
}

// Search Book (case-insensitive and multiple mathces)
void searchBook()
{
    string title;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter title to search: ";
    getline(cin, title);

    // Convert user input to lowercase
    string searchTitle = tolowercase(title);
    bool found = false;

    for (int i = 0; i < library.size(); i++)
    {
        string bookTitleLower = tolowercase(library[i].title);
        if (bookTitleLower.find(searchTitle) != string::npos) // allows partial searches by checking if the search term is a substring of the book title.
        {
            library[i].display();
            found = true;
        }
    }

    if (!found)
    {
        cout << "Book not found.\n";
    }
}

/* Save to File saves the current state of the library to a text file named "library.txt" which changes every
time the user adds, borrows, returns, or searches for a book, allowing the library data to persist between program runs.*/
void saveToFile()
{
    ofstream outFile("library.txt");
    if (!outFile)
    {
        cout << "Error saving file!\n";
        return;
    }
    ofstream backupFile("library_backup.txt"); // Create a backup file
    if (!backupFile)
    {
        cout << "Error saving file!\n";
        return;
    }
    for (int i = 0; i < library.size(); i++)
    {
        string line = to_string(library[i].id) + "," + library[i].title + "," + library[i].author + "," + to_string(library[i].isAvailable) + "\n";
        outFile << line;
        backupFile << line; // Write to backup file as well
    }

    outFile.close();
    backupFile.close(); // Close the backup file
    cout << "Saved to file.\n";
}

/*Loads the library data from "library.txt" when the program starts, allowing the user to continue managing their library without
losing previously entered data. It reads each line of the file, extracts the book details, and populates the library vector accordingly.*/
void loadFromFile()
{
    ifstream inFile("library.txt");
    if (!inFile)
    {
        cout << "No existing library file found. Starting fresh.\n";
        return;
    }
    library.clear();

    int id;
    string title, author;
    bool status;

    while (inFile >> id)
    {
        inFile.ignore();
        getline(inFile, title, ',');
        getline(inFile, author, ',');
        inFile >> status;

        Book b(id, title, author);
        b.isAvailable = status;
        library.push_back(b);

        inFile.ignore();
    }

    inFile.close();
    cout << "Loaded from file.\n";
}
