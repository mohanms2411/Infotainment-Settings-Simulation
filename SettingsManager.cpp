#include "SettingsManager.hpp"
#include <iostream>
#include<algorithm>
#include <fstream>

using namespace std;

SettingsManager::SettingsManager() {
    // Default settings
    settings["Language"] = "English";
    settings["Brightness"] = "70";
    settings["Volume"] = "50";
}

void SettingsManager::showSettings() const {
    cout << "\nCurrent Settings:\n";
    for (const auto& pair : settings) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

void SettingsManager::changeSetting(const string& key, const string& value) {
    // Convert input key to match case of stored keys
    string formattedKey = key;
    formattedKey[0] = toupper(formattedKey[0]);
    for (size_t i = 1; i < formattedKey.length(); ++i) {
        formattedKey[i] = tolower(formattedKey[i]);
    }

    if (settings.find(formattedKey) != settings.end()) {
        settings[formattedKey] = value;
        cout << "Setting updated!\n";
    } else {
        cout << "Invalid setting key!\nAvailable keys: ";
        for (const auto& s : settings) {
            cout << s.first << " ";
        }
        cout << endl;
    }
}

void SettingsManager::saveToFile(const string& filename) const {
    ofstream out(filename);
    if (!out) {
        cout << "Failed to open file for writing.\n";
        return;
    }
    for (const auto& pair : settings) {
        out << pair.first << "=" << pair.second << endl;
    }
    out.close();
    cout << "Settings saved to " << filename << endl;
}

void SettingsManager::loadFromFile(const string& filename) {
    ifstream in(filename);
    if (!in) {
        cout << "Failed to open file for reading.\n";
        return;
    }

    string line;
    while (getline(in, line)) {
        size_t pos = line.find('=');
        if (pos != string::npos) {
            string key = line.substr(0, pos);
            string value = line.substr(pos + 1);
            settings[key] = value;
        }
    }
    in.close();
    cout << "Settings loaded from " << filename << endl;
}
