#ifndef COMMANDLINEDB_COMMAND_H
#define COMMANDLINEDB_COMMAND_H

#include <string>

class Command {
public:
    virtual ~Command() = default;
    virtual bool execute() = 0;
};

#endif //COMMANDLINEDB_COMMAND_H
