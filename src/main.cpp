#include <iostream>
#include "../include/btree_map.h"
#include "../include/repl.h"

typedef btree::btree_map<int, int> MyMap;

int main() {
    auto obj_map = new MyMap;
    MyMap::const_iterator lookup1 = obj_map->find(5);
    obj_map->insert(std::make_pair<int, int>(5, 3));
    MyMap::const_iterator lookup2 = obj_map->find(5);
    delete obj_map;

    // command branch: use command pattern + make store a static singleton so repl doesn't need to
    // be coupled with store
    Store::instance();
    REPL repl;

    return 0;
}
