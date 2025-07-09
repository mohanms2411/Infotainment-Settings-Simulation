#ifndef SETTINGS_MANAGER_HPP
#define SETTINGS_MANAGER_HPP

#include <string>
#include <map>

class SettingsManager {
private:
    std::map<std::string, std::string> settings;

public:
    SettingsManager();
    void showSettings() const;
    void changeSetting(const std::string& key, const std::string& value);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif
