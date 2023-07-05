#include "../../include/cmds/factory.h"

#include "../../include/cmds/connect.h"
#include "../../include/cmds/make.h"
#include "../../include/cmds/insert.h"

Factory::Factory() {
    commandMap["CONNECT"] = &Factory::makeConnectCommand;
    commandMap["MAKE"] = &Factory::makeMakeCommand;
    commandMap["INSERT"] = &Factory::makeInsertCommand;
}
Command *Factory::makeCommand(const std::string &cmd, const std::string &args) {
    auto ptr = commandMap.find(cmd)->second;
    return (this->*ptr)(args);
}

Command *Factory::makeConnectCommand(const std::string &args) {
    return new Connect(args);
}
Command *Factory::makeMakeCommand(const std::string &args) {
    return new Make(args);
}
Command* Factory::makeInsertCommand(const std::string &args) {
    return new Insert(args);
}