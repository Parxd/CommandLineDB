#ifndef COMMANDLINEDB_CONNECT_H
#define COMMANDLINEDB_CONNECT_H

#include "../command.h"

class Connect: public Command {
public:
    explicit Connect(Store&, std::string);
    bool execute() override;
private:
    Store& store;
    std::string filepath;
};

#endif //COMMANDLINEDB_CONNECT_H
