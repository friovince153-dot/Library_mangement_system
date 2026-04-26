// main.cpp contains the main function and menu for the library system
#include <limits>
#include <iostream>
#include <cstdlib> // for system()
#include "Library.h"
#include <thread>
#include <chrono>
#include "Loginandsignup.h"
using namespace std;

void realLoadingScreen()
{
    using namespace std::chrono;

    cout << "[ SYSTEM INITIALIZING... ]\n\n";

    string steps[] = {
        "> Booting core system...",
        "> Loading library database...",
        "> Initializing user authentication...",
        "> Connecting to storage...",
        "> Finalizing setup..."};

    // Step-by-step loading
    for (int i = 0; i < 5; i++)
    {
        cout << steps[i] << endl;
        this_thread::sleep_for(milliseconds(400));
    }

    cout << "\n";

    // Progress bar with percentage
    for (int i = 0; i <= 100; i++)
    {
        cout << "\rLoading: [";

        int progress = i / 2; // 50 chars width

        for (int j = 0; j < 50; j++)
        {
            if (j < progress)
                cout << "#";
            else
                cout << " ";
        }

        cout << "] " << i << "%";
        cout.flush();

        this_thread::sleep_for(milliseconds(20));
    }

    cout << "\n\nSystem Ready!\n";
    this_thread::sleep_for(milliseconds(500));

    // Clear screen before showing banner
    cout << "\033[2J\033[1;1H";

    // FINAL BANNER
    cout << R"(

 _     ___  ____  ____   _    ____  _   _
| |   |_ _|| __ )|  _ \ / \  |  _ \| \ | |
| |    | | |  _ \| |_) / _ \ | |_) |  \| |
| |___ | | | |_) |  _ </ ___ \|  _ <| |\  |
|_____|___|____/|_| \_/_/   \_\_| \_\_| \_|

        LIBRARY MANAGEMENT SYSTEM

)";
}

// Basic UI
void showMenu()
{

    cout << "=====================================" << endl;
    cout << "|          LIBRARY SYSTEM           |" << endl;
    cout << "=====================================" << endl;
    cout << "| Please select an option:          |" << endl;
    cout << "|-----------------------------------|" << endl;
    cout << "| 1. Add Book                       |" << endl;
    cout << "| 2. View Books                     |" << endl;
    cout << "| 3. Borrow Book                    |" << endl;
    cout << "| 4. Return Book                    |" << endl;
    cout << "| 5. Search Book                    |" << endl;
    cout << "| 6. Delete Book                    |" << endl;
    cout << "| 7. Save to File                   |" << endl;
    cout << "| 8. Load from File                 |" << endl;
    cout << "| 9. Exit                           |" << endl;
    cout << "=====================================" << endl;
    cout << "Enter choice: ";
}

// main function for the switch case menu and calling the functions from library.cpp
int main()
{
    cout << "\033[2J\033[1;1H"; // clear screen
    system("color 0A");         // green text on black

    realLoadingScreen(); // 👈 THIS is your "real program" feel

    loadUsers();

    int choice;

    do
    {
        cout << "====== LOGIN SYSTEM ======\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric.limits<streamsize>::max(), '\n');
            cout << "Invalid choice! Please enter a number.\n\n";
            continue;
        }

        if (choice == 1)
        {
            if (loginUser())
            {
                break; // proceed to library system
            }
        }
        else if (choice == 2)
        {
            registerUser();
        }

    } while (choice != 3);

    if (choice == 3)
        return 0;

    // 👇 AFTER LOGIN — your existing system starts
    loadFromFile();                                                // Load library data from file at startup
    cout << "Loaded " << library.size() << " books at startup.\n"; // loads the number of books loaded from the previous file at startup
    do
    {
        showMenu();
        cin >> choice;

        // Clear input buffer if invalid input was entered
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice!\n";
            cout << "\nPress ENTER to continue...";
            cin.get();
            cout << "\033[2J\033[1;1H";
            continue;
        }

        switch (choice)
        {
        case 1:
            do
            {
                addBook();
                cout << "Repeat? (y/n): "; /*after each action, the user is prompted to repeat the action
                 or return to the main menu*/
                char ch;
                cin >> ch;
                if (ch == 'n' || ch == 'N')
                    break;
            } while (true);
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            do
            {
                borrowBook();
                cout << "Repeat? (y/n): "; // same applies to each.
                char ch;
                cin >> ch;
                if (ch == 'n' || ch == 'N')
                    break;
            } while (true);
            break;
        case 4:
            do
            {
                returnBook();
                cout << "Repeat? (y/n): ";
                char ch;
                cin >> ch;
                if (ch == 'n' || ch == 'N')
                    break;
            } while (true);
            break;
        case 5:
            do
            {
                searchBook();
                cout << "Repeat? (y/n): ";
                char ch;
                cin >> ch;
                if (ch == 'n' || ch == 'N')
                    break;
            } while (true);
            break;
         case 6:
            do
            {
                deleteBook();
                cout << "Repeat? (y/n): ";
                char ch;
                cin >> ch;
                if (ch == 'n' || ch == 'N')
                    break;
            } while (true);
            break;
        case 7:
            do
            {
                saveToFile();
                cout << "Repeat? (y/n): ";
                char ch;
                cin >> ch;
                if (ch == 'n' || ch == 'N')
                    break;
            } while (true);
            break;
        case 8:
            do
            {
                loadFromFile();
                cout << "Repeat? (y/n): ";
                char ch;
                cin >> ch;
                if (ch == 'n' || ch == 'N')
                    break;
            } while (true);
            break;
        case 9:
            saveToFile(); // Save library data to file before exiting
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
        
        if (choice != 9)
        {
            cout << "\nPress ENTER to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            cout << "\033[2J\033[1;1H"; // this resets the console screen (works on most terminals)
        } /* system("cls"); // for Windows, but using ANSI escape codes for better compatibility and because system("cls") is not recommended
           for security reasons */

    } while (choice != 9);
    return 0;
}
