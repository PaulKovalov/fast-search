#include "document.hpp"
Document::Document(unordered_set<string> words) {
	this->words = words;
}
unordered_set<string>::iterator Document::begin() {
	return words.begin();
}
unordered_set<string>::const_iterator Document::begin() const {
	return begin();
}
unordered_set<string>::iterator Document::end() {
	return words.end();
}
unordered_set<string>::const_iterator Document::end() const {
	return end();
}
