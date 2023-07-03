cmake_minimum_required(VERSION 3.24)
project(CommandLineDB)

add_executable(CommandLineDB main.cpp)

target_sources(CommandLineDB PRIVATE
        ./src/store.cpp
        ./src/repl.cpp
        ./src/db.cpp
        )
