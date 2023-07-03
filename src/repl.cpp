#include <iostream>
#include "../include/repl.h"

REPL *REPL::inst = nullptr;
REPL *REPL::instance() {
    if (REPL::inst == nullptr) {
        REPL::inst = new REPL;
    }
    return REPL::inst;
}
REPL::REPL(): loop(true) {
    commands.insert(
            {"CONNECT", "MAKE", "DEFINE", "INSERT", "GET", "DELETE"}
            );
    while (loop) {
        std::string in;
        std::cout << "> ";
        std::getline(std::cin, in);
        parse(in);
    }
}
void REPL::parse(const std::string&) {

}

