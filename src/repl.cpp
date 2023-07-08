#include <chrono>
#include <thread>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "../include/repl.h"

REPL::REPL(): loop(true), factory() {
    commands.insert(
            {"CONNECT", "MAKE", "INSERT", "GET", "DELETE", "VIEW", "HELP", "EXIT", "DISCONNECT"}
            );
    while (loop) {
        std::string in;
        std::cout << "> ";
        std::getline(std::cin, in);
        parse(in);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
REPL::~REPL() {
    delete Store::instance();
}
void REPL::parse(std::string& in) {
    boost::trim(in);
    std::string cmd = in.substr(0, in.find(' '));
    std::string upperCmd = boost::to_upper_copy(cmd);
    std::string loc = boost::erase_first_copy(in, cmd);
    boost::trim(loc);
    if (commands.find(upperCmd) != commands.end()) {
        if (upperCmd == "HELP") {
            menu();
        }
        else if (upperCmd == "DISCONNECT") {
            if (Store::status()) {
                delete Store::instance();
                std::cout << "Disconnected from database." << "\n";
            }
            else {
                std::cerr << "Not connected to database." << "\n";
            }
        }
        else if (upperCmd == "EXIT") {
            loop = false;
            if (Store::instance()->state == 2) {
                // save
            }
        }
        else {
            try {
                factory.makeCommand(upperCmd, loc)->execute();
            }
            // Input errors
            catch (std::invalid_argument& err) {
                std::cerr << std::string(err.what()) + " See \"HELP\" for formatting." << std::endl;
            }
            // State errors
            catch (std::logic_error& err) {
                std::cerr << "Error: " << err.what() << std::endl;
            }
        }
    }
    else {
        std::cerr << "Unknown command. See \"HELP\" for all commands." << std::endl;
    }
}
void REPL::menu() {
    std::cout << "-- Options --" << "\n";
    // DB mgmt
    std::cout << "CONNECT <file> --connect to existing database file path" << "\n";
    std::cout << "MAKE <title, col1, col2> "
                 "--name of new database to be created, column names for key, value pairs" << "\n";
    // Data mgmt
    std::cout << "INSERT <key, value> --pair to be inserted" << "\n";
    std::cout << "GET <key> --key of pair to be retrieved" << "\n";
    std::cout << "DELETE <key> --key of pair to be deleted" << "\n";
    // Misc
    std::cout << "VIEW --view database info" << "\n";
    std::cout << "HELP --view options menu" << "\n";
    std::cout << "EXIT --exit database application" << "\n";

    std::cout << "-------------" << std::endl;
}
