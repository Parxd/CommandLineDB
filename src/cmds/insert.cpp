#include <boost/algorithm/string/trim.hpp>
#include "../../include/store.h"
#include "../../include/cmds/insert.h"

Insert::Insert(Store& str, const std::string& args): store(str) {
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
    store.insert(key, value);
    return true;
}
