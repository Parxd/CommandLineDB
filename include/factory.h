#ifndef COMMANDLINEDB_FACTORY_H
#define COMMANDLINEDB_FACTORY_H

#include <memory>
#include <unordered_map>
#include "command.h"

class Factory {
public:
    Factory();
    virtual ~Factory() = default;
    virtual std::unique_ptr<Command> makeCommand(const std::string&, const std::string&);
    virtual std::unique_ptr<Command> makeConnectCommand(const std::string&);
    virtual std::unique_ptr<Command> makeMakeCommand(const std::string&);
    virtual std::unique_ptr<Command> makeInsertCommand(const std::string&);
    virtual std::unique_ptr<Command> makeGetCommand(const std::string&);
    virtual std::unique_ptr<Command> makeDeleteCommand(const std::string&);
private:
    typedef std::unique_ptr<Command> (Factory::*ptr)(const std::string&);
    std::unordered_map<std::string, ptr> commandMap;
};

#endif //COMMANDLINEDB_FACTORY_H
