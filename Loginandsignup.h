#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct User
{
    string username;
    string password;
};

extern vector<User> users;

// functions
void registerUser();
bool loginUser();
void loadUsers();
void saveUsers();