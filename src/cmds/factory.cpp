#include "../../include/cmds/insert.h"
#include "../../include/cmds/factory.h"

Factory::Factory() {
    commandMap["INSERT"] = &Factory::makeInsertCommand;
}
Command* Factory::makeInsertCommand(const std::string &k, const std::string& v) {
    return new Insert(k, v);
}
