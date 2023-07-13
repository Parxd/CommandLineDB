#include <iostream>
#include <utility>
#include <filesystem>
#include "../../include/cmds/connect.h"

Connect::Connect(Store& str, std::string args, int& s): store(str), state(s) {
    if (std::filesystem::is_regular_file(args)) {
        // still need to check if it's a json file and a valid one at that too
        filepath = std::move(args);
    }
    else {
        auto curPath = std::string(std::filesystem::current_path());
        if (args.front() == '/') {
            curPath += args;
        }
        else {
            curPath += "/" + args;
        }
        if (std::filesystem::is_regular_file(curPath)) {
            // still need to check if it's a json file and a valid one at that too
            filepath = std::move(curPath);
        }
        else {
            throw std::invalid_argument("Invalid format - formatting or file path is invalid.");
        }
    }
    std::cout << "Connected to persistent database at " + filepath << ".\n";
}
bool Connect::execute() {
    if (state == 1) {
        std::cout << "Disconnecting from in-memory transient database.\n";
    }
    state = 2;
    return true;
}
