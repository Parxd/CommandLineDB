#ifndef COMMANDLINEDB_INSERT_H
#define COMMANDLINEDB_INSERT_H

#include "../command.h"

class Insert: public Command {
public:
    explicit Insert(Store&, const std::string&, int&);
    bool execute() override;
private:
    Store& store;
    std::string key, value;
    int& state;
};

#endif //COMMANDLINEDB_INSERT_H
