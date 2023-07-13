#ifndef COMMANDLINEDB_CONNECT_H
#define COMMANDLINEDB_CONNECT_H

#include "../command.h"

class Connect: public Command {
public:
    explicit Connect(Store&, std::string, int&);
    bool execute() override;
private:
    Store& store;
    std::string filepath;
    int& state;
};

#endif //COMMANDLINEDB_CONNECT_H
