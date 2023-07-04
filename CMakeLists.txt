cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 17)
project(CommandLineDB)

add_executable(CommandLineDB src/main.cpp)

target_sources(CommandLineDB PRIVATE
        ./src/store.cpp
        ./src/repl.cpp
        ./src/db.cpp
        )
