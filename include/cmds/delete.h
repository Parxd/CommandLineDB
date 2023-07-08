#ifndef COMMANDLINEDB_DELETE_H
#define COMMANDLINEDB_DELETE_H

#include "../command.h"

class Delete: public Command {
public:
    explicit Delete(const std::string&);
    bool execute() override;
private:
    std::string key;
};

#endif //COMMANDLINEDB_DELETE_H
