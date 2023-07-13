#ifndef COMMANDLINEDB_FACTORY_H
#define COMMANDLINEDB_FACTORY_H

#include <memory>
#include <unordered_map>
#include "store.h"
#include "command.h"

class Factory {
public:
    Factory();
    virtual ~Factory() = default;
    virtual std::unique_ptr<Command> makeCommand(Store&, const std::string&, const std::string&);
    virtual std::unique_ptr<Command> makeConnectCommand(Store&, const std::string&);
    virtual std::unique_ptr<Command> makeMakeCommand(Store&, const std::string&);
    virtual std::unique_ptr<Command> makeInsertCommand(Store&, const std::string&);
    virtual std::unique_ptr<Command> makeGetCommand(Store&, const std::string&);
    virtual std::unique_ptr<Command> makeDeleteCommand(Store&, const std::string&);
private:
    typedef std::unique_ptr<Command> (Factory::*ptr)(Store&, const std::string&);
    std::unordered_map<std::string, ptr> commandMap;
};

#endif //COMMANDLINEDB_FACTORY_H
