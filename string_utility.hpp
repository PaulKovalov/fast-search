#pragma once
#include <cctype>
#include <string>
#include <vector>
using namespace std;

class StringUtility {
   public:
    StringUtility(){}
    vector<string> split(const string&, const string&);
    void tolower(string&);
    string trim(const string&);
};
