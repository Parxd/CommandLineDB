#include "../../include/cmds/delete.h"
#include "../../include/store.h"

Delete::Delete(Store& str, const std::string &k, int& s): key(k), store(str), state(s) {
    if (!state) {
        throw std::logic_error("Not connected to database--MAKE or CONNECT first.");
    }
    if (k.empty()) {
        throw std::invalid_argument("Invalid deletion format.");
    }
}
bool Delete::execute() {

    return true;
}
