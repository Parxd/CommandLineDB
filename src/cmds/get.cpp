#include <utility>
#include <stdexcept>
#include "../../include/cmds/get.h"
#include "../../include/store.h"

Get::Get(const std::string& k): key(k) {
    if (k.empty()) {
        throw std::invalid_argument("Invalid insertion format.");
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
