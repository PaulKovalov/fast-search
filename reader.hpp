#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "string_utility.hpp"

using namespace std;

class FileReader {
   protected:
    StringUtility su;

   public:
    FileReader(){}
    vector<string> readFile(const string &);
};