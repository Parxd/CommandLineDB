#include "../../include/cmds/delete.h"

Delete::Delete(Store& str, const std::string &k, int& s): key(k), store(str), state(s) {
    if (!state) {
        throw std::logic_error("Not connected to database--MAKE or CONNECT first.");
    }
    if (k.empty()) {
        throw std::invalid_argument("Invalid deletion format.");
    }
}
bool Delete::execute() {
    auto it = store.remove(key);
    if (it == store.getEnd()) {
        std::cout << "Key not found.\n";
        return false;
    }
    return true;
}
