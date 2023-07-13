#ifndef COMMANDLINEDB_REPL_H
#define COMMANDLINEDB_REPL_H

#include <set>
#include "store.h"
#include "command.h"
#include "factory.h"

class REPL {
public:
    REPL();
    ~REPL() = default;
private:
    /**
     * 0: None
     * 1: Transient
     * 2: Persistent
     */
    int state;
    void parse(std::string&);
    bool loop = false;
    Store store;
    Factory factory;
    std::set<std::string> commands;
};

#endif //COMMANDLINEDB_REPL_H
