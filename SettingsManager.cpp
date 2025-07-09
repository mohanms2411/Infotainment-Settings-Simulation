#include "SettingsManager.hpp"
#include <iostream>
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
    if (settings.find(key) != settings.end()) {
        settings[key] = value;
        cout << "Setting updated!\n";
    } else {
        cout << "Invalid setting key!\n";
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
