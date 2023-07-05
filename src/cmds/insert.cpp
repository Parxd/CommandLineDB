#include <utility>
#include "../../include/store.h"
#include "../../include/cmds/insert.h"

Insert::Insert(std::string k, std::string v): key(std::move(k)), value(std::move(v)) {}
bool Insert::execute() {
    Store::instance()->insert(key, value);
    return true;
}
