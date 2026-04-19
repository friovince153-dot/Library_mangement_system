# Library Management System

A C++ console application for managing a library's book inventory with user authentication.

## Features

- **User Authentication**: Register and login system
- **Book Management**: Add, view, borrow, and return books
- **Search**: Case-insensitive book title search
- **Persistence**: Automatic saving/loading from files
- **Backup**: Automatic backup file creation

## Prerequisites

- **C++ Compiler** (g++, clang, MSVC)
- **CMake** 3.10 or higher (recommended)

## Building Instructions

### Option 1: Using CMake (Recommended - Works on all platforms)

#### Windows:
```bash
mkdir build
cd build
cmake ..
cmake --build .
.\bin\Final_thesis.exe
```

#### Linux/macOS:
```bash
mkdir build
cd build
cmake ..
make
./bin/Final_thesis
```

### Option 2: Using g++ directly

#### Windows (MinGW):
```bash
g++ Book.cpp Library.cpp Loginandsignup.cpp Final_project.cpp -o Final_thesis -std=c++17
Final_thesis.exe
```

#### Linux/macOS:
```bash
g++ Book.cpp Library.cpp Loginandsignup.cpp Final_project.cpp -o Final_thesis -std=c++17
./Final_thesis
```

### Option 3: Using your IDE

- **Visual Studio Code**: Install C/C++ extension
- **Visual Studio**: Create a new C++ console project and add these files
- **Code::Blocks**: Create a project and add source files

## File Structure

```
.
├── Final_project.cpp       # Main program
├── Book.cpp                # Book class implementation
├── Book.h                  # Book class header
├── Library.cpp             # Library functions
├── Library.h               # Library header
├── Loginandsignup.cpp      # Authentication
├── Loginandsignup.h        # Authentication header
├── CMakeLists.txt          # CMake build configuration
├── .gitignore              # Git ignore file
└── README.md               # This file
```

## Usage

1. **Register**: Create a new account with username and password
2. **Login**: Enter credentials to access the library system
3. **Manage Books**: Use the menu to add, view, borrow, or return books
4. **Search**: Find books by partial title matching
5. **Save/Load**: Data automatically saves, or manually load from file

## Data Files Generated

- `users.txt` - Registered user credentials
- `library.txt` - Book inventory data
- `library_backup.txt` - Backup of library data

## Platform Support

✓ Windows (MinGW, MSVC, Clang)
✓ Linux (g++, clang)
✓ macOS (g++, clang)

## System Requirements

- 1 MB disk space
- Console/Terminal emulator
- C++ standard library

## Troubleshooting

### "Command not found: g++"
- Install MinGW (Windows) or XCode Command Line Tools (macOS)

### UTF-8/Symbol Issues
- Console should handle ASCII output correctly

### File Not Found Errors
- Run program from the project directory where `.txt` files are created

## License

Educational project

## Author

Created as a semester project
