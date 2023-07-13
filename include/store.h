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
    void clear();
    std::pair<iterator, bool> insert(std::string key, std::string value);
    iterator retrieve(const std::string& key);
    const_iterator remove(const std::string& key);
    void setTitle(const std::string&);
    void setCols(const std::string &c1, const std::string &c2);
    void setConnect(bool);
    [[nodiscard]] const std::string& getTitle() const;
    [[nodiscard]] const size_t& getRecord() const;
    [[nodiscard]] const_iterator getEnd() const;
    [[nodiscard]] bool getConnect() const;
private:
    std::string title_;
    std::pair<std::string, std::string> cols_;
    size_t record_;
    Tree tree_;
    bool connect;
};

#endif //COMMANDLINEDB_STORE_H
