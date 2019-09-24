#pragma once
#include <fstream>
#include <string>
#include <iterator>
#include <vector>
#include <unordered_set>
using namespace std;

class Document {
	unordered_set<string> words;	
public:
	Document(unordered_set<string> words);
	unordered_set<string>::iterator begin();
	unordered_set<string>::const_iterator begin() const;
	unordered_set<string>::iterator end();
	unordered_set<string>::const_iterator end() const;
};
