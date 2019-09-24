#pragma once
#include <string>
#include <iostream>
#include <experimental/filesystem>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "trie.hpp"
#include "document.hpp"
#include "doc_reader.hpp"
#include "config.hpp"
#include "string_utility.hpp"

using namespace std;
namespace fs = std::experimental::filesystem;

class App {
	struct Entry {
		int type;
		string name;
		Entry(int t, string s): type(t), name(s) {}
	};
	Config* config;
	Trie* trie;
	DocumentReader* reader;
	Validator* searchQueryValidator;
	unordered_set<string> indexed;
	vector<Entry> entries;
	StringUtility su;
	bool checkIndexExists();
	string fileListMenu();
	void LS();
	void updateIndexFile(const string&);
	void readIndexFile();
	void showAddMenu();
	void showMainMenu(int);
	void showIndexedFiles();
	bool deleteIndex();
public:
	App();
	void start();
	~App();
};
