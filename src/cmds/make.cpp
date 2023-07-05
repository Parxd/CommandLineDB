#include "../../include/store.h"
#include "../../include/cmds/make.h"

Make::Make(const std::string& args) {
    size_t commaPos1 = args.find(',');
    if (commaPos1 != std::string::npos) {
        std::string cols;
        title = args.substr(0, commaPos1);
        cols = args.substr(commaPos1 + 1);

        size_t commaPos2 = cols.find(',');
        if (commaPos2 != std::string::npos) {
            col1 = cols.substr(0, commaPos2);
            col2 = cols.substr(commaPos2 + 1);
        }
        else {
            throw std::invalid_argument("Invalid format.");
        }
    }
    else {
        throw std::invalid_argument("Invalid format.");
    }
}
bool Make::execute() {
    return false;
}
