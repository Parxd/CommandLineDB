#ifndef COMMANDLINEDB_MAKE_H
#define COMMANDLINEDB_MAKE_H

#include "../command.h"

class Make: public Command {
public:
    explicit Make(Store&, const std::string&, int&);
    bool execute() override;
private:
    Store& store;
    std::string title, col1, col2;
    int& state;
};

#endif //COMMANDLINEDB_MAKE_H
