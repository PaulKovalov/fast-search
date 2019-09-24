#include "validator.hpp"
Validator::Validator(unordered_set<string> s) {
    this->excluded_seqs = s;
}
bool Validator::valid_word(const string& w) {
    if (excluded_seqs.find(w) != excluded_seqs.end()) {
        return false;
    }
    if (w.length() == 1) {
        return isalnum(w[0]);
    }
    return true;
}