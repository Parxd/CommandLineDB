#include "../../include/cmds/delete.h"
#include "../../include/store.h"

Delete::Delete(Store& str, const std::string &k): key(k), store(str) {
    if (k.empty()) {
        throw std::invalid_argument("Invalid deletion format.");
    }
}
bool Delete::execute() {
    store.remove(key);
    return true;
}
