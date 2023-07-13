cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
project(CommandLineDB)

add_executable(CommandLineDB src/main.cpp)

target_sources(CommandLineDB PRIVATE
        ./src/store.cpp
        ./src/repl.cpp
        ./src/factory.cpp
        # cmds
        ./src/cmds/connect.cpp
        ./src/cmds/make.cpp
        ./src/cmds/insert.cpp
        ./src/cmds/get.cpp
        ./src/cmds/delete.cpp
        )