#ifndef COMMANDLINEDB_STORE_H
#define COMMANDLINEDB_STORE_H

#include <string>

#include "btree.h"
#include "btree_map.h"

typedef btree::btree_map<std::string, std::string> Tree;
typedef Tree::iterator iterator;
typedef Tree::const_iterator const_iterator;

class Store {
public:
    Store();

    ~Store();

    Store(const Store& ref);

    std::pair<iterator, bool> insert(std::string key, std::string value);

    const_iterator retrieve(std::string key);

    const_iterator remove(std::string key);

private:
    Tree tree_;

};

#endif //COMMANDLINEDB_STORE_H
