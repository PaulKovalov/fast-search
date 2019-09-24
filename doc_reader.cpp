#include "doc_reader.hpp"
DocumentReader::DocumentReader(Validator* v):FileReader() {
    this->validator = v;
}
Document* DocumentReader::getDocument(const string& filename) {
    vector<string> content = this->readFile(filename);
    unordered_set<string> validated;
    for (auto str: content) {
        su.tolower(str);
        string w = su.trim(str);
        if (this->validator->valid_word(w)) {
            validated.insert(w);
        }
    }
    return new Document(validated);
}