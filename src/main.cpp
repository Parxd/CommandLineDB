#include <boost/program_options.hpp>
#include "../include/repl.h"

int main() {
    // Uninitialized: Start program without args (must use MAKE/CONNECT before any other cmd) (0)
    // Transient: Connected to in-memory (1)
    // Persistent: Start program with args, connected to a file (2)

    // start w no args -> 0 -> make -> 1
    // start w no args -> 0 -> connect -> 2
    // start w args -> 2

    REPL repl;
    return 0;
}
