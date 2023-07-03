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
    ~Store() = default;
    Store(const Store& ref);
    std::pair<iterator, bool> insert(std::string key, std::string value);
    iterator retrieve(const std::string& key);
    const_iterator remove(const std::string& key);
    [[nodiscard]] const std::string& getTitle() const;
private:
    std::string title;
    size_t record_;
    Tree tree_;
};

#endif //COMMANDLINEDB_STORE_H
