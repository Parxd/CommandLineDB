#include <chrono>
#include <thread>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "../include/repl.h"
#include "../include/cmds/insert.h"

REPL::REPL(): loop(true) {
    while (loop) {
        std::string in;
        std::cout << "> ";
        std::getline(std::cin, in);
        parse(in);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
void REPL::parse(std::string& in) {
    boost::trim(in);
    std::string cmd = in.substr(0, in.find(' '));
    std::string upperCmd = boost::to_upper_copy(cmd);
    std::string loc = boost::erase_first_copy(in, cmd);
    boost::trim(loc);
    if (upperCmd == "HELP") {
        menu();
    }
    else if (upperCmd == "CONNECT") {

    }
    else if (upperCmd == "MAKE") {

    }
    else if (upperCmd == "DEFINE") {

    }
    else if (upperCmd == "INSERT") {
        std::string v1, v2;
        size_t commaPos = loc.find(',');
        if (commaPos != std::string::npos) {
            v1 = loc.substr(0, commaPos);
            v2 = loc.substr(commaPos + 1);
        }
    }
    else if (upperCmd == "GET") {

    }
    else if (upperCmd == "DELETE") {

    }
    else if (upperCmd == "VIEW") {

    }
    else if (upperCmd == "EXIT") {
        loop = false;
        // save to file (also need save to file on dtor of store object)
    }
    else {
        std::cerr << "Unknown command. Type \"HELP\" for all commands." << std::endl;
    }
}
void REPL::menu() {
    std::cout << "-- Options --" << "\n";
    // DB mgmt
    std::cout << "CONNECT <file> --connect to existing database file path" << "\n";
    std::cout << "MAKE <title> --name of new database to be created" << "\n";
    std::cout << "DEFINE <column 1, column 2> --column names for key, value pairs" << "\n\n";
    // Data mgmt
    std::cout << "INSERT <key, value> --pair to be inserted" << "\n";
    std::cout << "GET <key> --key of pair to be retrieved" << "\n";
    std::cout << "DELETE <key> --key of pair to be deleted" << "\n\n";
    // Misc
    std::cout << "VIEW --view database info" << "\n";
    std::cout << "HELP --view options menu" << "\n";
    std::cout << "EXIT --exit database application" << std::endl;
}