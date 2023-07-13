#include <stdexcept>
#include "../../include/cmds/get.h"

Get::Get(Store& str, const std::string& k, int& s): key(k), store(str), state(s) {
    if (!state) {
        throw std::logic_error("Not connected to database--MAKE or CONNECT first.");
    }
    if (k.empty()) {
        throw std::invalid_argument("Invalid retrieval format.");
    }
}
bool Get::execute() {
    auto it = store.retrieve(key);
    if (it != store.getEnd()) {
        std::cout << it->first << ", " << it->second << "\n";
    }
    else {
        std::cout << "Key not found.\n";
        return false;
    }
    return true;
}
