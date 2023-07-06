cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 17)
project(CommandLineDB)

add_executable(CommandLineDB src/main.cpp)

target_sources(CommandLineDB PRIVATE
        ./src/store.cpp
        ./src/repl.cpp
        # cmds
        src/factory.cpp
        ./src/cmds/connect.cpp
        ./src/cmds/make.cpp
        ./src/cmds/insert.cpp
        ./src/cmds/get.cpp
        )
find_package(Boost REQUIRED COMPONENTS system filesystem)
target_link_libraries(CommandLineDB PRIVATE Boost::filesystem Boost::boost)