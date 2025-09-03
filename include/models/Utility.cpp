//
// Created by User on 8/15/2025.
//

#include "Utility.h"
#include <fstream>
#include <limits>

namespace Utility {
    string getInputString(const string &prompt) {
        string input;
        cout << prompt;
        getline(cin, input);
        return input;
    }

    int getValidChoice(int low, int up) {
        int choice;
        while (true) {
            cin >> choice;

            // Handle invalid input (non-numeric)
            if (cin.fail()) {
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Invalid input! Please enter a number (" << low << " - " << up << "): ";
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

            if (choice >= low && choice <= up) {
                return choice;
            }

            cout << "Invalid choice! Please enter " << low << " - " << up << ": ";
        }
    }

    string file(const string &id, const string &user) {
        string f;
        f += user;
        f += "_";
        f += id;
        f += ".dat";
        return f;
    }

    bool isExistInFile(const string &fileName, const string &userid) {
        ifstream file;
        file.open(fileName);
        if (file.is_open()) {
            string name, id, pass;
            while (getline(file, name) && getline(file, id) && getline(file, pass)) {
                if (userid == id) {
                    return true;
                }
            }
        } else if (!file.is_open()) return false; //file doesn't exist
        return false;
    }

    bool saveToFile(const string &fileName, const string &name, const string &id, const string &pass) {
        if (ofstream file(fileName, ios::app); file.is_open()) {
            file << name << "\n" << id << "\n" << pass << "\n";
            return true;
        }
        return false;
    }
}
