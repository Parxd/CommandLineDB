#include "../include/db.h"

db::db(): store(std::make_unique<Store>()), repl(REPL::instance()) {
}
