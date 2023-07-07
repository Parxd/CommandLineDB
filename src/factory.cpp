#include "../include/factory.h"

#include "../include/cmds/connect.h"
#include "../include/cmds/make.h"
#include "../include/cmds/insert.h"
#include "../include/cmds/get.h"

Factory::Factory() {
    commandMap["CONNECT"] = &Factory::makeConnectCommand;
    commandMap["MAKE"] = &Factory::makeMakeCommand;
    commandMap["INSERT"] = &Factory::makeInsertCommand;
    commandMap["GET"] = &Factory::makeGetCommand;
}
std::unique_ptr<Command> Factory::makeCommand(const std::string &cmd, const std::string &args) {
    auto ptr = commandMap.find(cmd)->second;
    return (this->*ptr)(args);
}
std::unique_ptr<Command> Factory::makeConnectCommand(const std::string &args) {
    return std::make_unique<Connect>(args);
}
std::unique_ptr<Command> Factory::makeMakeCommand(const std::string &args) {
    return std::make_unique<Make>(args);
}
std::unique_ptr<Command> Factory::makeInsertCommand(const std::string &args) {
    return std::make_unique<Insert>(args);
}
std::unique_ptr<Command> Factory::makeGetCommand(const std::string &args) {
    return std::make_unique<Get>(args);
}