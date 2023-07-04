#ifndef COMMANDLINEDB_REPL_H
#define COMMANDLINEDB_REPL_H

#include <set>
#include "db.h"
#include "store.h"

class db;

class REPL {
public:
    explicit REPL(std::unique_ptr<db>);
    ~REPL() = default;
private:
    /**
     * @brief Prints help menu (internal REPL method b/c
     * doesn't affect anything on store)
     */
    void menu();
    void parse(std::string&);
    bool loop = false;
    static REPL* inst;
    std::unique_ptr<db> manager;
    std::unique_ptr<Store> store;
    std::set<std::string> commands;
};

#endif //COMMANDLINEDB_REPL_H
