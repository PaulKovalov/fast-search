#include "trie.hpp"

Trie::Trie() {}

void Trie::insert(Document* doc, string document) {
    fs::path starting(".index");
    if (!fs::exists(starting)) {
        fs::create_directory(".index");
    }
    for (auto it = doc->begin(); it != doc->end(); ++it) {
        fs::path curr_path(".index");
        for (auto& curr_char : *it) {
            curr_path /= to_string(curr_char);
            if (!fs::exists(curr_path) || !fs::is_directory(curr_path)) {
                fs::create_directory(curr_path);
            }
        }
        ofstream fout(curr_path.string() + "/docs.txt", ios_base::app);
        fout << document;
        fout.close();
    }
}
unordered_map<string, int> Trie::search(vector<string> query) {
    unordered_map<string, int> res;
    fs::path starting(".index");
    if (!fs::exists(starting)) {
        fs::create_directory(".index");
    }
    for (auto& q : query) {
        fs::path curr_path = starting;
        for (char& c : q) {
            curr_path /= to_string(c);
        }
        if (fs::exists(curr_path)) {
            // path exists, but doesn't mean that word is present
            // this may be just a prefix
            ifstream fin(curr_path.string() + "/docs.txt");
            if (fin.is_open()) {
                // yeahboy, word exists, for now just print all docs with it
                string file;
                while (fin >> file) {
                    ++res[file];
                }
            }
        }
    }
    return res;
}
unordered_map<string, int> Trie::info() {
    h = 0;
    tn = 0;
    tc = 0;
    h = traverse(fs::path(".index/"), 0);
    unordered_map<string, int> infomap;
    infomap["h"] = h;
    infomap["t"] = tn;
    infomap["c"] = tc;
    return infomap;
}
int Trie::traverse(fs::path curr_path, int curr_height) {
    int max_h = curr_height;
    for (const auto& entry : fs::directory_iterator(curr_path)) {     
        if (fs::is_directory(entry.path())) {
            ++tn;
            tc += curr_height + 1;
            max_h = max(traverse(entry.path(), curr_height + 1), max_h);
        }
    }
    return max_h;
}