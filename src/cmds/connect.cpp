#include <iostream>
#include <utility>
#include <filesystem>
#include <boost/filesystem.hpp>
#include "../../include/cmds/connect.h"

Connect::Connect(std::string args): filepath(std::move(args)) {
    if (!std::filesystem::exists(filepath)) {
        throw std::invalid_argument("Invalid format - formatting or file path is invalid.");
    }
    boost::filesystem::path filePath(filepath);
    if (boost::filesystem::exists(filePath)) {
        std::cout << "hello";
    }
}
bool Connect::execute() {
    return false;
}
