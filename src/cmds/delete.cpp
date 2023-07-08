#include "../../include/cmds/delete.h"
#include "../../include/store.h"

Delete::Delete(const std::string &k): key(k) {
    if (Store::instance()->state == 0) {
        throw std::logic_error("Not connected to database.");
    }
    if (k.empty()) {
        throw std::invalid_argument("Invalid deletion format.");
    }
}
bool Delete::execute() {
    Store::instance()->remove(key);
    return true;
}
