#include "../include/store.h"

Store::Store(): tree_(), record_(0) {}
Store::Store(const Store &ref): tree_(ref.tree_), record_(ref.record_) {};
std::pair<iterator, bool> Store::insert(std::string key, std::string value) {
    ++record_;
    return tree_.insert(std::make_pair<std::string, std::string>(std::move(key), std::move(value)));
}
iterator Store::retrieve(const std::string& key) {
    return tree_.find(key);
}
const_iterator Store::remove(const std::string& key) {
    --record_;
    return tree_.erase(retrieve(key));
}
void Store::setTitle(const std::string& t) {
    title_ = t;
}
const std::string &Store::getTitle() const {
    return title_;
}
const size_t &Store::getRecord() const {
    return record_;
}
