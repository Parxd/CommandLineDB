#ifndef COMMANDLINEDB_REPL_H
#define COMMANDLINEDB_REPL_H

#include <set>
#include "store.h"
#include "command.h"
#include "cmds/factory.h"

class REPL {
public:
    REPL();
    ~REPL() = default;
private:
    /**
     * @brief Prints help menu (internal REPL method b/c
     *        doesn't affect anything in store)
     */
    static void menu();
    void parse(std::string&);
    bool loop = false;
    Factory factory;
    std::set<std::string> commands;
};

#endif //COMMANDLINEDB_REPL_H
