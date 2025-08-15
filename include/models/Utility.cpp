//
// Created by User on 8/15/2025.
//

#include "Utility.h"
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

            if (choice >= 1 && choice <= 2) {
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
}
