#include <stdexcept>
#include "../../include/cmds/get.h"
#include "../../include/store.h"

Get::Get(const std::string& k): key(k) {
    if (Store::instance()->state == 0) {
        throw std::logic_error("Not connected to database.");
    }
    if (k.empty()) {
        throw std::invalid_argument("Invalid retrieval format.");
    }
}

bool Get::execute() {
    auto it = Store::instance()->retrieve(key);
    if (it != Store::instance()->getEnd()) {
        std::cout << "PAIR: " << it->first << ", " << it->second << "\n";
        return true;
    }
    std::cerr << "Key not found." << "\n";
    return false;
}
