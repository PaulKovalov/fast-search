#pragma once
#include <string>
#include <unordered_set>

using namespace std;

class Validator {
    unordered_set<string> excluded_seqs;
   public:
    Validator(unordered_set<string>);
    bool valid_word(const string&);
};