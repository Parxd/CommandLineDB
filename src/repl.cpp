#include <iostream>
#include <chrono>
#include <thread>
#include <boost/algorithm/string.hpp>
#include "../include/repl.h"

REPL::REPL(std::unique_ptr<db> db): loop(true), manager(std::move(db)) {
    commands.insert(
            {"HELP", "CONNECT", "MAKE", "DEFINE", "INSERT", "GET", "DELETE", "EXIT", "VIEW"}
            );
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
    if (commands.find(upperCmd) != commands.end()) {
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
            manager->insert(loc, loc);
        }
        else if (upperCmd == "GET") {

        }
        else if (upperCmd == "DELETE") {

        }
        else if (upperCmd == "VIEW") {

        }
        else {
            loop = false;
            // save to file (also need save to file on dtor of store object)
        }
    }
    else {
        std::cerr << "Unknown command. Type \"HELP\" for all commands." << std::endl;
    }
}
void REPL::menu() {
    int c = 0;
    std::cout << "\n";
    std::cout << "Options: " << "\n";
    for (auto &i : commands) {
        std::cout << i;
        switch (c) {
            case 0:
                std::cout << " <filename> --path to existing database file";
                break;
            case 1:
                std::cout << " <column 1, column 2> --column names for key, value pairs";
                break;
            case 2:
                std::cout << " <key> --key of pair to be deleted";
                break;
            case 3:
                std::cout << " --exit database application";
                break;
            case 4:
                std::cout << " <key> //key of pair to be retrieved";
                break;
            case 5:
                std::cout << " --view options menu";
                break;
            case 6:
                std::cout << " <key, value> --pair to be inserted";
                break;
            case 7:
                std::cout << " <title> --name of new database to be created";
                break;
            case 8:
                std::cout << " --view database info";
                break;
            default:
                break;
        }
        std::cout << "\n";
        ++c;
    }
    std::cout << std::endl;
}