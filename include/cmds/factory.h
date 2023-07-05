#ifndef COMMANDLINEDB_FACTORY_H
#define COMMANDLINEDB_FACTORY_H

#include <unordered_map>
#include "../command.h"

class Factory {
public:
    Factory();
    virtual ~Factory() = default;
    virtual Command* makeCommand(const std::string&, const std::string&);
    virtual Command* makeConnectCommand(const std::string&);
    virtual Command* makeMakeCommand(const std::string&);
    virtual Command* makeInsertCommand(const std::string&);

private:
    typedef Command* (Factory::*ptr)(const std::string&);
    std::unordered_map<std::string, ptr> commandMap;
};

#endif //COMMANDLINEDB_FACTORY_H
