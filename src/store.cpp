#include "../include/store.h"

Store::Store(): tree_(), record_(0), connect(false) {}
void Store::clear() {
    // save
    tree_.clear();
}
std::pair<iterator, bool> Store::insert(std::string key, std::string value) {
    auto it = tree_.insert(std::make_pair<std::string, std::string>(std::move(key), std::move(value)));
    ++record_;
    return it;
}
iterator Store::retrieve(const std::string& key) {
    return tree_.find(key);
}
const_iterator Store::remove(const std::string& key) {
    auto it = tree_.erase(retrieve(key));
    --record_;
    return it;
}
void Store::setTitle(const std::string& t) {
    title_ = t;
}
void Store::setCols(const std::string& c1, const std::string& c2) {
    cols_.first = c1;
    cols_.second = c2;
}
const std::string &Store::getTitle() const {
    return title_;
}
const size_t &Store::getRecord() const {
    return record_;
}
const_iterator Store::getEnd() const {
    return tree_.end();
}
void Store::setConnect(bool c) {
    connect = c;
}
bool Store::getConnect() const {
    return connect;
}
