cmake_minimum_required(VERSION 3.27)
project(HomeLibrary)

set(CMAKE_CXX_STANDARD 20)

#Find SQLite library
find_package(SQLite3 REQUIRED)

include_directories(include)

add_executable(HomeLibrary main.cpp
        src/Book/Book.cpp
        include/Book/Book.h
        src/Library/Library.cpp
        include/Library/Library.h)

#Link against the SQLite library
target_link_libraries(HomeLibrary SQLite::SQLite3)