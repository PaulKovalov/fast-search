#include <string>
#include <unordered_set>
#include <vector>
#include "reader.hpp"
#include "validator.hpp"

class Config : public FileReader {
    unordered_set<string> excluded_seqs;
    void readConfig();

   public:
    Config();
    Validator* getValidator();
};