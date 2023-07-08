#include <boost/algorithm/string/trim.hpp>
#include "../../include/store.h"
#include "../../include/cmds/insert.h"

Insert::Insert(const std::string& args) {
    if (Store::instance()->state == 0) {
        throw std::logic_error("Not connected to database.");
    }
    size_t commaPos = args.find(',');
    if (commaPos != std::string::npos) {
        key = args.substr(0, commaPos);
        value = args.substr(commaPos + 1);
        boost::trim_left(value);
        if (key.empty() || value.empty()) {
            throw std::invalid_argument("Invalid insertion format.");
        }
    }
    else {
        throw std::invalid_argument("Invalid insertion format.");
    }
}
bool Insert::execute() {
    Store::instance()->insert(key, value);
    return true;
}
