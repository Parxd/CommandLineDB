#ifndef COMMANDLINEDB_DELETE_H
#define COMMANDLINEDB_DELETE_H

#include "../command.h"

class Delete: public Command {
public:
    explicit Delete(Store&, const std::string&, int&);
    bool execute() override;
private:
    Store& store;
    std::string key;
    int& state;
};

#endif //COMMANDLINEDB_DELETE_H
