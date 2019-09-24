#include <iostream>
#include "document.hpp"
#include "reader.hpp"
#include "validator.hpp"
#include "string_utility.hpp"
#include <algorithm>
#include <unordered_set>

class DocumentReader : public FileReader {
    Validator* validator;
    string filename;
   public:
    DocumentReader(Validator*);
    Document* getDocument(const string&);
};