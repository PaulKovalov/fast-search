#pragma once
#include <experimental/filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "document.hpp"

using namespace std;
namespace fs = std::experimental::filesystem;

class Trie {
    int h, tn, tc;
    int traverse(fs::path, int);
   public:
    Trie();
    void insert(Document*, string);
    unordered_map<string, int> search(vector<string>);
    unordered_map<string, int> info();
};
