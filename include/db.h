#ifndef COMMANDLINEDB_DB_H
#define COMMANDLINEDB_DB_H

#include "store.h"
#include "repl.h"

class REPL;

class db {
public:
    db();
    ~db() = default;
private:
    std::unique_ptr<Store> store;
    std::unique_ptr<REPL> repl;
};

#endif //COMMANDLINEDB_DB_H
