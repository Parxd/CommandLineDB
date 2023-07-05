#include <iostream>
#include <utility>
#include <filesystem>
#include "../../include/cmds/connect.h"

Connect::Connect(std::string args): filepath(std::move(args)) {}
bool Connect::execute() {
    if (std::filesystem::exists(filepath)) {
        std::cout << "Connected to persistent file on disk at " + filepath << std::endl;
        // do stuff
        return true;
    }
    else {
        std::cerr << "Invalid filepath." << std::endl;
        return false;
    }
}
