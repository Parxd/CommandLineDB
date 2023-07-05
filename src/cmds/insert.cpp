#include "../../include/store.h"
#include "../../include/cmds/insert.h"

Insert::Insert(const std::string& args) {
    size_t commaPos = args.find(',');
    if (commaPos != std::string::npos) {
        key = args.substr(0, commaPos);
        value = args.substr(commaPos + 1);
    }
    else {
        throw std::invalid_argument("Invalid format.");
    }
}
bool Insert::execute() {
    Store::instance()->insert(key, value);
    return true;
}
