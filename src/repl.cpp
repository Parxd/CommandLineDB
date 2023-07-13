#include <chrono>
#include <thread>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "../include/repl.h"

REPL::REPL(): loop(true), factory(), store(), state(0) {
    commands.insert(
            {"CONNECT", "DELETE", "GET", "INSERT", "MAKE", "VIEW", "HELP", "EXIT"}
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
    std::string loc = boost::erase_first_copy(in, cmd);
    boost::trim(loc);
    if (commands.find(upperCmd) != commands.end()) {
        try {
            factory.makeCommand(store, upperCmd, loc)->execute();
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
    else {
        std::cerr << "Unknown command. See \"HELP\" for all commands." << std::endl;
    }
}
