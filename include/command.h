#ifndef COMMANDLINEDB_COMMAND_H
#define COMMANDLINEDB_COMMAND_H

#include <string>
#include "store.h"

class Command {
public:
    virtual ~Command() = default;
    virtual bool execute() = 0;
};

#endif //COMMANDLINEDB_COMMAND_H
