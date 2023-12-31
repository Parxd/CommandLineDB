#ifndef COMMANDLINEDB_GET_H
#define COMMANDLINEDB_GET_H

#include "../command.h"

class Get: public Command {
public:
    explicit Get(Store&, const std::string&, int&);
    bool execute() override;
private:
    Store& store;
    std::string key;
    int& state;
};

#endif //COMMANDLINEDB_GET_H
