#include "config.hpp"

Config::Config() : FileReader() {
    readConfig();
}

void Config::readConfig() {
    vector<string> conf_file = this->readFile("config");
    bool excluded = false;
    for (auto& str: conf_file) {
        if (str == "EXCLUDE") {
            excluded = true;
        }
        if (excluded) {
            excluded_seqs.insert(str);
        }
    }
}

Validator* Config::getValidator() {
    return new Validator(this->excluded_seqs);
}