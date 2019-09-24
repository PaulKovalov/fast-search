#include "app.hpp"

App::App() {}
void App::updateIndexFile(const string& filename) {
    ofstream fout(".index/index.txt", ios_base::app);
    fout << filename << endl;
    indexed.insert(filename);
    fout.close();
}
void App::readIndexFile() {
    ifstream fin(".index/index.txt");
    if (!fin.is_open())
        return;
    string line;
    while (fin >> line) {
        indexed.insert(line);
    }
    fin.close();
}
void App::showIndexedFiles() {
    for (auto it = indexed.begin(); it != indexed.end(); ++it) {
        cout << *it << endl;
    }
}
void App::showAddMenu() {
    while (true) {
        LS();
        cout << "\nType q for quit\n";
        string input;
        stringstream ss;
        cin >> input;
        if (input == "q")
            return;
        size_t val;
        ss << input;
        ss >> val;
        while (val < 1 || val > entries.size()) {
            cout << "Invalid input, please try again\n";
            cin >> input;
            if (input == "q")
                return;
            ss << input;
            ss >> val;
        }
		if (indexed.find(entries[val - 1].name) != indexed.end()) {
			cout << "This file is already in the index\n";
		} else {
        	Document* doc = reader->getDocument(entries[val - 1].name);
        	trie->insert(doc, entries[val - 1].name);
        	updateIndexFile(entries[val - 1].name);
		}
    }
}
bool App::deleteIndex() {
    unordered_set<string>().swap(indexed);
    return fs::remove_all(".index");
}
void App::showMainMenu(int option = 0) {
    while (true) {
        stringstream ss;
        string input;
        size_t val;
        if (!option) {
            cout << "\n1. Search for a phrase\n";
            cout << "2. Add files to index\n";
            cout << "3. List indexed files\n";
            cout << "4. Delete index\n";
            cout << "5. Exit\n";
            cin >> input;
            cin.ignore();
            ss << input;
            ss >> val;
        } else {
            val = option;
        }
        while (val < 1 || val > 5) {
            cout << "Invalid input, please try again\n";
            cin >> input;
            if (input == "q")
                return;
            ss << input;
            ss >> val;
        }
        switch (val) {
            case 1: {
                cout << "Enter a phrase:\n";
                getline(cin, input);
                vector<string> exploded = su.split(input, " "), validated;
                for (auto& word : exploded) {
                    word = su.trim(word);
                    su.tolower(word);
                    if (searchQueryValidator->valid_word(word)) {
                        validated.push_back(word);
                    }
                }
                unordered_map<string, int> res = trie->search(exploded);
                for (auto& p : res) {
                    cout << p.first << ": " << fixed << setprecision(3) << double(p.second) / double(exploded.size()) * 100.0 << "% of the phrase found\n ";
                }
                break;
            }
            case 2: {
                showAddMenu();
                break;
            }
            case 3: {
                showIndexedFiles();
                break;
            }
            case 4: {
                if (checkIndexExists()) {
                    cout << "Are you sure you want to clear index?(yes/no)\n";
                    cout << "Currently it has the following files:\n";
                    showIndexedFiles();
                    string input;
                    cin >> input;
                    if (input != "yes") {
                        break;
                    }
                }
                if (deleteIndex()) {
                    cout << "Index deleted" << endl;
                } else {
                    cout << "Index doesn't exist, nothing to delete" << endl;
                }
                break;
            }
            case 5: {
                return;
            }
            default:
                cout << "Invalid input" << endl;
        }
        option = 0;
    }
}
bool App::checkIndexExists() {
    return indexed.size() > 0;
}
void App::LS() {
    size_t filetype_offset = 0;
    int left_offset;
    std::string path = ".";
    vector<Entry>().swap(entries);
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.path() == "./.index")
            continue;
        if (entry.path().string().size() > filetype_offset) {
            filetype_offset = entry.path().string().size();
        }
        if (fs::is_directory(entry.path())) {
            entries.push_back(Entry(1, entry.path()));
        } else {
            entries.push_back(Entry(0, entry.path()));
        }
    }
    left_offset = (int)ceil(log10(entries.size())) + 1;
    cout << "Files in your current directory (" << fs::current_path() << ")\n\n";
    for (size_t i = 0; i < entries.size(); ++i) {
        cout << left << setfill(' ') << setw(left_offset) << i + 1;
        cout << left << setfill('-') << setw(filetype_offset + 3) << entries[i].name << (entries[i].type == 1 ? " (directory)" : "") << (indexed.find(entries[i].name) != indexed.end() ? " (indexed)\n" : "\n");
    }
}
void App::start() {
    config = new Config();
    reader = new DocumentReader(config->getValidator());
    trie = new Trie();
	searchQueryValidator = config->getValidator();
    readIndexFile();
    if (checkIndexExists()) {
        showMainMenu();
    } else {
        string prompt = "You have no indexed documents yet. To start using fast-search, please choose file or directory with the files to index\n";
        cout << prompt;
        showMainMenu(2);
    }
}
App::~App() {
	delete config;
	delete reader;
	delete trie;
	delete searchQueryValidator;
}