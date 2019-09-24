#include "string_utility.hpp"
#include <algorithm>

vector<string> StringUtility::split(const string &s, const string &delim) {
    vector<string> result;
    if (delim.empty()) {
        result.push_back(s);
        return result;
    }
    string::const_iterator substart = s.begin(), subend;
    while (true) {
        subend = search(substart, s.end(), delim.begin(), delim.end());
        string temp(substart, subend);
        if (!temp.empty()) {
            result.push_back(temp);
        }
        if (subend == s.end()) {
            break;
        }
        substart = subend + delim.size();
    }
    return result;
}

void StringUtility::tolower(string &s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
}

string StringUtility::trim(const string &w) {
    int start = 0, end = w.length();
    while (!isalnum(w[end - 1])) {
        --end;
    }
    while (!isalnum(w[start])) {
        ++start;
    }
    int ap_pos = w.find("'", start);
    if (ap_pos > -1) {
        end = min(end, ap_pos);
    }
    return w.substr(start, end - start);
}