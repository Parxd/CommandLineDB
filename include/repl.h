#ifndef COMMANDLINEDB_REPL_H
#define COMMANDLINEDB_REPL_H

#include <set>
#include "store.h"

class REPL {
public:
    static REPL* instance();
    ~REPL() = default;
private:
    REPL();
    void parse(const std::string&);
    bool loop = false;
    static REPL* inst;
    std::unique_ptr<Store> store;
    std::set<std::string> commands;
};

#endif //COMMANDLINEDB_REPL_H
