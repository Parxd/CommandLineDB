#include <iostream>
#include "include/btree_map.h"

int main() {
    typedef btree::btree_map<int, int> MyMap;

    auto obj_map = new MyMap;
    MyMap::const_iterator lookup1 = obj_map->find(5);
    obj_map->insert(std::make_pair<int, int>(5, 3));
    MyMap::const_iterator lookup2 = obj_map->find(5);
    delete obj_map;

    return 0;
}
