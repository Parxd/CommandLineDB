#include <stdexcept>
#include "../../include/cmds/get.h"
#include "../../include/store.h"

Get::Get(Store& str, const std::string& k): key(k), store(str) {
    if (k.empty()) {
        throw std::invalid_argument("Invalid retrieval format.");
    }
}

bool Get::execute() {
    store.retrieve(key);
    return false;
}
