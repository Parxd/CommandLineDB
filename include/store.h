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
    int state;
    static Store* instance();
    ~Store() = default;
    Store(const Store& ref);
    std::pair<iterator, bool> insert(std::string key, std::string value);
    iterator retrieve(const std::string& key);
    const_iterator remove(const std::string& key);
    void setTitle(const std::string&);
    void setCols(const std::string &c1, const std::string &c2);
    [[nodiscard]] const std::string& getTitle() const;
    [[nodiscard]] const size_t& getRecord() const;
    [[nodiscard]] const_iterator getEnd() const;
    inline static bool status() {
        return bool(inst);
    }
private:
    Store();
    static Store* inst;
    std::string title_;
    std::pair<std::string, std::string> cols_;
    size_t record_;
    Tree tree_;
};

#endif //COMMANDLINEDB_STORE_H
