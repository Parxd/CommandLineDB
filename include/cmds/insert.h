#ifndef COMMANDLINEDB_INSERT_H
#define COMMANDLINEDB_INSERT_H

#include <string>
#include "../command.h"

class Insert: public Command {
public:
    explicit Insert(std::string, std::string);
    bool execute() override;
private:
    std::string key, value;
};

#endif //COMMANDLINEDB_INSERT_H
