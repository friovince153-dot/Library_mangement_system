cmake_minimum_required(VERSION 3.10)
project(LibraryManagementSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    Final_project.cpp
    Book.cpp
    Library.cpp
    Loginandsignup.cpp
)

# Create executable
add_executable(Final_thesis ${SOURCES})

# Compiler-specific flags
if(MSVC)
    target_compile_options(Final_thesis PRIVATE /W4)
else()
    target_compile_options(Final_thesis PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Output directory
set_target_properties(Final_thesis PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
