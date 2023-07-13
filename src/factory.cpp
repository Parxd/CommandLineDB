#include "../include/factory.h"

#include "../include/cmds/connect.h"
#include "../include/cmds/make.h"
#include "../include/cmds/insert.h"
#include "../include/cmds/get.h"
#include "../include/cmds/delete.h"

Factory::Factory() {
    commandMap["CONNECT"] = &Factory::makeConnectCommand;
    commandMap["MAKE"] = &Factory::makeMakeCommand;
    commandMap["INSERT"] = &Factory::makeInsertCommand;
    commandMap["GET"] = &Factory::makeGetCommand;
    commandMap["DELETE"] = &Factory::makeDeleteCommand;
}
std::unique_ptr<Command> Factory::makeCommand(Store& str, const std::string &cmd, const std::string &args) {
    auto ptr = commandMap.find(cmd)->second;
    return (this->*ptr)(str, args);
}
std::unique_ptr<Command> Factory::makeConnectCommand(Store& str, const std::string &args) {
    return std::make_unique<Connect>(str, args);
}
std::unique_ptr<Command> Factory::makeMakeCommand(Store& str, const std::string &args) {
    return std::make_unique<Make>(str, args);
}
std::unique_ptr<Command> Factory::makeInsertCommand(Store& str, const std::string &args) {
    return std::make_unique<Insert>(str, args);
}
std::unique_ptr<Command> Factory::makeGetCommand(Store& str, const std::string &args) {
    return std::make_unique<Get>(str, args);
}
std::unique_ptr<Command> Factory::makeDeleteCommand(Store& str, const std::string &args) {
    return std::make_unique<Delete>(str, args);
}