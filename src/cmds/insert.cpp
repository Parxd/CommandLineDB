#include "../../include/store.h"
#include "../../include/cmds/insert.h"

Insert::Insert(const std::string& args) {
    size_t commaPos = args.find(',');
    if (commaPos != std::string::npos) {
        key = args.substr(0, commaPos);
        value = args.substr(commaPos + 1);
    }
    else {
        std::cerr << "Invalid insertion format. See \"HELP\" for formatting." << std::endl;
    }
}
bool Insert::execute() {
    Store::instance()->insert(key, value);
    return true;
}
