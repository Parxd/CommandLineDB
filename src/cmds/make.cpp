#include <boost/algorithm/string/trim.hpp>
#include "../../include/store.h"
#include "../../include/cmds/make.h"

Make::Make(const std::string& args) {

    size_t commaPos1 = args.find(',');
    if (commaPos1 != std::string::npos) {
        std::string cols;
        title = args.substr(0, commaPos1);
        if (title.empty()) {
            throw std::invalid_argument("Invalid format.");
        }
        cols = args.substr(commaPos1 + 1);

        size_t commaPos2 = cols.find(',');
        if (commaPos2 != std::string::npos) {
            col1 = cols.substr(0, commaPos2);
            col2 = cols.substr(commaPos2 + 1);
            boost::trim_left(col1);
            boost::trim_left(col2);
            if (col1.empty() || col2.empty()) {
                throw std::invalid_argument("Invalid format.");
            }
        }
        else {
            throw std::invalid_argument("Invalid format.");
        }
    }
    else {
        throw std::invalid_argument("Invalid format.");
    }
    Store::instance()->state = 1;
    std::cout << "Connected to transient in-memory database." << "\n";
}
bool Make::execute() {
    Store::instance()->setTitle(title);
    Store::instance()->setCols(col1, col2);
    return true;
}
