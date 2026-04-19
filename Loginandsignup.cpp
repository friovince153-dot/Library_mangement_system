#include <fstream>
#include <iostream>
#include "Loginandsignup.h"
using namespace std;

vector<User> users;

void registerUser()
{
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    for (auto &u : users)
    {
        if (u.username == username)
        {
            cout << "Username already exists!\n";
            return;
        }
    }
    cout << "Enter password: ";
    cin >> password;
    users.push_back({username, password});
    saveUsers();
    cout << "Registration successful!\n";
}

bool loginUser()
{
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    for (auto &u : users)
    {
        if (u.username == username && u.password == password)
        {
            cout << "Login successful!\n";
            return true;
        }
    }
    cout << "Invalid username or password.\n";
    return false;
}

void saveUsers()
{
    ofstream out("users.txt");
    for (auto &u : users)
    {
        out << u.username << "," << u.password << endl;
    }
    out.close();
}

void loadUsers()
{
    ifstream in("users.txt");
    users.clear();
    string username, password;
    while (getline(in, username, ',') && getline(in, password))
    {
        users.push_back({username, password});
    }
    in.close();
}
