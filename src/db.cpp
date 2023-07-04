#include <utility>

#include "../include/db.h"

db::db(): store(std::make_unique<Store>()),
        repl(std::make_unique<REPL>(std::unique_ptr<db>(this))) {}

void db::insert(std::string k, std::string v) {
    store->insert(std::move(k), std::move(v));
}

