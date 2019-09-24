#include "reader.hpp"
vector<string> FileReader::readFile(const string& filename) {
    ifstream fin(filename);
	if (!fin.is_open()) {
		throw runtime_error("Error opening file " + filename);
	}
    vector<string> words;
	string word;
	while (fin >> word) {
		words.push_back(word);
	}
	fin.close();
    return words;
}