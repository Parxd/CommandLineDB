#ifndef COMMANDLINEDB_GET_H
#define COMMANDLINEDB_GET_H

#include "../command.h"

class Get: public Command {
public:
    explicit Get(const std::string&);
    bool execute() override;
private:
    std::string key;
};

#endif //COMMANDLINEDB_GET_H
