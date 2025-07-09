#include <iostream>
#include "SettingsManager.hpp"

using namespace std;

int main() {
    SettingsManager sm;
    int choice;
    string key, value, filename = "settings.txt";

    while (true) {
        cout << "\n===== Infotainment Settings Menu =====\n";
        cout << "1. Show Settings\n";
        cout << "2. Change Setting\n";
        cout << "3. Save Settings to File\n";
        cout << "4. Load Settings from File\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                sm.showSettings();
                break;
            case 2:
                cout << "Enter setting name (Language/Brightness/Volume): ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> value;
                sm.changeSetting(key, value);
                break;
            case 3:
                sm.saveToFile(filename);
                break;
            case 4:
                sm.loadFromFile(filename);
                break;
            case 0:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
